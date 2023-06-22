# Picopad TFT Display Emulator

This project provides an emulator for the TFT display of Picopad handheld devices. It's designed to assist in the
prototyping and development of applications for Picopad handhelds. With this tool, you can easily prepare and test your
display code using the API of the Picopad SDK.

Code of this emulator is based on the original Picopad SDK source code.

## Features

- Display emulation: The emulator accurately represents the display characteristics of Picopad handhelds, allowing you
  to see how your application will look on the actual device.
- Keyboard input: Simulate changes in device state with keypress events (e.g., toggle sensor connection with the 'C'
  key).
- Easy prototyping: Modify the provided main file to draw different UI components on the display.
- Picopad SDK API: The emulator is built to interact with the Picopad SDK API, letting you test how your code interacts
  with the API.

## Getting Started

### Prerequisites

This emulator is based on SFML (Simple and Fast Multimedia Library) and the Picopad SDK. Ensure you have SFML on your
system.

Certainly. Here's how you can install SFML on macOS and use it in your project with CMake.

### Installing SFML on macOS

1. Install Homebrew if you don't have it installed already. You can install it by pasting the following command in the
   terminal:

    ```bash
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    ```

2. Once Homebrew is installed, you can install SFML by running the following command:

    ```bash
    brew install sfml
    ```

This will download and install the latest version of SFML on your system.

### Using SFML in your project with CMake

1. Create a `CMakeLists.txt` file in your project directory if you don't have one already.

2. Add the following lines to your `CMakeLists.txt` file:

    ```cmake
    cmake_minimum_required(VERSION 3.25)
    project(<your_project_name> C CXX)
    
    set(CMAKE_CXX_STANDARD 17)
    
    add_executable(tft-emulator main.cpp)
    
    find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
    
    target_link_libraries(tft-emulator sfml-graphics sfml-audio)
    ```

Replace `your_project_name` with the name of your project.

3. In the terminal, navigate to your project directory and build your project with CMake:

    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

Your project should now be able to use SFML.

## Running the Emulator

1. Clone this repository to your local machine.
2. Navigate to the project's directory.
3. Compile the source code with your CMAKE. 

## Usage

Modify the `main.cpp` file to create the UI of your application using the Picopad SDK API.

## Links

- Picopad from Pajenicko e-shop
- Picopad SDK (https://github.com/Pajenicko/Picopad)