# C programming

This repository contains the weekly C programming exercises and the
Minesweeper final project. The exercise folders are kept in their original
learning order; the final project has its own maintainable application
structure.

## Repository structure

```text
week0/ ... week7/   Weekly exercises and experiments
Minesweeper/
  include/          Public game declarations
  src/              Application entry point and game implementation
  CMakeLists.txt    Build configuration
```

## Build and run Minesweeper

Requirements:

- C compiler with C11 support
- CMake 3.16 or newer

From the repository root:

```sh
cmake -S Minesweeper -B Minesweeper/build
cmake --build Minesweeper/build
Minesweeper/build/minesweeper
```

On Windows, run `Minesweeper\build\Debug\minesweeper.exe` for a Visual Studio
generator, or the executable produced by the selected CMake generator.

The game accepts board sizes from 5x5 to 15x15, configurable mine counts,
coordinates such as `A 1`, and the actions `O` (open), `F` (flag/unflag), and
`Q` (quit).

## Development notes

The Minesweeper build enables strict compiler warnings. Input is read line by
line and validated before it is used, and all board-neighbour operations check
their bounds.
