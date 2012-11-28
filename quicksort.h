
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "global.h"

void quick_sort(data array[], int len);
void quick_sort_debug(data array[], int len, STAT *stat);
void quick_fast_sort(data array[], int len);
void quick_fast_sort_debug(data array[], int len, STAT *stat);

int partition(data array[], int len, int pivot_index);
int partition_debug(data array[], int len, int pivot_index, STAT *stat);
int partition_fast(data array[], int len, int pivot_index);
int partition_fast_debug(data array[], int len, int pivot_index, STAT *stat);

#endif
