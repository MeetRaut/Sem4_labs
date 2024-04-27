// Merge sort 
#include<stdio.h>

// Function to merge two sorted arrays
void merge(int a[], int mid, int low, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int leftarr[20], rightarr[20];

    // Copy data to temp arrays
    for (i = 0; i < n1; i++)
        leftarr[i] = a[low + i];
    for (j = 0; j < n2; j++)
        rightarr[j] = a[mid + 1 + j];

    // Merge the temp arrays back into a single sorted array
    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2) {
        if (leftarr[i] <= rightarr[j]) {
            a[k] = leftarr[i];
            i++;
        }
        else {
            a[k] = rightarr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftarr, if any
    while (i < n1) {
        a[k] = leftarr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightarr, if any
    while (j < n2) {
        a[k] = rightarr[j];
        j++;
        k++;
    }
}

// Function to perform mergesort
void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        
        // Recursive calls for left and right halves
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);

        // Merge the sorted halves
        merge(a, mid, low, high);
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

    // Calling mergesort function to sort the array
    mergesort(arr, 0, n - 1);

    // Output: Displaying the sorted array
    // Output
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}