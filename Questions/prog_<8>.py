import random

def bubble_sort(arr):
    comparisons = 0
    swaps = 0
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            comparisons += 1
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swaps += 1
    return comparisons, swaps

def selection_sort(arr):
    comparisons = 0
    swaps = 0
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            comparisons += 1
            if arr[j] < arr[min_idx]:
                min_idx = j
        if min_idx != i:
            arr[i], arr[min_idx] = arr[min_idx], arr[i]
            swaps += 1
    return comparisons, swaps

def insertion_sort(arr):
    comparisons = 0
    swaps = 0
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0:
            comparisons += 1
            if arr[j] > key:
                arr[j + 1] = arr[j]
                swaps += 1
                j -= 1
            else:
                break
        arr[j + 1] = key
    return comparisons, swaps

def merge_sort(arr):
    comp_count = [0]
    
    def sort(data):
        if len(data) <= 1:
            return data
        
        mid = len(data) // 2
        left = sort(data[:mid])
        right = sort(data[mid:])
        
        merged = []
        i = j = 0
        while i < len(left) and j < len(right):
            comp_count[0] += 1
            if left[i] < right[j]:
                merged.append(left[i])
                i += 1
            else:
                merged.append(right[j])
                j += 1
        merged.extend(left[i:])
        merged.extend(right[j:])
        return merged

    sorted_arr = sort(arr)
    return sorted_arr, comp_count[0]

def main():
    n = int(input("Enter the number of integers (N): "))
    original_list = [random.randint(1, 1000) for _ in range(n)]
    
    print("\n--- Choose a Sorting Algorithm ---")
    print("1. Bubble Sort")
    print("2. Selection Sort")
    print("3. Insertion Sort")
    print("4. Merge Sort")
    choice = input("Enter your choice (1-4): ")

    arr = original_list.copy()
    print(f"\nBefore sorting: {arr}")

    comparisons = 0
    swaps = "N/A"

    if choice == '1':
        comparisons, swaps = bubble_sort(arr)
    elif choice == '2':
        comparisons, swaps = selection_sort(arr)
    elif choice == '3':
        comparisons, swaps = insertion_sort(arr)
    elif choice == '4':
        arr, comparisons = merge_sort(arr)
    else:
        print("Invalid selection.")
        return

    print(f"After sorting:  {arr}")
    print(f"\n--- meetrics ---")
    print(f"Total Comparisons: {comparisons}")
    print(f"Total Swaps: {swaps}")

if __name__ == "__main__":
    main()
