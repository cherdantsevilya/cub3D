<h1 align="center">
    CUB3D
</h1>

___

## :memo: **About**

_This project is inspired by the world-famous eponymous 90's game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you'll have to find your way._

### *Keywords*  
> + Applicative

### *Skills*
> + Imperative programming
> + Graphics
> + Rigor
> + Algorithms & AI

For detailed information, refer to the [**subject of this project**](https://github.com/cherdantsevilya/cub3D/blob/master/content/en.subject%20(1).pdf).

___

## 🚀 **Description**

*My first RayCaster with miniLibX 💡*

<p align="center">
    <img src="https://github.com/cherdantsevilya/cub3D/blob/master/content/cub3d.gif" width="640" height="480">
</p>

### Introduction

The aim of the ``cub3d`` proyect is to create a 3D game using the raycasting technique which is a rendering method implemented in the world-famous ``Wolfenstein 3D`` game.

### Map

The ``cub3D`` executable receives as a single argument the map file we read, which must be of ``.cub`` filetype.

The file must follow these rules:
- There must be header lines before the actual map containing the following:
    - At least a line containing ``NO``, ``SO``, ``EA`` and ``WE`` followed by a valid path to an xpm image
    - A line starting with ``F`` (**f**loor) or ``C`` (**c**eiling) followed by a color in RGB separated by commas
- Only `` `` *(empty)*, ``1`` *(wall)*, ``0`` *(floor)*, and either ``N``, ``S``, ``E`` or ``W`` *(Player starting position looking at **N**orth, **S**outh, **E**ast or **W**est)*, will be accepted characters in our map (except if you add other characters as bonus)
- The map may not be rectangular, but it must be surrounded by walls
- Spaces are allowed but the player cannot walk on them, thus every space must also be closed/surrounded by walls
- There must be a single player on the map

Here's an example of a valid map (not rectangular but still valid):

```
NO ./textures/WALL2.xpm
SO ./textures/WALL21.xpm
WE ./textures/WALL8.xpm
EA ./textures/WALL22.xpm

F 112,112,112
C 53,53,53

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111110111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000000001
10000W00000000001101010010001
1100000111010101111101111000111
11110111 1110101 100000010001
11111111 1111111 111111111111
```

___
