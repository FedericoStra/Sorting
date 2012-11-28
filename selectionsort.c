#include "selectionsort.h"

void selection_sort(data array[], int len) {
	int i; // part of array from 0 to i-1 is already sorted
	int min; // min is the position of the minimum element
	int k; // variable used to scan the array to seach the min
	data tmp; // temporary variable used to swap elements
	for (i = 0; i < len; i++) { // increment i untill all the array is sorted
		min = i;
		for (k = i+1; k < len; k++) // search the position of min
			if (array[k] < array[min])
				min = k;
		if (i != min) {
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
		}
	}
}

void selection_sort_debug(data array[], int len, STAT *stat) {
	int i; // part of array from 0 to i-1 is already sorted
	int min; // min is the position of the minimum element
	int k; // variable used to scan the array to seach the min
	data tmp; // temporary variable used to swap elements
	stat->space++;
	stat->allo++;
	for (i = 0; i < len; i++) { // increment i untill all the array is sorted
		min = i;
		for (k = i+1; k < len; k++) { // search the position of min
			if (array[k] < array[min])
				min = k;
			stat->comp++;
			}
		if (i != min) {
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			stat->swap++;
		}
	}
}

