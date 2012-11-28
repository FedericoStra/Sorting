#include "sorting.h"

#define MAXLENGTH 5000000 // maximum length of the array to be sorted

p2sf SF[] = { // sorting functions
	bubble_sort,
	cocktail_sort,
	comb_sort,
	gnome_sort,
	heap_sort,
	insertion_sort,
	merge_sort,
	quick_sort,
	quick_fast_sort,
	selection_sort,
	shell_sort,
	ciura_shell_sort
};

p2sdf SFD[] = { // sorting functions with debug
	bubble_sort_debug,
	cocktail_sort_debug,
	comb_sort_debug,
	gnome_sort_debug,
	heap_sort_debug,
	insertion_sort_debug,
	merge_sort_debug,
	quick_sort_debug,
	quick_fast_sort_debug,
	selection_sort_debug,
	shell_sort_debug,
	ciura_shell_sort_debug
};

char *SFNames[] = {
	"Bubble sort",
	"Cocktail sort",
	"Comb sort",
	"Gnome sort",
	"Heap sort",
	"Insertion sort",
	"Merge sort",
	"Quick sort",
	"Quick fast sort",
	"Selection sort",
	"Shell sort",
	"Ciura Shell sort"
};

int nSF = sizeof(SF)/sizeof(*SF); // number of sorting functions

p2sf fastSF[] = { // fast sorting functions
	comb_sort,
	heap_sort,
	merge_sort,
	quick_sort,
	quick_fast_sort,
	shell_sort,
	ciura_shell_sort
};

p2sdf fastSFD[] = { // fast sorting functions with debug
	comb_sort_debug,
	heap_sort_debug,
	merge_sort_debug,
	quick_sort_debug,
	quick_fast_sort_debug,
	shell_sort_debug,
	ciura_shell_sort_debug
};

char *fastSFNames[] = {
	"Comb sort",
	"Heap sort",
	"Merge sort",
	"Quick sort",
	"Quick fast sort",
	"Shell sort",
	"Ciura Shell sort"
};

int nFastSF = sizeof(fastSF)/sizeof(*fastSF); // number of fast sorting functions

int main() {
	int  maxlen = 500000, len; // array length
	data originalArray[maxlen]; // original set of data

	// Decreasing
	len = 5000;
	printf("ARRAY LENGTH: %d. TYPE: Decreasing\n", len);
	decreasing_array(originalArray, len);
	execute_test(originalArray, len, SF, SFD, SFNames, nSF);

	len = 15000;
	printf("ARRAY LENGTH: %d. TYPE: Decreasing\n", len);
	decreasing_array(originalArray, len);
	execute_test(originalArray, len, SF, SFD, SFNames, nSF);

	len = 25000;
	printf("ARRAY LENGTH: %d. TYPE: Decreasing\n", len);
	decreasing_array(originalArray, len);
	execute_test(originalArray, len, SF, SFD, SFNames, nSF);

	// Almost sorted
	len = 5000;
	printf("ARRAY LENGTH: %d. TYPE: Almost sorted\n", len);
	almost_sorted_array(originalArray, len, 1000, 100);
	execute_test(originalArray, len, SF, SFD, SFNames, nSF);

	len = 15000;
	printf("ARRAY LENGTH: %d. TYPE: Almost sorted\n", len);
	almost_sorted_array(originalArray, len, 3000, 300);
	execute_test(originalArray, len, SF, SFD, SFNames, nSF);

	len = 25000;
	printf("ARRAY LENGTH: %d. TYPE: Almost sorted\n", len);
	almost_sorted_array(originalArray, len, 5000, 500);
	execute_test(originalArray, len, SF, SFD, SFNames, nSF);

	// Random
	random_array(originalArray, maxlen); // generate random array

	len = 5000;
	printf("ARRAY LENGTH: %d. TYPE: Random\n", len);
	execute_test(originalArray, len, SF, SFD, SFNames, nSF);

	len = 25000;
	printf("ARRAY LENGTH: %d. TYPE: Random\n", len);
	execute_test(originalArray, len, SF, SFD, SFNames, nSF);

	len = 50000;
	printf("ARRAY LENGTH: %d. TYPE: Random\n", len);
	execute_test(originalArray, len, fastSF, fastSFD, fastSFNames, nFastSF);

	len = 100000;
	printf("ARRAY LENGTH: %d. TYPE: Random\n", len);
	execute_test(originalArray, len, fastSF, fastSFD, fastSFNames, nFastSF);

	len = 300000;
	printf("ARRAY LENGTH: %d. TYPE: Random\n", len);
	execute_test(originalArray, len, fastSF, fastSFD, fastSFNames, nFastSF);

	len = maxlen;
	printf("ARRAY LENGTH: %d. TYPE: Random\n", len);
	execute_test(originalArray, len, fastSF, fastSFD, fastSFNames, nFastSF);
}

void reset_stat(STAT *stat) {
	stat->comp = 0;
	stat->swap = 0;
	stat->recc = 0;
	stat->read = 0;
	stat->write = 0;
	stat->allo = 0;
	stat->space = 0;
	stat->cusp = 0;
}

void print_stat(STAT stat) {
	printf("%15d%15d%15d%15d%15d%15d\n", stat.comp, stat.swap, stat.write, stat.recc, stat.space, stat.allo);
}

void random_array(data array[], int len) {
	int i;
	for (i = 0; i < len; i++)
		array[i] = rand();
}

void decreasing_array(data array[], int len) {
	int i;
	for (i = 0; i < len; i++)
		array[i] = len-i;
}

void almost_sorted_array(data array[], int len, int n, int d) {
	int i, j, k;
	data tmp;
	for (i = 0; i < len; i++)
		array[i] = i;
	for (i = 0; i < n; i++) {
		j = rand() % (len-d);
		k = j + (rand() % d);
		tmp = array[j];
		array[j] = array[k];
		array[k] = tmp;
		}
}

void copy_array(data a[], data b[], int len) {
	int i;
	for (i = 0; i < len; i++)
		b[i] = a[i];
}

int compare_arrays(data a[], data b[], int len) {
	int i;
	for (i = 0; i < len; i++)
		if (a[i] != b[i])
			return 0;
	return 1;
}

int check_sorted(data array[], int len) {
	int i;
	for (i = 0; i < len-1; i++)
		if (array[i] > array[i+1])
			return 0;
	return 1;
}

void print_array(data array[], int len) {
	int i;
	for (i = 0; i < len-1; i++)
		printf("%d - ", array[i]);
	printf("%d\n", array[len-1]);
}

int execute_test(data originalArray[], int len, p2sf SF[], p2sdf SFD[], char *SFNames[], int nSF) {
	data sortedArray[len]; // already sorted array used to check sorting
	data array[len]; // array to be sorted
	STAT stat;
	clock_t start, stop, elapsed;
	int i; // index used to select the sorting function

	copy_array(originalArray, sortedArray, len); // copy to sortedArray
	quick_sort(sortedArray, len); // sort the sortedArray
	if (check_sorted(sortedArray, len))
		printf("Initialization completed successfully.\n");
	else {
		printf("Initialization error.\n");
		return 0;
	}
	printf("SORTING FUNCTION     TIME    COMPARISONS      SWAPPINGS         WRITES      RECURSION          SPACE    ALLOCATIONS\n");
	for (i = 0; i < nSF; i++) {
		copy_array(originalArray, array, len); // build array
		reset_stat(&stat); // reset stat
		(*SFD[i])(array, len, &stat); // debugging test
		if (!compare_arrays(array, sortedArray, len)) { // if sorting error
			printf("%-20s Sorting failed.\n", SFNames[i]);
			continue;
			}
		copy_array(originalArray, array, len); // build array
		start = clock();
		(*SF[i])(array, len); // timing test
		stop = clock();
		if (!compare_arrays(array, sortedArray, len)) { // if sorting error
			printf("%-20s Sorting failed.\n", SFNames[i]);
			continue;
			}
		printf("%-20s %2.2f", SFNames[i], (float)(stop-start)/CLOCKS_PER_SEC);
		print_stat(stat);
	}
	printf("\n");
	return 1;
}
