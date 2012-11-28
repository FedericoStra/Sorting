#include "cocktailsort.h"

void cocktail_sort(data array[], int len) {
	int begin = 0; // array is to be sorted from position begin to end+1
	int end = len-1;
	int i; // currently scanning position: comparing array[i] and array[i+1]
	int new_end = begin;
	int new_begin = end;
	while (begin < end) { // while array is not completely sorted
		new_end = begin;
		for (i = begin; i < end; i++) // scan from begin to end
			if (array[i] > array[i+1]) {
				data tmp = array[i];
				array[i] = array[i+1];
				array[i+1] = tmp;
				new_end = i;
			}
		end = new_end;
		new_begin = end;
		for (i = end-1; i >= begin; i--) // scan from end to begin
			if (array[i] > array[i+1]) {
				data tmp = array[i];
				array[i] = array[i+1];
				array[i+1] = tmp;
				new_begin = i;
			}
		begin = new_begin;
	}
}

void cocktail_sort_debug(data array[], int len, STAT *stat) {
	int begin = 0; // array is to be sorted from position begin to end+1
	int end = len-1;
	int i; // currently scanning position: comparing array[i] and array[i+1]
	int new_end = begin;
	int new_begin = end;
	data tmp; // temporary variable used to swap elements
	stat->space++;
	stat->allo++;
	while (begin < end) { // while array is not completely sorted
		new_end = begin;
		for (i = begin; i < end; i++) { // scan from begin to end
			if (array[i] > array[i+1]) {
				tmp = array[i];
				array[i] = array[i+1];
				array[i+1] = tmp;
				new_end = i;
				stat->swap++; // count swappings
			}
			stat->comp++; // count comparisons
		}
		end = new_end;
		new_begin = end;
		for (i = end-1; i >= begin; i--) { // scan from end to begin
			if (array[i] > array[i+1]) {
				tmp = array[i];
				array[i] = array[i+1];
				array[i+1] = tmp;
				new_begin = i;
				stat->swap++; // count swappings
			}
			stat->comp++; // count comparisons
		}
		begin = new_begin;
	}
}
