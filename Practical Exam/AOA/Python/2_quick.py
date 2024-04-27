import array

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

# Example usage:
arr = array.array('i', [12, 4, 5, 6, 7, 3, 1, 15])
sorted_arr = quick_sort(arr)
print(sorted_arr)