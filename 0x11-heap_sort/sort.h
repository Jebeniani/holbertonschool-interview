#ifndef SORT_H
#define SORT_H

void print_array(const int *array, size_t size);
void swap_int(int *a, int *b);
void heapify(int *array, size_t size, size_t i, size_t tot_sz);
void heap_sort(int *array, size_t size);

#endif
