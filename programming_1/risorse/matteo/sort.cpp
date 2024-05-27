#include "sort.hpp"

static void swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}
static void swap(long& a, long& b) {
    long c = a;
    a = b;
    b = c;
}

static long partition(long arr[], long first, long last) {
    //scelgo l'ultimo elemento come pivot
    long pivot = arr[last];
    long i = first;

    for (long j = first; j < last; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;  // increment index of smaller element
        }
    }
    swap(arr[i], arr[last]);
    
    return i;
}
static void quicksort_recursive(long arr[], long first, long last) {
    if(first < last) {
        long split = partition(arr, first, last);
        quicksort_recursive(arr, first, split-1);
        quicksort_recursive(arr, split+1, last);
    }
}
void quicksort(long arr[], long arr_size) {
    quicksort_recursive(arr, 0, arr_size-1);
}


void bubble_sort(int* arr, long size) {
    bool swapped = true;
    for(int i = 0; i < size && swapped; i++) {
        swapped = false;
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
    }
}

