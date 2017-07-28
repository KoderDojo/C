# Algorithms

Various algorithms coded in multiple programming languages while learning C and C++.

## Search

Two of the more common search algorithms are **linear search** and **binary search**.

*Linear search* is a sequential search that checks each value in a sequence one at a time until the value is found or all items have been checked. It runs in O(n). Worst case is the item is not found in the sequence, because linear search has to check all values in the sequence.

*Binary search* is a search algorithm that requires a sorted array and is able to reduce the target search area by 1/2 after each sampling. It runs in O(logn). Worst case is the item is not found in the sequence just like linear search.

* [linear-search.c](search/linear-search.c) - A simple linear search in C of an array containing integer values. The algorithm checks each value in the array one at a time sequentially in a *while* loop. The search is terminated when the value is found or every item in the sequence has been checked.
* [binary-search.c](search/binary-search.c) - Searches a sorted array of integers sorted by Insertion Sort. The algorithm continuously reads the value at the midpoint of the low and hi indexes until it either finds the target value or determines the value is not in the array.

## Code

The C and C++ code is written with **JetBrains CLion**.

The C# code is written with **Visual Studio 2017** or **JetBrains Rider**.

