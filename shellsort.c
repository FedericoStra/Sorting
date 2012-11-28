#include "shellsort.h"

void shell_sort(data array[], int len) {
	int gap = len/2; // gap of comparisons
	int i, j;
	data tmp; // temporary variable used to swap elements
	while (gap > 0) {
		for (i = gap; i < len; i++) {
			tmp = array[i];
			j = i;
			while (j >= gap && array[j-gap] > tmp) {
				array[j] = array[j-gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		if (1 < gap && gap < 4)
			gap = 1;
		else
			gap = (int)(gap / 2.2);
	}
}

void shell_sort_debug(data array[], int len, STAT *stat) {
	int gap = len/2; // gap of comparisons
	int i, j;
	data tmp; // temporary variable used to swap elements
	stat->space++;
	stat->allo++;
	while (gap > 0) {
		for (i = gap; i < len; i++) {
			tmp = array[i];
			j = i;
			while (j >= gap && array[j-gap] > tmp) {
				array[j] = array[j-gap];
				j -= gap;
				stat->comp++;
				stat->write++;
			}
			array[j] = tmp;
			stat->write++;
		}
		if (1 < gap && gap < 4)
			gap = 1;
		else
			gap = (int)(gap / 2.2);
	}
}

/*
According to Marcin Ciura, the best gap sequence is 1, 4, 10, 23, 57, 132, 301, 701, 1750 and then a geometric progression with common ratio 2.2
Source: http://en.wikipedia.org/wiki/Shell_sort#Gap_sequence
*/

int next_gap(int gap) {
	if (gap <= 1)
		return 0;
	else if (gap <= 4)
		return 1;
	else if (gap <= 10)
		return 4;
	else if (gap <= 23)
		return 10;
	else if (gap <= 57)
		return 23;
	else if (gap <= 132)
		return 57;
	else if (gap <= 301)
		return 132;
	else if (gap <= 701)
		return 301;
	else if (gap <= 1750)
		return 701;
	float newgap = 1750;
	while (2.2*newgap < gap)
		newgap = (int)(2.2*newgap);
	return newgap;
}

void ciura_shell_sort(data array[], int len) {
	int gap = next_gap(len/2); // gap of comparisons
	int i, j;
	data tmp; // temporary variable used to swap elements
	while (gap > 0) {
		for (i = gap; i < len; i++) {
			tmp = array[i];
			j = i;
			while (j >= gap && array[j-gap] > tmp) {
				array[j] = array[j-gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		gap = next_gap(gap);
	}
}

void ciura_shell_sort_debug(data array[], int len, STAT *stat) {
	int gap = next_gap(len); // gap of comparisons
	int i, j;
	data tmp; // temporary variable used to swap elements
	stat->space++;
	stat->allo++;
	while (gap > 0) {
		for (i = gap; i < len; i++) {
			tmp = array[i];
			j = i;
			while (j >= gap && array[j-gap] > tmp) {
				array[j] = array[j-gap];
				j -= gap;
				stat->comp++;
				stat->write++;
			}
			array[j] = tmp;
			stat->write++;
		}
		gap = next_gap(gap);
	}
}

