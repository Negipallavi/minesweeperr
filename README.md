# Minesweeper Game

A simple command-line implementation of the classic Minesweeper game written in C. The goal is to uncover all cells on an 8x8 grid without hitting any mines.

## Description

In this Minesweeper game, players interact with an 8x8 grid containing 10 randomly placed mines. Players can reveal cells by entering their coordinates, and the game provides hints about the number of adjacent mines.

## Features

- 8x8 grid size
- 10 randomly placed mines
- Hint numbers indicating adjacent mines
- Recursive cell revealing for zeros

INSTRUCTIONS
 1. Enter the coordinates. r c
 2. If you reveal a number or zero, continue revealing cells.
 3. If you reveal a mine, the game is over.

Enter coordinates (row and column) to reveal (0-7): 2 3
Current Grid:
* * * * * * * *
* * * * * * * *
* * 1 * * * * *
* * * * * * * *
* * * * * * * *
* * * * * * * *
* * * * * * * *
* * * * * * * *
