#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
    int *tmp = malloc(size * sizeof(int));

    if (tmp == NULL)
        return;

    merge(array, size, tmp);
    free(tmp);
}

/**
 * merge - Merges two subarrays of array[]
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @tmp: Temporary array to store sorted elements
 */
void merge(int *array, size_t size, int *tmp)
{
    size_t left = size / 2, right = size - left;
    size_t i = 0, j = 0, f = 0;
    int *right_array = array + left;

    if (size <= 1)
        return;

    merge(array, left, tmp);
    merge(right_array, right, tmp);

    for (i = 0; i < left; i++)
        tmp[i] = array[i];

    printf("Merging...\n[left]: ");
    print_array(array, left);
    printf("[right]: ");
    print_array(right_array, right);

    i = 0;

    while (i < left || j < right)
    {
        while (j < right && (i >= left || right_array[j] < tmp[i]))
            array[f++] = right_array[j++];
        while (i < left && (j >= right || right_array[j] >= tmp[i]))
            array[f++] = tmp[i++];
    }

    printf("[Done]: ");
    print_array(array, size);
}