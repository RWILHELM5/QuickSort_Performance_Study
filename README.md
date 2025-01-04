# QuickSort Performance Study

**Author**: Ryan Wilhelm

## Purpose
This project implements the QuickSort algorithm with a median-of-three pivot selection strategy and analyzes its performance for input sizes of 10, 100, and 1000 unsorted floating-point numbers. Execution times are recorded, averaged, and visualized in a plot.

## Files Included
- `Wilhelm_Ryan_QuickSort.cpp`: Implementation of QuickSort (Task 1).
- `Wilhelm_Ryan_executionTime.txt`: Recorded execution times for all input files.
- `Wilhelm_Ryan_averageExecutionTime.txt`: Average execution times for each input size.
- `Wilhelm_Ryan_plotAverageExecutionTime.jpg`: Performance plot (input size vs. execution time).
- `Wilhelm_Ryan_InputFileGenerator.cpp`: Program to generate random input files.
- `Makefile`: For compiling the C++ programs.
- `Wilhelm_Ryan_input_10.txt`: Input file for size 10.
- `Wilhelm_Ryan_output_10.txt`: Output file for size 10.

## How to Compile
To compile the programs, use the included Makefile:
```bash
make
```
This generates the `Wilhelm_Ryan_QuickSort` executable.

To compile the input file generator:
```bash
g++ -o InputFileGenerator Wilhelm_Ryan_InputFileGenerator.cpp
```

## How to Run QuickSort
Run QuickSort on any input file with:
```bash
./Wilhelm_Ryan_QuickSort input.txt output.txt
```

### Example:
```bash
./Wilhelm_Ryan_QuickSort Wilhelm_Ryan_input_10.txt Wilhelm_Ryan_output_10.txt
```

## How to Generate Input Files
To generate input files for testing:
```bash
./InputFileGenerator
```
This creates 75 input files in the `Input Files/` directory (25 each for sizes 10, 100, and 1000).

## Notes
- Ensure the `Input Files/` and `Output Files/` directories exist before running scripts.
- Use a Linux system for compatibility.
- Required Python libraries (`numpy`, `matplotlib`) can be installed using pip:
```bash
pip3 install numpy matplotlib
```

