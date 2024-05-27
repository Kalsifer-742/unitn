void copy_array(int arr1[], int arr2[], int start1, int end1, int start2){
	for(int i = start1, j = start2; i < end1; i++, j++){
		arr2[j] = arr1[i];
	}
}