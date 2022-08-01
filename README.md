<h1 align="center">
    CUB3D
</h1>

___

## 🚀 **Description**

*My first RayCaster with miniLibX 💡*

<p align="center">
    <img src="https://user-images.githubusercontent.com/70847388/171485317-649fef15-0630-4f05-b1d8-8cba9cb7c4cc.gif">
</p>

### *Introduction*

The aim of the ``cub3d`` proyect is to create a 3D game using the raycasting technique which is a rendering method implemented in the world-famous ``Wolfenstein 3D`` game.

### *Map*

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

### *Raycasting*

Raycasting is a rendering technique to create a 3D perspective in a 2D map. 
The logic behind RayCasting is to throw rays in the direction of the player view. Basically, we need to check the distance between the player and the nearest wall (i.e. the point where the ray hits a wall) to caculate the height of the vertical lines we draw. Here is a simple depiction of it:

<p align="center">
     <img width="200" alt="Raycast Example 1" src="https://user-images.githubusercontent.com/71781441/154158563-5b4f7641-4f3d-4cca-97f1-4cc79aac16dd.png">
    <img width="233" alt="Raycast Example 2" src="https://user-images.githubusercontent.com/71781441/154159164-667da898-a8d5-4991-a8d0-a6008f111054.png">
</p>

### *Controls*

Here is a summary of the various controls in the game:
- The ``WASD`` keys move the player up, down, left and right relative to the player's viewing angle
- The ``left`` and ``right`` arrow keys rotate the viewing angle of the player
- Press the ``ESC`` key or the ``X`` button on the window to exit the game

###### *For detailed information, refer to the [**subject of this project**](https://github.com/cherdantsevilya/cub3D/blob/master/content/en.subject%20(1).pdf).*

___

## 📌 **Useful links**

+ [Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)
+ [Cub3D БЕЗ СПОЙЛЕРОВ](https://www.youtube.com/watch?v=vK6_Hz6O8iA)
+ [42 Docs](https://harm-smits.github.io/42docs/libs/minilibx)
+ [For Coderz - RAYCASTING](https://zxpress.ru/article.php?id=8482)
+ [How to handle mouse buttons and key presses?](https://github.com/VBrazhnik/FdF/wiki/How-to-handle-mouse-buttons-and-key-presses%3F)
+ [Ray-Casting Tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
+ [простой 3D-шутер с нуля](https://habr.com/ru/post/439698/)
