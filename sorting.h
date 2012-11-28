#ifndef SORTING_H
#define SORTING_H

#include <stdio.h> // for printf()
#include <stdlib.h> // for rand()
#include <time.h> // for clock()

#include "global.h" // for global definitions
#include "algorithms.h" // calls all the sorting algorithms

typedef void (*p2sf)(data *array, int len); // pointer to sorting function
typedef void (*p2sdf)(data *array, int len, STAT *stat); // pointer to sorting debug function

int main();

void reset_stat(STAT *stat);
void print_stat(STAT stat);

void random_array(data array[], int len);
void decreasing_array(data array[], int len);
void almost_sorted_array(data array[], int len, int n, int d);

void copy_array(data a[], data b[], int len);
int compare_arrays(data a[], data b[], int len);
int check_sorted(data array[], int len);
void print_array(data array[], int len);

int execute_test(data originalArray[], int len, p2sf SF[], p2sdf SFD[], char *SFNames[], int nSF);

#endif
