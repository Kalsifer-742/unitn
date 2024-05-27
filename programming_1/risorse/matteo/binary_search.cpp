


unsigned long binary_search(long arr[], unsigned long arr_size, long val) {
    //primo e ultimo indice valido di arr
    long low = 0;
    long high = arr_size - 1;

    while (low <= high) {
        //scegli un pivot a meta' tra high e low
        long pivot = low + (high - low) / 2;

        if (val == arr[pivot])
            return pivot;
        //decidiamo quale partizione prendere in considerazione
        else if (val < arr[pivot])
            high = pivot - 1;
        else
            low = pivot + 1;
    }
    return -1;  // if val is not in the array, return -1.
}
