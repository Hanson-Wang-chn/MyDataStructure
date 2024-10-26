#include "Sortable_list.h"
#include "Record.h"

void Sortable_list :: insertion_sort( )
/* Post: The entries of the Sortable list have been rearranged so that the keys in all
the entries are sorted into nondecreasing order.
Uses: Methods for the class Record ; the contiguous List implementation of Chapter 6 */
{
    int first_unsorted; // position of first unsorted entry
    int position; // searches sorted part of list
    Record current; // holds the entry temporarily removed from list
    for (first_unsorted = 1; first_unsorted < count; first_unsorted++)
        if (entry[first_unsorted] < entry[first_unsorted - 1]) {
            position = first_unsorted;
            current = entry[first_unsorted]; // Pull unsorted entry out of the list.
            do { // Shift all entries until the proper position is found.
                entry[position] = entry[position - 1];
                position--; // position is empty.
            } while (position > 0 && entry[position - 1] > current);
            entry[position] = current;
        }
}

//for selection_sort. //选择排序
void Sortable_list :: swap(int low, int high)
/* Pre: low and high are valid positions in the Sortable list .
Post: The entry at position low is swapped with the entry at position high .
Uses: The contiguous List implementation of Chapter 6. */
{
    Record temp;
    temp = entry[low];
    entry[low] = entry[high];
    entry[high] = temp;
}


int Sortable_list :: max_key(int low, int high) {
    int max, current;
    max = low;
    for (current = low + 1; current <= high; current++)
        if (entry[max] < entry[current])
            max = current;
    return max;
}

void Sortable_list :: selection_sort( )
/* Post: The entries of the Sortable list have been rearranged so that the keys in all the entries are sorted into nondecreasing order.
Uses: max_key ,swap . */
{
    for (int position = count-1; position >= 0; position--) {
        int max = max_key(0, position);
        swap(max, position);
    }
}


//for shell_sort. 希尔排序
void Sortable_list :: sort_interval(int start, int increment) {
    int first_unsorted; // position of first unsorted entry
    int position; // searches sorted part of list
    Record current; // holds the entry temporarily removed from list
    for (first_unsorted = start + increment; first_unsorted < count; first_unsorted += increment )
        if (entry[first_unsorted] < entry[first_unsorted - increment]) {
            position = first_unsorted;
            current = entry[first_unsorted]; // Pull unsorted entry out of the list.
            do { // Shift all entries until the proper position is found.
                entry[position] = entry[position - increment];
                position -= increment; // position is empty.
            } while (position > start && entry[position - increment] > current);
            entry[position] = current;
        }
}

void Sortable_list :: shell_sort()
/* Post: The entries of theSortable list have been rearranged so that the keys in all
the entries are sorted into nondecreasing order.
Uses: sort_interval */
{
    int increment, // spacing of entries in sublist
    start; // starting point of sublist
    increment = count;
    do {
        increment = increment/3 + 1;
        for (start = 0; start < increment; start++)
            sort_interval(start, increment); // modified insertion sort
    } while (increment > 1);
}

//for quick_sort.
void Sortable_list :: quick_sort( )
/* Post: The entries of the Sortable list have been rearranged so that their keys are sorted into nondecreasing order.
Uses: Contiguous List implementation of Chapter 6, recursive quick sort .*/
{
    recursive_quick_sort(0, count - 1);
}

void Sortable_list :: recursive_quick_sort(int low, int high)
/* Pre: low and high are valid positions in the Sortable list .
Post: The entries of the Sortable list have been rearranged so that their keys are sorted into nondecreasing order.
Uses: Contiguous List implementation of Chapter 6, recursive quick sort , and partition . */
{
    int pivot_position;
    if (low < high) { // Otherwise, no sorting is needed.
        pivot_position = partition(low, high);
        recursive_quick_sort(low, pivot_position - 1);
        recursive_quick_sort(pivot_position + 1, high);
    }
}

int Sortable_list :: partition(int low, int high)
/* Pre: low and high are valid positions of the Sortable list , with low <= high .
Post: The center (or left center) entry in the range between indices low and high of the Sortable list
has been chosen as a pivot. All entries of the Sortable list between indices low and high , inclusive,
have been rearranged so that those with keys less than the pivot come before the pivot and the remaining
entries come after the pivot. The final position of the pivot is returned.
Uses: swap(int i, int j) (interchanges entries in positions i and j of a Sortable list ), the contiguous
List implementation of Chapter 6, and methods for the class Record . */
{
    Record pivot;
    int i, // used to scan through the list
    last_small; // position of the last key less than pivot，记录小于抽点的数值下标
    swap(low, (low + high)/2);//将抽点与最小位置的值交换，并放置于最小的位置
    pivot = entry[low]; // First entry is now pivot .
    last_small = low; //初始化为最小的位置
    for (i = low + 1; i <= high; i++)
        if (entry[i] < pivot) {
            last_small ++; //从low+1开始放置。
            swap(last_small, i); // Move large entry to right and small to left.
        }
    swap(low, last_small); // Put the pivot into its proper position.
    return last_small;

}

//for heap_sort.
void Sortable_list :: heap_sort( )
/* Post: The entries of the Sortable list have been rearranged so that their keys
are sorted into nondecreasing order.
Uses: The contiguous List implementation of Chapter 6,build_heap , and insert_heap . */
{
    Record current; // temporary storage for moving entries
    int last_unsorted; // Entries beyond last unsorted have been sorted.
    build_heap( ); // First phase: Turn the list into a heap.
    for (last_unsorted = count - 1; last_unsorted > 0; last_unsorted--) {
        current = entry[last_unsorted]; // Extract last entry from list.
        entry[last_unsorted] = entry[0]; // Move top of heap to the end
        insert_heap(current, 0, last_unsorted - 1); // Restore the heap
    }
}

void Sortable_list :: build_heap( )
/* Post: The entries of the Sortable list have been rearranged so that it becomes a heap.
Uses: The contiguous List implementation of Chapter 6, and insert heap . */
{
    int low; // All entries beyond the position low form a heap.
    //非叶子结点K的满足的条件是：2K+1<=COUNT-1
    //K<=1/2*COUNT-1
    for (low = count/2 - 1; low >= 0; low--) {
        Record current = entry[low];
        insert_heap(current, low, count - 1);
    }
}

void Sortable_list :: insert_heap(const Record &current, int low, int high)
/* Pre: The entries of the Sortable list between indices low + 1 and high ,
inclusive, form a heap. The entry in position low will be discarded.
Post: The entry current has been inserted into the Sortable list and the
entries rearranged so that the entries between indices low and high ,
inclusive, form a heap.
Uses: The class Record , and the contiguous List implementation of Chapter 6.*/
{
    int large; // position of child of entry[low] with the larger key
    large = 2 * low + 1; // large is now the left child of low.
    while (large <= high) {
        if (large < high && entry[large] < entry[large + 1])
            large++; // large is now the child of low with the largest key.
        if (current >= entry[large])
            break; // current belongs in position low.
        else { // Promote entry[large] and move down the tree.
            entry[low] = entry[large];
            low = large;
            large = 2 * low + 1;
        }
    }
    entry[low] = current;
}


//for Merge_sort
void divide_from(Sortable_list & mylist, Sortable_list & secondlist) {
    int mid=(mylist.size()-1)/2; //divide the dots
    int secondsize=mylist.size()-(mid+1); //the length of second array
    for (int i=0; i<secondsize; i++){
        Record x;
        if(mylist.retrieve(mid+1, x)==success){
            secondlist.insert(i, x);
            mylist.remove(mid+1, x);//delete the dot from the initial array
        }
    }

}
void combine(Sortable_list & firstsortlist, const Sortable_list & secondsortlist) {
    Sortable_list tmp;
    int m=0, n=0, i=0;//m stands for the index of the first array，n stands for the second one
    while(m<firstsortlist.size() && n<secondsortlist.size()){
        Record x, y;
        firstsortlist.retrieve(m, x);
        secondsortlist.retrieve(n, y);
        if(x<=y){
            tmp.insert(i++, x);//i is the index of the combined one
            m++;
        }
        else{
            tmp.insert(i++, y);
            n++;
        }
    }
    while(m<firstsortlist.size()){
        Record x;
        firstsortlist.retrieve(m, x);
        tmp.insert(i++, x);
        m++;
    }
    while(n<secondsortlist.size()){
        Record y;
        secondsortlist.retrieve(n, y);
        tmp.insert(i++, y);
        n++;
    }
    firstsortlist=tmp;

}
void Merge_sort(Sortable_list & mylist) {
    Sortable_list secondlist;
    if (mylist.size()>1) {
        divide_from(mylist, secondlist);
        Merge_sort(mylist);
        Merge_sort(secondlist);
        combine(mylist, secondlist);
    }

}