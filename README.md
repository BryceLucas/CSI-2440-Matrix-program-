# Matrix Program

This program performs matrix operations based on user input or command-line arguments.

## Features

- Read matrices from files for multiplication.
- Generate random matrices given a size input.
- Multiply two matrices and output the result to a file.
- Check if the input files are correctly formatted as matrices.
- Print matrices to the console for verification.

## Usage

Compile the program using a C compiler such as `gcc`:

```bash
gcc -o matrixbryce matrixbryce.c
```

Run the program by passing either two filenames or a size for random matrix generation:

```bash
./matrixbryce file1.txt file2.txt
```

Or:

```bash
./matrixbryce 5
```

## Requirements

- C compiler (GCC, Clang, or any standard C compiler)
- Standard C library
- Command-line environment or IDE for running the program
