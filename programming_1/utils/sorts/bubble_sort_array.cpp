void bubble_sort(int arr[], int DIM){
	int tmp;
	
	bool swapped = true;	
	while(swapped){
		swapped = false;
		for(int i = 0; i < DIM-1; i++){
			if(arr[i] > arr[i+1]){
				tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
				swapped = true;
			}
		}	
	}
}