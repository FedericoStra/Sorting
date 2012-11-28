sorting : sorting.o bubblesort.o cocktailsort.o combsort.o gnomesort.o heapsort.o insertionsort.o mergesort.o quicksort.o selectionsort.o shellsort.o
	gcc sorting.o bubblesort.o cocktailsort.o combsort.o gnomesort.o heapsort.o insertionsort.o mergesort.o quicksort.o selectionsort.o shellsort.o -o sorting -O3

sorting.o : sorting.c sorting.h global.h algorithms.h
	gcc -c sorting.c -o sorting.o -O3

bubblesort.o : bubblesort.c bubblesort.h global.h
	gcc -c bubblesort.c -o bubblesort.o -O3

cocktailsort.o : cocktailsort.c cocktailsort.h global.h
	gcc -c cocktailsort.c -o cocktailsort.o -O3

combsort.o : combsort.c combsort.h global.h
	gcc -c combsort.c -o combsort.o -O3

gnomesort.o : gnomesort.c gnomesort.h global.h
	gcc -c gnomesort.c -o gnomesort.o -O3

heapsort.o : heapsort.c heapsort.h global.h
	gcc -c heapsort.c -o heapsort.o -O3

insertionsort.o : insertionsort.c insertionsort.h global.h
	gcc -c insertionsort.c -o insertionsort.o -O3

mergesort.o : mergesort.c mergesort.h global.h
	gcc -c mergesort.c -o mergesort.o -O3

quicksort.o : quicksort.c quicksort.h global.h
	gcc -c quicksort.c -o quicksort.o -O3

selectionsort.o : selectionsort.c selectionsort.h global.h
	gcc -c selectionsort.c -o selectionsort.o -O3

shellsort.o : shellsort.c shellsort.h global.h
	gcc -c shellsort.c -o shellsort.o -O3

clean:
	rm *.o sorting
