#ifndef GLOBAL_H
#define GLOBAL_H

typedef int data; // type of data to be sorted

typedef struct statistics { // structure used to register statistics about the sorting process
	int comp; // comparisons
	int swap; // swappings
	int recc; // recursive calls
	int read;
	int write; // writes
	int allo; // number allocations
	int space; // additional space required
	int cusp; // currently used space
} STAT;

//enum bool {false, true};

#endif
