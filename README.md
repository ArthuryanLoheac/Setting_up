# SETTING UP - Largest Square Finder

"SETTING UP" is a project under the "ELEMENTARY PROGRAMMING IN C" module, aimed at teaching students about dynamic programming through a practical and engaging challenge. The essence of the project is to identify the largest possible square without obstacles on a given board, a metaphor for setting up an efficient workspace in the cluttered laboratory that new Epitech students encounter.

## Project Overview

The project challenges students to write a C program that analyzes a board layout to find the largest square that can be formed without including any obstacles. The board layout is provided via a file or generated dynamically based on given parameters.

### Features

- **Dynamic Board Analysis:** Processes a board layout to determine the largest free square area.
- **File Input:** Accepts a file containing the board's layout, adhering to specific format rules.
- **Generated Board Input:** Capable of generating a board based on dimensions and a pattern.
- **Custom Output:** Prints the board with the largest square marked, prioritizing the highest and leftmost solutions in case of multiple options.

## Getting Started

### Prerequisites

- GCC compiler or any standard C compiler
- Basic understanding of command-line operations

### Compilation

Compile the program using the included Makefile:

```bash
make
```

This will generate the executable setting_up, ready for use.

## Usage
To analyze a board from a file:

```bash
./setting_up path_to_file
```
To generate a board and analyze it:

```bash
./setting_up dimension "pattern"
```
## File Format
The input file must follow these constraints:

The first line specifies the number of lines on the board.
Board content uses . to denote empty spaces and o to mark obstacles.
All lines, except the first, must be of equal length and end with \n.
## Examples
Analyzing a provided board:

```bash
./setting_up example_file
```
Generating and analyzing a 6x6 board with a "..o.." pattern:

```bash
./setting_up 6 "..o.."
```
