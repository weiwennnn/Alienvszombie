# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo]((https://www.youtube.com/watch?v=4cRI8nBFi1E)).

## Minimum Requirements

### Completed

List all the features completed.

1. Two dimensional game board with correct columns and row numbers and contains characters and    objects .
2. Customizetions settings including game board dimensions and number of zombies.
3. "Save game into a file" and "load game from a file" by name functions.
4. Game characters Alien (player)which always at middle of the board and Zombie which palced randomize.
5. Game object placed randomize including: Arrow("^","v","<",">"), Health("h"), pod("p"), rock("r"), Empty(" "),and Trail(".").
6. Game controls by typing commands including: "up", "down", "left", "right", "arrow", "help", "save", "load" and "quit".
7. Game detail 1: Alien will only target to attack closest zombie when found a pod.
8. Game detail 2: Alien's life will no more than 100 and will remain 100 even found a health pack.
9. Game detail 3: Alien's attack will clear to 0 at next turn if player not decided to attack zombie.
10. Quit functions while still in play.

## Additional Features

-

## Contributions

### HEE_KAI_WEN

1. Game Board.
2. Multiple Zombies.
3. Zombie movement and attack behaviour. 
4. Alien target to attack closest zombie when found a pod.

### LEE_WEI_WEN

1. Random items appear on the map.
2. Aliean appear in the midddle of the map.
3. SAVE function.
4. Alien's health and attack behaviour.

### TAI_JIN_PEI

1. Game Controls.
2. Game Objects.
3. LOAD function.
4. QUIT function.

## Problems Encountered & Solutions

Problem encountered:
Gameboard including position of characters and objects saved well in the file but cannot load well.

Solutions:
save file type as ".txt" so more easier to read.
save numbers of rows and columns too to rebuild the gameboard.

Problem encountered:
Zombie life and attack cannot function well.

Plan for the solutions:
Give up out to let zombie's life and attack as global variables but list down 9 zombies' life and attack variables one by one. 

