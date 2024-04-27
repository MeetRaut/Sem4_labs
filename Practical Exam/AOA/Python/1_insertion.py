import array

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# Dynamic input
n = int(input("Enter the number of elements: "))
arr = array.array('i', [0] * n)

print("Enter the elements:")
for i in range(n):
    arr[i] = int(input())

insertion_sort(arr)

print("Sorted array:")
for i in range(n):
    print(arr[i], end=" ")