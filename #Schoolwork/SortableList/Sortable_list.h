#ifndef SORTABLE_LIST_H_INCLUDED
#define SORTABLE_LIST_H_INCLUDED

#include "List.cpp"
#include "Record.h"

class Sortable_list: public List<Record> {
public: // Add prototypes for sorting methods here.
    void insertion_sort( );  // for insertion sort

    //for selection_sort.
    void swap(int low, int high);  // swap two elements
    int max_key(int low, int high);  // return the max element in the list
    void selection_sort( );  // selection sort

    //for shell_sort.
    void sort_interval(int start, int increment);  // sort interval in the shell sort
    void shell_sort();  // shell sort

    //for quick_sort.
    void quick_sort( );  // quick sort
    void recursive_quick_sort(int low, int high);  //recursive
    int partition(int low, int high);  // divide the list into two parts

    //for heap_sort.
    void heap_sort( );  // heap sort
    void build_heap( );  // create a new heap
    void insert_heap(const Record &current, int low, int high);  // insert a heap

private: // Add prototypes for auxiliary functions here.

};

//for Merge_sort
void divide_from(Sortable_list & mylist, Sortable_list & secondlist);  // divide from the merge sort
void combine(Sortable_list & firstsortlist, const Sortable_list & secondsortlist);  // combine the two parts into one
void Merge_sort(Sortable_list & mylist);  // merge sort

#endif // SORTABLE_LIST_H_INCLUDED
