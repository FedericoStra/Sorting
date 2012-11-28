#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "global.h"

void heap_sort(data array[], int len);
void heap_sort_debug(data array[], int len, STAT *stat);

void siftDown(data array[], int len, int pos);
void siftDown_debug(data array[], int len, int pos, STAT *stat);

#endif
