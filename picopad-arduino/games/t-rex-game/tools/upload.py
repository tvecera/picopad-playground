"""
Binary File Sender over Serial

This script allows for sending binary files over a serial to the Picopad custom loader.
The script first sends a starting sequence to the device and awaits an acknowledgment.
Following this, the CRC, file size, and then the file content are sent, each expecting
their respective acknowledgments.

MIT License

Copyright (c) 2023 Tomas Vecera tomas@vecera.dev

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
"""

import argparse
import binascii
import os
import time
import serial.tools.list_ports
from colorama import Fore, init

init(autoreset=True)  # Automatically reset colors after each print


def bytes_to_human_readable(byte_count):
    """Convert bytes to human-readable format."""
    suffixes = ['B', 'KB', 'MB', 'GB', 'TB', 'PB']
    i = 0
    while byte_count >= 1024 and i < len(suffixes) - 1:
        byte_count /= 1024
        i += 1
    return f"{byte_count:.2f} {suffixes[i]}"


def read_serial_and_check(console, expected_hex=None):
    uart_response = console.readline().decode('utf-8').strip()
    if not uart_response:  # If timeout occurs, uart_response will be empty
        print(f"{Fore.RED}Timeout while waiting for response from device.")
        console.close()
        return exit(1)
    if "ERROR" in uart_response:
        print(f"{Fore.RED}Error from device: {uart_response}")
        console.close()
        return None
    elif expected_hex and uart_response != f"ACK {expected_hex}":
        print(f"{Fore.YELLOW}Unexpected ACK from device: {uart_response}. Expected: ACK {expected_hex}")
        console.close()
        return None
    return uart_response


def send_with_progress(console, content, total_size):
    chunk_size = 512
    bar_length = 50
    for i in range(0, len(content), chunk_size):
        chunk = content[i:i + chunk_size]
        console.write(chunk)
        progress = (i + len(chunk)) / total_size
        arrow = '=' * int(round(progress * bar_length) - 1) + '>'
        spaces = ' ' * (bar_length - len(arrow))
        print(f"\r[{arrow + spaces}] {Fore.RESET}{i + len(chunk)}/{total_size} bytes", end='')
        time.sleep(0.1)
    print()  # New line after progress completion


parser = argparse.ArgumentParser(description="Send a binary file over serial to the Picopad loader")
parser.add_argument("-p", "--port", help="Serial port (default: try to find Arduino Pico port", nargs="?")
parser.add_argument("-b", "--baudrate", help="Baud rate for the serial communication. Default is 115200.",
                    default=115200, type=int, nargs="?")
parser.add_argument("file_path", help="Path to the binary file")
args = parser.parse_args()

try:
    serial_port = args.port
    if serial_port is None:
        print(f"{Fore.YELLOW}Trying to identify Arduino Pico port...")
        ports = list(serial.tools.list_ports.comports())
        for p in ports:
            if "Pico" in p.description:
                print(f"{Fore.GREEN}Arduino Pico port found: {p}")
                print(f"{Fore.CYAN}Port details:")
                print(f"   Name: {p.device}")
                print(f"   Description: {p.description}")
                print(f"   HWID: {p.hwid}")
                serial_port = p.device
                break

        if serial_port is None:
            print(f"{Fore.RED}Arduino Pico port not found. Please specify the port using the '-p' argument.")
            exit(1)

    # Set up the serial connection
    ser = serial.Serial(serial_port, args.baudrate, timeout=60)
    time.sleep(2)

    start_time = time.time()
    print(f"{Fore.BLUE}1. Sending starting sequence 73939173")

    numbers = [7, 3, 9, 3, 9, 1, 7, 3]
    data = bytearray()
    for num in numbers:
        data.extend(num.to_bytes(1, 'little'))

    MAX_RETRIES = 5
    for _ in range(MAX_RETRIES):
        ser.write(data)
        response = read_serial_and_check(ser)
        if response == "ACK":
            print(f"{Fore.GREEN}   Starting sequence received")
            break
        else:
            print(f"{Fore.YELLOW}   Retrying starting sequence...")
    else:
        print(f"{Fore.RED}   Failed to get ACK after maximum retries.")
        ser.close()
        exit(1)

    # Load the binary file
    with open(args.file_path, 'rb') as f:
        file_content = f.read()

    # Get file size and CRC
    file_size = os.path.getsize(args.file_path)
    file_crc = binascii.crc32(file_content)

    # Send CRC and check ACK
    print(f"{Fore.BLUE}2. Sending file CRC: ", hex(file_crc))
    ser.write(file_crc.to_bytes(4, 'little'))
    response = read_serial_and_check(ser, "CRC32 " + hex(file_crc))
    if response is not None:
        print(f"{Fore.GREEN}   File CRC32 ACK received: ", response)
    else:
        exit(1)

    # Send the file size and check ACK
    print(f"{Fore.BLUE}3. Sending file size: ", hex(file_size))
    ser.write(file_size.to_bytes(4, 'little'))
    response = read_serial_and_check(ser, "FILESIZE " + hex(file_size))
    if response is not None:
        print(f"{Fore.GREEN}   File file size ACK received", response)
    else:
        exit(1)

    # Send file content with progress bar
    print(f"{Fore.BLUE}4. Sending file binary content...\n")
    send_with_progress(ser, file_content, file_size)
    response = read_serial_and_check(ser, "FLASH " + hex(file_size))
    if response is not None:
        print(f"\n{Fore.GREEN}File flash ACK received", response)
    else:
        exit(1)

    # Close the serial connection
    ser.close()

    # Display upload summary
    human_readable_size = bytes_to_human_readable(file_size)
    elapsed_time = time.time() - start_time
    print(f"\nUpload Summary:")
    print(f"{Fore.CYAN}File size: {human_readable_size}")
    print(f"{Fore.CYAN}Upload duration: {elapsed_time:.2f} seconds")

except serial.SerialException:
    print(f"\n{Fore.RED}A serial exception occurred!")
except OSError as e:
    if e.errno == 6:
        print(f"\n{Fore.RED}Device not configured error!")
    else:
        print(f"\n{Fore.RED}An OSError occurred: {e}")
except Exception as e:
    # This will catch any other exceptions
    print(f"\n{Fore.RED}An unexpected error occurred: {e}")
