#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * menger - Draws a square of a given size using the '#' character.
 * @level: The level
 * return: The size of the square
 */
void menger(int level)
{
if (level < 0)
{
return;
}
int size = pow(3, level);
draw_sponge(level, 0, 0, size);
}

/**
 * draw_sponge - Draws a 2D Menger Sponge of
 * a given level using the '#' and ' ' characters.
 * @level: The level to draw
 * @x: The x position
 * @y: The y position
 * @size: The size of the square
 *
 * return: The
 */
void draw_sponge(int level, int x, int y, int size)
{
if (level == 0)
{
printf("#");
return;
}
int sub_size = size / 3;
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
if (i == 1 && j == 1)
{
printf(" ");
}
else
{
draw_sponge(level - 1, x + i * sub_size, y + j * sub_size, sub_size);
}
}
printf("\n");
}
}
