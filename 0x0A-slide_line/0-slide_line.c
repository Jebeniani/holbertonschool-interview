#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers to the left or to the right
 * @line: a pointer to the array of integers
 * @size: the size of the array
 * @direction: the direction to slide and merge the array
 *
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, j, step;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);

    if (direction == SLIDE_LEFT)
        step = 1;
    else
        step = -1;

    for (i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            for (j = i + step; j < size && (int)j >= 0; j += step)
            {
                if (line[j] != 0)
                {
                    if (line[i] == line[j])
                    {
                        line[i] *= 2;
                        line[j] = 0;
                        break;
                    }
                    break;
                }
            }
        }
    }

    for (i = 0, j = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            line[j] = line[i];
            j++;
        }
    }

    while (j < size)
    {
        line[j] = 0;
        j++;
    }

    return (1);
}