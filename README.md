# N-Queens solver

## Goal

The goal of this program is to solve the N-queens problem. 
It is a modified clone of [this repository](https://github.com/Sanegv/8-queens-solver), which solves for only 8-Queens (as opposed to any amount), but works using bitboards and bitwise operations.

The goal here was to use two concepts:
- backtracking;
- Unit Testing (in C)

### Backtracking

A backtracking algorithm is a type of algorithm used to find a solution that satisfies some constraints.
To do so, we iterate over a tree of possibilities, and as soon as one possibility proves to violate a constraint, we eliminate it.

This kind of algorithm is used to solve problems like exploring a labyrinth,finding moves in chess, solving sudoku grids, etc.

### Unit Testing

While not a brand-new concept, I wanted to force myself to do this project properly, and TDD (Test Driven Development) allowed me to gain a lot of time when trying an implementation.
C unit testing is not as advanced as Java's JUnit or Go's Testing, but it is more than enough to create a working TDD environment.

## N-Queens problem

In the N-Queens problem, we must place N queens on an N*N grid, in such a way that no queen is threatened by another one.

That means that no two queens can occupy the same file, row, or diagonal.
We can see how similar this problem is to solving a sudoku grid.

The implementation for N-Queens is similar to the one I used for 8-Queens.
In fact, I just copyied and pasted the solve() function to a new project, but without limiting myself to using bitboards, and using 2D arrays to of size N*N.

## Files

This repository is divided in two main directories.

### [src](./src)

This folder contains all the actual code used for the [board](./src/board.h),the [solver](./src/solver.h), and a [main](./src/main.c) function that finds prints a solution in the terminal.

### [tests](./tests)

This folder holds all the unit tests for all the functions of src 
(except the one that prints the board).

- [unitTests](./tests/unitTests.c) has its own main, and calls all the tests of the other files.
- [board_test](./tests/board_test.h) and [solver_test](./tests/solver_test.h) test all the functions defined in [board](./src/board.h) and [solver](./src/solver.h), respectively.