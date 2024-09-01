# Conway in C

A while back, I followed a tutorial to put together Conway's game of life in C++ using raylib. This time I thought I would do it in C:

To compile:  
```
gcc -o gameoflife gameoflife.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

The rules of Conway's Game of Life:

Any live cell with 2 or 3 live neighbors survives.
Any dead cell with exactly 3 live neighbors becomes a live cell.
All other live cells die in the next generation. Similarly, all other dead cells stay dead.

Press the spacebar to reset the grid with a new random configuration.

![Demo GIF](conway.gif)
