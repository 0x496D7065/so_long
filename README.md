*This project has been created as part of the 42 curriculum*

# so_long

## Description

so_long is a small 2D game written in C with the MiniLibX graphics library. The player moves around a map, collects every collectible, and then reaches the exit, using as few moves as possible. The map is loaded from a `.ber` file, which is validated before the game starts.

## Gameplay

| Key | Action |
|---|---|
| `W` / `↑` | Move up |
| `A` / `←` | Move left |
| `S` / `↓` | Move down |
| `D` / `→` | Move right |
| `ESC` | Quit the game |

- Collect all collectibles, then go to the exit to win.
- The move count is printed in the terminal after each move.
- Closing the window also quits the game cleanly.

## Map format

Maps are `.ber` files made of these characters:

| Character | Meaning |
|---|---|
| `1` | Wall |
| `0` | Empty space |
| `P` | Player start position |
| `E` | Exit |
| `C` | Collectible |

A map is valid only if all these hold:

- It is rectangular.
- It is surrounded by walls.
- It contains exactly one `P`, exactly one `E`, and at least one `C`.
- The exit and every collectible can be reached from the player's start position.

If the map is invalid, the program prints an error and exits.

## Instructions

### Build

```bash
make          # builds the so_long executable
make clean    # removes object files
make fclean   # removes object files and the executable
make re       # rebuilds everything
```

### Run

```bash
./so_long map.ber
```

Two sample maps are included: `map.ber` and `map2.ber`.

## Project structure

```
.
├── Makefile
├── map.ber / map2.ber   # sample maps
├── assets/              # sprites and textures
├── includes/            # header files
└── srcs/                # source files
```

## Resources

- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- Flood fill algorithm, used to check that a path exists
