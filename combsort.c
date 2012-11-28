#include "combsort.h"

void comb_sort(data array[], int len) {
	int gap = len;
	int swaps = 0; // 1 if a swap has occurred, 0 if none
	int i; // index used to scan the list
	data tmp; // temporary variable used to swap elements
	while (gap > 1 || swaps) {
		if (gap > 1) // update the gap value
			gap /= 1.24;
		swaps = 0; // reset the swaps flag
		for (i = 0; i+gap < len; i++)
			if (array[i] > array[i+gap]) {
				tmp = array[i];
				array[i] = array[i+gap];
				array[i+gap] = tmp;
				swaps = 1;
			}
	}
}

void comb_sort_debug(data array[], int len, STAT *stat) {
	int gap = len;
	int swaps = 0; // 1 if a swap has occurred, 0 if none
	int i; // index used to scan the list
	data tmp; // temporary variable used to swap elements
	stat->space++;
	stat->allo++;
	while (gap > 1 || swaps) {
		if (gap > 1) // update the gap value
			gap /= 1.24;
		swaps = 0; // reset the swaps flag
		for (i = 0; i+gap < len; i++) {
			if (array[i] > array[i+gap]) {
				tmp = array[i];
				array[i] = array[i+gap];
				array[i+gap] = tmp;
				swaps = 1;
				stat->swap++;
			}
			stat->comp++;
		}
	}
}
