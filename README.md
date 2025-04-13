# C++ Connect Four Game

A command-line implementation of the classic two-player board game Connect Four.

## Description

This C++ application simulates the Connect Four game where two players take turns dropping colored discs into a vertical grid. The objective is to be the first to form a horizontal, vertical, or diagonal line of four discs of your color.

## Features

- Classic Connect Four gameplay
- Two-player mode (Black vs Red)
- 6x7 standard game board
- Command-line interface with visual board representation
- Input validation to prevent illegal moves
- Win detection in all directions (horizontal, vertical, and diagonal)
- Draw detection when the board is full

## Requirements

- C++ compiler (C++11 or higher recommended)
- Standard C++ libraries

## Installation

1. Clone this repository or download the source code
2. Navigate to the project directory
3. Compile the code using your preferred C++ compiler:

```bash
g++ -o connect_four ConnectFour.cpp Game.cpp Board.cpp Checker.cpp -std=c++11
```

## Usage

Run the compiled executable:

```bash
./connect_four
```

### Game Controls

- Enter a column number (1-7) to drop a disc into that column
- Enter 'q' at any time to quit the game

### Gameplay

1. Black player starts the game
2. Players alternate turns, dropping their colored discs into columns
3. The game announces the winner when a player forms a line of four discs
4. If the board fills up without a winner, the game ends in a draw

## File Structure

- **main.cpp**: Program entry point
- **Game.h/cpp**: Handles game logic, player turns, and win conditions
- **Board.h/cpp**: Manages the game board and piece placement
- **Checker.h/cpp**: Represents individual game pieces

## Class Structure

### Game Class

- Manages the overall game flow
- Handles user input validation
- Checks for win conditions and draw scenarios
- Alternates between player turns

### Board Class

- Represents the 6x7 game grid
- Manages piece placement and board state
- Renders the board to the console
- Provides utility functions for checking available spaces

### CheckerPiece Class

- Represents an individual game piece (Black, Red, or empty)
- Handles piece rendering and state

## Win Condition Algorithm

The game checks for wins in four directions after each move:
1. Horizontal (→)
2. Vertical (↓)
3. Diagonal descending (↘)
4. Diagonal ascending (↗)

The algorithm counts consecutive pieces of the same color in both directions along each line to determine if four or more are connected.

## Future Enhancements

Potential features for future versions:
- AI opponent with difficulty levels
- Graphical user interface
- Game state saving/loading
- Player statistics tracking
- Network multiplayer support
- Customizable board dimensions


## Acknowledgments

This project was created as a programming exercise to demonstrate object-oriented programming concepts in C++.
