
### Bubble Sort

This algorithm steps through the list repeatedly and compares adjacent elements. If the left element is larger than the right, they are swapped. This process continues until the largest values "bubble up" to their correct positions at the end of the list.

----------

### Selection Sort

The list is divided into a sorted and an unsorted section. The algorithm searches the entire unsorted part to find the smallest number, then swaps it with the first element of that section. This "selects" the correct item for each position one by one.

----------

### Insertion Sort

This method mimics how a person might sort a hand of playing cards. It takes one element from the unsorted section and slides it backward through the sorted section until it finds its correct spot, shifting other elements out of the way to make room.

----------

### Merge Sort

This is a "divide and conquer" algorithm. It recursively splits the list into halves until each sub-list contains only one element. Then, it merges those sub-lists back together in the correct order, ensuring the final combined list is fully sorted.

----------

### Main Execution Logic

The main block handles the user interaction by gathering the list size and the desired algorithm choice. It generates the random data, creates a copy to preserve the original state, and triggers the specific function. Finally, it reports the sorted results and the mechanical effort (comparisons and swaps) used to get there.
