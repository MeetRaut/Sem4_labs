#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x){
    while (l <= r){
        int m = l + (r - l) / 2;

        if (arr[m] == x){
            return m;
        }

        if (arr[m] < x){
            l = m + 1;
        }else{
            r = m - 1;
        }
            
    }
    return -1;
}

int main(void){
    int arr[100];
    int n, i, x;

    printf("Enter the number of elements of the array:");
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        printf("Enter the elements in the %d position : ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter element to be searched in the array:");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1){
        printf("Element not found!");
    }else{
        printf("Element is present at index %d", result);
    }

    return 0;
}