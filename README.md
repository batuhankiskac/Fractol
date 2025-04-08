# Fractol

Fractol is a graphical application written in C for visualizing and exploring different types of fractals. This project leverages the power of mathematical functions and algorithms to generate intricate and beautiful fractal patterns. It serves as a great introduction to graphical programming and the mathematical concepts behind fractals.

## Features

- **Multiple Fractal Types**: Supports various fractal types such as Mandelbrot, Julia, and more.
- **Zoom and Pan**: Interactive features to zoom in and out and pan across the fractal images.
- **Color Schemes**: Various color schemes to enhance the visual appeal of the fractals.
- **Real-Time Rendering**: Efficient rendering for real-time interaction and exploration.

## Requirements

- **C Compiler**: Ensure you have a C compiler like `gcc` installed.
- **Make**: The project uses a Makefile for building.
- **Libraries**: Requires the MLX library for graphical rendering.

## Installation

Clone the repository and navigate to the project directory:
```sh
git clone https://github.com/batuhankiskac/Fractol.git
cd Fractol
```

Build the project using Make:
```sh
make
```

## Usage

Run the application with the following command:
```sh
./fractol [fractal_type]
```
Where `[fractal_type]` can be one of the supported fractal names, e.g., `Mandelbrot`, `Julia`.

Example:
```sh
./fractol Mandelbrot
```

Feel free to modify this description to better fit your project's specifics!
