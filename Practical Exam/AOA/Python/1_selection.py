import array

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i+1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

# Dynamic input
n = int(input("Enter the number of elements: "))
arr = array.array('i', [0] * n)

print("Enter the elements:")
for i in range(n):
    arr[i] = int(input())

selection_sort(arr)

print("Sorted array:")
for i in range(n):
    print(arr[i], end=" ")