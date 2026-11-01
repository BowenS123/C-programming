# Minesweeper

A small terminal Minesweeper game written in portable C11. It is the final
project in this repository's C programming exercises.

## Build

```sh
cmake -S . -B build
cmake --build build
```

Run the generated `minesweeper` executable. The program does not require
configuration files, environment variables, external libraries, or network
access.

## Controls

- `O` opens a cell.
- `F` flags or unflags a covered cell.
- `Q` quits the current game.
- Coordinates use a column letter and zero-based row number, for example
  `A 1`.

The available board sizes are 5x5, 8x8, and 15x15. Enter `0` for the mine
count to use the default 25% density.
