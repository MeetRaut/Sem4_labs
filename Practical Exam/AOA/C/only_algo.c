// Insertion
for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
}

// Selection
for(int i = 0; i < n-1; i++){
        int min_index = i;

        for(int j = i; j < n; j ++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
}

// Quicksort
void quickSort(int arr[], int first, int last){
    if(first < last){
        int i, j, pivot, temp;    
        i = first;
        pivot = first;
        j = last;

        while(i < j){
            while(arr[i] <= arr[pivot] && i < last){
                i++;
            }

            while(arr[j] > arr[pivot]){
                j--;
            }

            if(i < j){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;

        quickSort(arr, first, j-1);
        quickSort(arr, j+1, last);
    }
}