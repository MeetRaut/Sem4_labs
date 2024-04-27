// Quick sort 
#include <stdio.h>
#include <stdlib.h>

void quicksort(int arr[], int first, int last) {
    int i, j, pivot, temp;
    
    // If there is more than one element in the array
    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        
        // Partitioning step
        while (i < j) {
            // Move i to the right until finding an element greater than pivot
            while (arr[i] <= arr[pivot] && i < last)
                i++;
            // Move j to the left until finding an element less than pivot
            while (arr[j] > arr[pivot])
                j--;
            // Swap arr[i] and arr[j] if i is less than j
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        // Place the pivot in its correct position
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        
        // Recursive calls for the two sub-arrays
        quicksort(arr, first, j - 1);
        quicksort(arr, j + 1, last);
    }
}

int main() {
    // Input from the user
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[20];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    // Calling quicksort function to sort the array
    quicksort(arr, 0, n - 1);
    
    // Output
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}