import array

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i+1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

def dynamic_input():
    n = int(input("Enter the number of elements: "))
    arr = array.array('i', [0] * n)
    print("Enter the elements:")
    for i in range(n):
        arr[i] = int(input())
    return arr

def main():
    arr = dynamic_input()

    print("Select sorting algorithm:")
    print("1. Insertion Sort")
    print("2. Selection Sort")
    choice = int(input("Enter your choice (1 or 2): "))

    if choice == 1:
        insertion_sort(arr)
    elif choice == 2:
        selection_sort(arr)
    else:
        print("Invalid choice")

    if choice in [1, 2]:
        print("Sorted array:")
        for num in arr:
            print(num, end=" ")

if __name__ == "__main__":
    main()