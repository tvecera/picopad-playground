# Arduino Picopad Serial Uploader

This script allows you to send a binary file over a serial connection to the Picopad Custom Loader. It offers options
such as specifying the serial port and baud rate, with added functionalities like auto-detection of the port and
progress bar during the upload.

## Requirements:

- Python 3.x
- Libraries:
    - `pyserial`
    - `binascii`
    - `zlib`
    - `argparse`
    - `colorama`

You can install the required Python libraries using the following command:

```bash
pip install pyserial colorama
```

## Usage:

```bash
python PySerialUpload.py [-p PORT] [-b BAUDRATE] [file_path]
```

- `-p` or `--port`: The serial port. If not provided, the script will attempt to identify the Arduino Pico port.
- `-b` or `--baudrate`: The baud rate for the serial communication. Default is 115200.
- `file_path`: Path to the binary file to be uploaded.

### Example:

```bash
python PySerialUpload.py --port /dev/cu.usbmodem14202 --baudrate 115200 BINARY.PP2
```

## Features:

- **Port Identification**: If the port is not provided, the script will try to identify the Arduino Pico port and use it
  for communication.
- **Progress Bar**: During the upload, a progress bar shows the upload progress in real-time.
- **Error Handling**: The script handles various errors like timeouts, incorrect ACKs, and serial exceptions to provide
  feedback to the user.
