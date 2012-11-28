#include "insertionsort.h"

void insertion_sort(data array[], int len) {
	int i; // part of array from 0 to i-1 is already sorted
	int j; // index to swap elements
	data tmp; // temporary variable used to swap elements
	for (i = 1; i < len; i++) // increment i untill all the array is sorted
		for (j = i; j>0 && array[j-1] > array[j]; j--) { // while the element array[i] has not come to its place yet
			tmp = array[j];
			array[j] = array[j-1];
			array[j-1] = tmp;
		}
}

void insertion_sort_debug(data array[], int len, STAT *stat) {
	int i; // part of array from 0 to i-1 is already sorted
	int j; // index to swap elements
	data tmp; // temporary variable used to swap elements
	stat->space++;
	stat->allo++;
	for (i = 1; i < len; i++) // increment i untill all the array is sorted
		for (j = i; j>0 && array[j-1] > array[j]; j--) { // while the element array[i] has not come to its place yet
			tmp = array[j];
			array[j] = array[j-1];
			array[j-1] = tmp;
			stat->comp++;
			stat->swap++;
		}
}
