#include "gnomesort.h"

void gnome_sort(data array[], int len) {
	int pos = 0; // position of the gnome
	data tmp; // temporary variable used to swap elements
	while (pos < len-1) { // while the gnome has not reached the end
		if (pos < 0 || array[pos] <= array[pos+1])
			pos++;
		else {
			tmp = array[pos];
			array[pos] = array[pos+1];
			array[pos+1] = tmp;
			pos--;
		}
	}
}

void gnome_sort_debug(data array[], int len, STAT *stat) {
	int pos = 0; // position of the gnome
	data tmp; // temporary variable used to swap elements
	stat->space++;
	stat->allo++;
	while (pos < len-1) { // while the gnome has not reached the end
		if (pos < 0 || array[pos] <= array[pos+1])
			pos++;
		else {
			tmp = array[pos];
			array[pos] = array[pos+1];
			array[pos+1] = tmp;
			pos--;
			stat->swap++;
		}
		stat->comp++;
	}
}
