*This project has been created as part of the 42 curriculum by afruhauf, gikarcev*

# cub3d

## Description

The Project aims to create a lightweight raycasting-based game engine.
It handles core rendering tasks and offers a modular foundation for expanding gameplay features.

### Features
- Raycasting-based 3D rendering from a 2D map
- Parsing a `.cub` configuration file
- Error handling for invalid maps/configurations
- Wall textures (N/S/E/W)
- Floor and ceiling color rendering with textures (F/C)
- Collision detection
- Camera rotation (left/right arrows or mouse)
- Player movement (W/A/S/D)
- Player jumping (SPACE), crouching (C), dodging (V), sprinting (hold SHIFT)
- dynamic mini-map
- audio implementation

## Instructions

### Requirements
- Linux
- `cc`
- Make

### Compilation
```
make
```

### execution
```
./cub3d <path to config file>
```
or simply
```
make test
```
## Resources
- Raycasting concepts: https://lodev.org/cgtutor/raycasting.html
- AI image gen for all the textures
- AI audio for the music
