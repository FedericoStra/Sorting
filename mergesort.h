#ifndef MERGESORT_H
#define MERGESORT_H

#include "global.h"

void merge_sort(data array[], int len);
void merge_sort_debug(data array[], int len, STAT *stat);

void merge(data array[], int sep, int end);
void merge_debug(data array[], int sep, int end, STAT *stat);

#endif
