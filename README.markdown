Sorting
=======

Comparison of various sorting algorithms.

What is it?
-----------

`sorting` is a simple modular program that debugs various sorting algorithms in order to spot advantages and drawbacks of each one. It consists of a main program, `sorting.c`, which executes the various algorithms while keeping track of many operations and resource usage.

It currently displays:

* time,
* comparisons,
* swappings,
* writes,
* recursion depth,
* space,
* memory allocations.

The algorithms implemented are divided in two groups depending on their performances:

* fast:
  * comb\_sort,
  * heap\_sort,
  * merge\_sort,
  * quick\_sort,
  * quick\_fast\_sort,
  * shell\_sort,
  * ciura\_shell\_sort;
* slow:
  * bubble\_sort,
  * cocktail\_sort,
  * gnome\_sort,
  * insertion\_sort,
  * selection\_sort.

`sorting` performs sorting on different types of arrays in order to emphasize different characteristics of the algorithms (such as adaptiveness).

It currently sorts arrays of *length - type*:

* 5000 - decreasing,
* 15000 - decreasing,
* 25000 - decreasing,
* 5000 - almost sorted,
* 15000 - almost sorted,
* 25000 - almost sorted,
* 5000 - random,
* 25000 - random,
* 50000 - random,
* 100000 - random,
* 300000 - random,
* 500000 - random.
