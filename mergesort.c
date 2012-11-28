#include "mergesort.h"

void merge_sort(data array[], int len) {
	if (len > 1) {
		int middle = len/2; // split the array
		merge_sort(array, middle); // order from 0 to middle-1
		merge_sort(array+middle, len-middle); // order from middle to len-1
		merge(array, middle, len); // merge the two arrays
	}
}

void merge_sort_debug(data array[], int len, STAT *stat) {
	if (len > 1) {
		int middle = len/2; // split the array
		merge_sort_debug(array, middle, stat); // order from 0 to middle-1
		merge_sort_debug(array+middle, len-middle, stat); // order from middle to len-1
		stat->recc += 2;
		merge_debug(array, middle, len, stat); // merge the two arrays
	}
}

void merge(data array[], int sep, int end) { // merges arrays from 0 to sep-1 and from sep to end-1 (sep is the separation between the two arrays)
	int i = 0, j = sep; // i scans from 0, j scans from j
	data buff[end]; // buff is used to store data to avoid overwriting
	int b = 0;
	while (i < sep && j <  end) {
		if (array[i] < array[j])
			buff[b++] = array[i++];
		else
			buff[b++] = array[j++];
	}
	while (i < sep) // complete the buff
		buff[b++] = array[i++];
	while (b-- > 0) // copy the buff on the array
		array[b] = buff[b];
}

void merge_debug(data array[], int sep, int end, STAT *stat) { // merges arrays from 0 to sep-1 and from sep to end-1 (sep is the separation between the two arrays)
	int i = 0, j = sep; // i scans from 0, j scans from j
	data buff[end]; // buff is used to store data to avoid overwriting
	if (stat->space < end) // update additional space usage
		stat->space = end;
	stat->allo += end;
	int b = 0;
	while (i < sep && j <  end) {
		if (array[i] < array[j]) {
			buff[b++] = array[i++];
			stat->write++;
		}
		else {
			buff[b++] = array[j++];
			stat->write++;
		}
		stat->comp++;
	}
	while (i < sep) { // complete the buff
		buff[b++] = array[i++];
		stat->write++;
	}
	while (b-- > 0) { // copy the buff on the array
		array[b] = buff[b];
		stat->write++;
	}
}
