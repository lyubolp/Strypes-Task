# Strypes-Task

## Task:

​	Write a program that finds the ***longest adjacent sequence*** of colors in a matrix(2D grid). Colors are represented by ‘R’, ‘G’, ‘B’ characters (respectively Red, Green and Blue).

## Solution:

​	The solution is in two parts - a C shared-object library, which contains the main algorithm, and a Python script, which handles input and output. We can view the matrix as a graph and a node `i` with letter `L(i)`, where L = {'R', 'G', 'B'}, is connected with another node `j` only when `L(i) == L(j)` and `i` and `j` are adjacent (diagonals are not considered adjacent). For each unvisited node, we can start a breadth-first search (BFS), using a queue. The queue itself is implemented by hand too. 

## Contents:

​	This repository's contents are:

- The C code for the algorithms
- CMakeLists.txt - used for creating a `makefile` for building the library
- Prebuilt library with the solution
- The Python script, which parses the input, loads the library and runs the algorithm
- Test files

## How-To-Run:

1. Make sure you have `python3` , `cmake` and `gcc` installed
2. (Optional) Compile the library
   1. In the `C` directory, run `cmake .`
   2. After that, run `make` to build the library
3. In the `Python` directory, run `main.py <path_to_test_file1> <path_to_test_file2>`, where `<path_to_test_fileX>` is the path to a file containing the graph. Example tests are located in the `tests` directory.

Example run:

`❯ ./main.py ../tests/test_2`

Output: `7`



