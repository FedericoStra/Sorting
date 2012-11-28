#include "heapsort.h"

void heap_sort(data array[], int len) {
	int i, heaplen, start;
	data tmp; // temporary variable used to swap elements
	for (start = 0; 2*start+2 < len; start = 2*start+2) ;
	for (i = start; i >= 0; i--)
		siftDown(array, len, i);
	for (heaplen = len; heaplen > 1; heaplen--) {
		tmp = array[0];
		array[0] = array[heaplen-1];
		array[heaplen-1] = tmp;
		siftDown(array, heaplen-1, 0);
	}
}

void heap_sort_debug(data array[], int len, STAT *stat) {
	int i, heaplen, start;
	data tmp; // temporary variable used to swap elements
	stat->space = 1;
	stat->allo++;
	for (start = 0; 2*start+2 < len; start = 2*start+2) ;
	for (i = start; i >= 0; i--)
		siftDown_debug(array, len, i, stat);
	for (heaplen = len; heaplen > 1; heaplen--) {
		tmp = array[0];
		array[0] = array[heaplen-1];
		array[heaplen-1] = tmp;
		siftDown_debug(array, heaplen-1, 0, stat);
		stat->swap++;
	}
}

void siftDown(data array[], int len, int pos) { // warning: working with a MAX-HEAP
	data tmp; // temporary variable used to swap elements
	int newpos;
	while ((newpos = 2*pos+1) < len) { // while pos is not a leaf
		if (newpos+1 < len && array[newpos] < array[newpos+1]) // if right child exists and is less than left child
			newpos++; // point to right child
		if (array[pos] < array[newpos]) { // if father < left child
			tmp = array[pos];
			array[pos] = array[newpos];
			array[newpos] = tmp;
			pos = newpos;
		}
		else
			pos = len;
	}
}

void siftDown_debug(data array[], int len, int pos, STAT *stat) { // warning: working with a MAX-HEAP
	data tmp; // temporary variable used to swap elements
	stat->space = 2;
	stat->allo++;
	int newpos;
	while ((newpos = 2*pos+1) < len) { // while pos is not a leaf
		if (newpos+1 < len)
			if (array[newpos] < array[newpos+1]) { // if right child exists and is less than left child
				newpos++; // point to right child
				stat->comp++;
			}
		if (array[pos] < array[newpos]) { // if father < left child
			tmp = array[pos];
			array[pos] = array[newpos];
			array[newpos] = tmp;
			pos = newpos;
			stat->swap++;
		}
		else
			pos = len;
		stat->comp++;
	}
}
