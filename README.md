# 42 So Long

Welcome to 42 So Long! This project challenges you to create a simple 2D game using the `mlx` graphics library. The goal is to implement a game that includes basic functionality, such as player movement, collectibles, and exits.

## Table of Contents

1. [Introduction](#introduction)
2. [Getting Started](#getting-started)
3. [Usage](#usage)
4. [Build Commands](#build-commands)
5. [Game Features](#game-features)
6. [Contributing](#contributing)
7. [License](#license)

## Introduction

The `so_long` project requires you to create a simple 2D game with a player, collectibles, and an exit. The game should have basic functionality, and you will use the `mlx` graphics library for rendering.

## Getting Started

To get started with `so_long`, follow these steps to build the dependency:

1. Clone this repository to your local machine:

```bash
git clone https://github.com/your-username/T-001v2r3.git
```
2.    Navigate to the minilibx folder and build the MinilibX library:

```bash
cd so_long/minilibx
make
```
3.    Once the MinilibX library is built, go back to the project directory:

```bash
cd ..
```
## Usage

To run the game, execute the following command:

```bash
./so_long [map_file]
```
For example:

```bash
./so_long assets/maps/mapshort.ber
```
The game will open, and you can navigate the player through the map.
Build Commands

Use the following commands to build and clean your project:

```bash
make         # to build with bonus features
make re      # to re-build the project
make clean   # to clean up object files
make fclean  # to clean up everything
```
## Game Features

The game features include:

    Player movements count
    Collectibles 
    Enemies

Describe any additional features you have implemented in your game.
## Contributing

Contributions to so_long are welcome! If you have ideas for improvements, bug fixes, or additional features, feel free to open an issue or submit a pull request.

Before submitting a pull request, please make sure your code follows the 42 Norm coding style.
## License

This project is licensed under the terms of the MIT license.
