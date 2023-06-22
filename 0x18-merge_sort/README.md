# Merge Sort Algorithm

This repository contains an implementation of the Merge Sort algorithm in C programming language. Merge Sort is an efficient sorting algorithm that uses a divide-and-conquer approach to sort an array of integers in ascending order.

## Implementation

The implementation consists of the following files:

- `sort.h`: Header file containing the function prototypes.
- `print_array.c`: File containing the `print_array` function to print an array of integers.
- `merge_sort.c`: File containing the `merge_sort` function to sort an array using the Merge Sort algorithm.
- `main.c`: Main file showcasing the usage of `print_array` and `merge_sort` functions.

## Usage

To use the Merge Sort algorithm, follow these steps:

1. Clone this repository or download the source code.
2. Include the `sort.h` header file in your program.
3. Call the `merge_sort` function, passing the array to be sorted and its size as arguments.
4. The array will be sorted in ascending order.
5. Use the `print_array` function to print the sorted array.

Here's an example of how to use the Merge Sort algorithm:

```c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    printf("Original array:\n");
    print_array(array, n);

    merge_sort(array, n);

    printf("Sorted array:\n");
    print_array(array, n);

    return 0;
}
```
## Complexity Analysis
The Merge Sort algorithm has a time complexity of O(n log n) in all cases (best, average, and worst). This makes it an efficient sorting algorithm for large datasets.

## Contributing
Contributions to this repository are welcome! If you find any issues or have suggestions for improvement, feel free to create a pull request or submit an issue.