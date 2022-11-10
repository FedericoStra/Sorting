#include "quicksort.h"
#include <stdlib.h>

void quick_sort(data array[], int len) {
	if (len > 1) {
		int pivot_index = rand()%(len-1); // choose pivot
		int pivot_new_index = partition(array, len, pivot_index); // partition the array and get the new pivot position
		quick_sort(array, pivot_new_index); // quick sort the first part
		quick_sort(array+pivot_new_index+1, len-pivot_new_index-1); // quick sort the second part
	}
}

void quick_sort_debug(data array[], int len, STAT *stat) {
	if (len > 1) {
		int pivot_index = rand()%(len-1); // choose pivot
		int pivot_new_index = partition_debug(array, len, pivot_index, stat); // partition the array and get the new pivot position
		quick_sort_debug(array, pivot_new_index, stat); // quick sort the first part
		quick_sort_debug(array+pivot_new_index+1, len-pivot_new_index-1, stat); // quick sort the second part
		stat->recc += 2;
	}
}

void quick_fast_sort(data array[], int len) {
	if (len > 1) {
		int pivot_index = rand()%(len-1); // choose pivot
		int pivot_new_index = partition_fast(array, len, pivot_index); // partition the array and get the new pivot position
		quick_fast_sort(array, pivot_new_index); // quick sort the first part
		quick_fast_sort(array+pivot_new_index+1, len-pivot_new_index-1); // quick sort the second part
	}
}

void quick_fast_sort_debug(data array[], int len, STAT *stat) {
	if (len > 1) {
		int pivot_index = rand()%(len-1); // choose pivot
		int pivot_new_index = partition_fast_debug(array, len, pivot_index, stat); // partition the array and get the new pivot position
		quick_fast_sort_debug(array, pivot_new_index, stat); // quick sort the first part
		quick_fast_sort_debug(array+pivot_new_index+1, len-pivot_new_index-1, stat); // quick sort the second part
		stat->recc += 2;
	}
}

int partition(data array[], int len, int pivot_index) {
	data pivot_value = array[pivot_index];
	array[pivot_index] = array[len-1]; // swap pivot with last element
	array[len-1] = pivot_value;
	int store = 0; // storing index
	int i;
	for (i = 0; i < len-1; i++) // left ≤ i ≤ right-2    (pivot is at right-1)
		if (array[i] < pivot_value) {
			data tmp = array[i];
			array[i] = array[store];
			array[store] = tmp;
			store++;
		}
	array[len-1] = array[store]; // move pivot to its final place
	array[store] = pivot_value;
	return store; // return the position of the pivot
}

int partition_debug(data array[], int len, int pivot_index, STAT *stat) {
	data pivot_value = array[pivot_index];
	data tmp;
	stat->allo += 2;
	stat->space = 2;
	array[pivot_index] = array[len-1]; // swap pivot with last element
	array[len-1] = pivot_value;
	stat->swap++;
	int store = 0; // storing index
	int i;
	for (i = 0; i < len-1; i++) { // left ≤ i ≤ right-2    (pivot is at right-1)
		if (array[i] < pivot_value) {
			tmp = array[i];
			array[i] = array[store];
			array[store] = tmp;
			store++;
			stat->swap++;
		}
		stat->comp++;
	}
	array[len-1] = array[store]; // move pivot to its final place
	array[store] = pivot_value;
	stat->swap++;
	return store; // return the position of the pivot
}

int partition_fast(data array[], int len, int pivot_index) {
	data pivot_value = array[pivot_index];
	array[pivot_index] = array[len-1]; // swap pivot with last element
	array[len-1] = pivot_value;
	int left = 0; // left index
	int right = len-2; // right index
	while (left < right) { // ( < pivot ), pivot, ( >= pivot)
		while (array[left] < pivot_value && left < right)
			left++;
		while (array[right] >= pivot_value && left < right)
			right--;
		if (left < right) {
			data tmp = array[left];
			array[left] = array[right];
			array[right] = tmp;
			left++;
			right--;
		}
	}
	if (left == right)
		if (array[left] < pivot_value)
			left++;
	array[len-1] = array[left]; // move pivot to its final place
	array[left] = pivot_value;
	return left; // return the position of the pivot
}

int partition_fast_debug(data array[], int len, int pivot_index, STAT *stat) {
	data pivot_value = array[pivot_index];
	data tmp;
	stat->allo += 2;
	stat->space = 2;
	array[pivot_index] = array[len-1]; // swap pivot with last element
	array[len-1] = pivot_value;
	stat->swap++;
	int left = 0; // left index
	int right = len-2; // right index
	while (left < right) { // ( < pivot ), pivot, ( >= pivot)
		while (array[left] < pivot_value && left < right) {
			left++;
			stat->comp++;
			}
		while (array[right] >= pivot_value && left < right) {
			right--;
			stat->comp++;
			}
		if (left < right) {
			tmp = array[left];
			array[left] = array[right];
			array[right] = tmp;
			left++;
			right--;
			stat->swap += 2;
		}
	}
	if (left == right)
		if (array[left] < pivot_value)
			left++;
	array[len-1] = array[left]; // move pivot to its final place
	array[left] = pivot_value;
	stat->swap++;
	return left; // return the position of the pivot
}
