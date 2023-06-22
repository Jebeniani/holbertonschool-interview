#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of array[]
 * @array: The array to be sorted
 * @left: Starting index of the left subarray
 * @mid: Middle index
 * @right: Ending index of the right subarray
 */
void merge(int *array, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    /* Create temporary arrays */
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    /* Copy data to temporary arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    /* Merge the temporary arrays back into array[l..r]*/
    i = 0;    // Initial index of first subarray
    j = 0;    // Initial index of second subarray
    k = left; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }

    /* Free temporary arrays */
    free(L);
    free(R);
}

/**
 * merge_sort_recursive - Recursive function for merge sort
 * @array: The array to be sorted
 * @left: Starting index of the subarray to be sorted
 * @right: Ending index of the subarray to be sorted
 */
void merge_sort_recursive(int *array, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        /* Sort first and second halves */
        merge_sort_recursive(array, left, mid);
        merge_sort_recursive(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_sort_recursive(array, 0, size - 1);
}
