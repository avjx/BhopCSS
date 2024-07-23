# Counter-Strike: Source Bhop DLL

This project is a C++ DLL for Counter-Strike: Source that automates bunny hopping (bhop).

## Features

- **Automatic Bunny Hop**: Automatically performs bunny hops when the spacebar is held down.
- **Debug Console**: Allocates a console for debugging, displaying useful information like module addresses and offsets.

## How It Works

The DLL intercepts keyboard input and simulates jump commands when the player is on the ground and the spacebar is pressed.

## Requirements

- MinGW (Minimalist GNU for Windows) or a compatible compiler
- Counter-Strike: Source

## Compilation

1. Install MinGW from [here](http://www.mingw.org/).
2. Add MinGW's `bin` directory to your system's PATH (e.g., `C:\MinGW\bin`).
3. Clone this repository or download the files.
4. Open a terminal or command prompt in the directory containing `bhop.cpp`.
5. Compile the DLL with the following command:

```sh
gcc -shared -o bhop.dll bhop.cpp -lstdc++
