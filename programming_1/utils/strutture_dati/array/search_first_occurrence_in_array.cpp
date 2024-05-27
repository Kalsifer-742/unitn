int search_first_occurrence_in_array(int x, int arr[], int DIM){
	for(int i = 0; i < DIM; i++){
		if(arr[i] == x){
			return i;
		}
	}
	return -1;
}