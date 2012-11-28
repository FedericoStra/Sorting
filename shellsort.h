#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "global.h"

void shell_sort(data array[], int len);
void shell_sort_debug(data array[], int len, STAT *stat);

void ciura_shell_sort(data array[], int len);
void ciura_shell_sort_debug(data array[], int len, STAT *stat);

int next_gap(int gap);

#endif
