#include "bubblesort.h"

void bubble_sort(data array[], int len) {
	int last_swap = len; // max index to check
	int i; // currently scanning position: comparing array[i] and array[i-1]; i runs from 1 to len
	int new_last_swap; // variable to remember the position of the last swap
	data tmp; // temporary variable used to swap elements
	while (last_swap > 1) { // while array is not completely sorted
		new_last_swap = 0;
		for (i = 1; i < last_swap; i++) // check from position 1 to last_swap
			if (array[i] < array[i-1]) { // if not in order, swap
				tmp = array[i];
				array[i] = array[i-1];
				array[i-1] = tmp;
				new_last_swap = i; // remember the position of the last swap
			}
		last_swap = new_last_swap; // set the new last swap position
	}
}

void bubble_sort_debug(data array[], int len, STAT *stat) {
	int last_swap = len; // max index to check
	int i; // currently scanning position: comparing array[i] and array[i-1]; i runs from 1 to len
	int new_last_swap; // variable to remember the position of the last swap
	data tmp; // temporary variable used to swap elements
	stat->space++;
	stat->allo++;
	while (last_swap > 1) { // while array is not completely sorted
		new_last_swap = 0;
		for (i = 1; i < last_swap; i++) { // check from position 1 to last_swap
			if (array[i] < array[i-1]) { // if not in order, swap
				tmp = array[i];
				array[i] = array[i-1];
				array[i-1] = tmp;
				new_last_swap = i; // remember the position of the last swap
				stat->swap++; // count swapping
			}
			stat->comp++; // count comparisons
		}
		last_swap = new_last_swap; // set the new last swap position
	}
}
