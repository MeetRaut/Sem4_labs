import array

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        less_than_pivot = array.array('i', [])
        greater_than_pivot = array.array('i', [])
        for element in arr[1:]:
            if element <= pivot:
                less_than_pivot.append(element)
            else:
                greater_than_pivot.append(element)
        
        return quick_sort(less_than_pivot) + array.array('i', [pivot]) + quick_sort(greater_than_pivot)

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
    print("1. Merge Sort")
    print("2. Quick Sort")
    choice = int(input("Enter your choice (1 or 2): "))

    if choice == 1:
        merge_sort(arr)
    elif choice == 2:
        quick_sort(arr)
    else:
        print("Invalid choice")

    if choice in [1, 2]:
        print("Sorted array:")
        for num in arr:
            print(num, end=" ")

if __name__ == "__main__":
    main()