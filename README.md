# cub3d

cub3d is a 3D game engine project developed as part of the 42 Madrid curriculum. It is inspired by the classic game Wolfenstein 3D and uses raycasting to render a 3D environment from a 2D map.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Contributing](#contributing)
- [License](#license)

## Introduction
cub3d is a simple 3D game engine that demonstrates the basics of raycasting. It is written in C and uses the MiniLibX library for graphics rendering. This project only runs on Linux and Mac.

## Features
- Raycasting for 3D rendering
- Basic player movement and collision detection
- Textured walls and sprites
- Simple map editor

## Installation
To install cub3d, follow these steps:

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/cub3d.git
    ```
2. Navigate to the project directory:
    ```sh
    cd cub3d
    ```
3. Compile the project:
    ```sh
    make
    ```

## Usage
To run the game, execute the following command:
```sh
./cub3d path/to/map.cub
```

## Controls
- `W`: Move forward
- `S`: Move backward
- `A`: Strafe left
- `D`: Strafe right
- `Left Arrow`: Turn left
- `Right Arrow`: Turn right
- `ESC`: Exit the game

## Contributing
Contributions are welcome! Please fork the repository and submit a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
