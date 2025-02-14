def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    
    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]
    
    print("Splitting:", arr)
    
    left_half = merge_sort(left_half)
    right_half = merge_sort(right_half)
    
    return merge(left_half, right_half)

def merge(left, right):
    result = []
    left_idx, right_idx = 0, 0
    
    while left_idx < len(left) and right_idx < len(right):
        if left[left_idx] < right[right_idx]:
            result.append(left[left_idx])
            left_idx += 1
        else:
            result.append(right[right_idx])
            right_idx += 1
            
    result.extend(left[left_idx:])
    result.extend(right[right_idx:])
    
    print("Merging:", left, right)
    print("Result:", result)
    
    return result

# Example usage:
arr = [64, 25, 12, 22, 11]
sorted_arr = merge_sort(arr)
print("Sorted array:", sorted_arr)