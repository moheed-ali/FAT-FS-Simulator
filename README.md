# Project: FAT FS Simulator - Simple File System Simulation using FAT

The OSCA FS (Operating System and Computer Architecture Class Project File System) is a program that implements a simple simulation of a file system using a FAT (File Allocation Table) structure. The program allows users to interact with the simulated file system through a command-line menu.

## Features

- Create new files
- View the list of files
- Delete files
- Display the FAT table for a file
- Copy files between the simulated file system and the host computer

## Project Structure

The project consists of several C files that handle specific tasks related to the file system simulation:

- `oscafs.c`: The main program that provides the command-line menu for interacting with the file system.
- `fat.c`: Contains functions to initialize and manipulate the FAT table, which tracks the allocation of disk blocks.
- `data_block.c`: Handles the storage and retrieval of data in the simulated disk blocks.
- `file_operations.c`: Provides functions for reading and writing files and getting the size of a file.
- `init_file.c`: Includes functions for initializing the file and directory entries and reading/writing blocks and directory entries to the simulated file system.
- `oscafs.h`: Contains global constants and struct definitions used across the project.
- `Makefile`: Automates the compilation process.

## Usage

To use the OS CAFS program:

1. Clone the repository: `git clone https://github.com/moheed-ali/FAT-FS-Simulator.git`
2. Compile the program: `make`
3. Run the program: `./oscafs`

Follow the on-screen instructions to interact with the simulated file system.

## Makefile

The Makefile provided automates the compilation process. Here are some useful commands:

- `make`: Compiles the program.
- `make clean`: Removes the compiled object files and the executable.
- `make rebuild`: Performs a clean build by removing all compiled files and then recompiling the program.

## Contribution

Contributions to this project are welcome. If you find any issues or want to add new features, please open an issue or submit a pull request.

