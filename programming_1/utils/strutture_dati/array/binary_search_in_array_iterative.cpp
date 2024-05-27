int binary_search_in_array_iterative(int x, int array[], int DIM)
{
    int start, end, middle;
    start = 0;
    end = DIM - 1;
    if(x < array[start] || x > array[end] ) return -1;    //  elemento cercato non presente nell'array
    while(start <= end) {
        middle = (start + end) / 2;
        if(array[middle] == x) 
            return middle;
        if(array[middle] < x)
            start = middle + 1;
        else
            end = middle - 1;
    }
    return -1;
}