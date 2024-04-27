// Selection sort 
#include <stdio.h>

int main() {
    // Input from the user
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[20];
    
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Selection sort algorithm
    for (int i = 0; i < n - 1; i++) {
        int minindex = i;
        
        // Finding the index of the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }

        // Swapping the minimum element with the first element of the unsorted part
        int temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }

    // Output
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}