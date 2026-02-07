#***Given the array of the data (unsorted), Write a program to build the min and max heap.***

* -> to build a heap from an undorted array , the process if ***Heapify*** is used
* -> instead of inserting the elements one by one , we start from the last non leaf noade and work our way up to the root, sinking the elements into their correct positions.

#**Main Logic**
* the last non leaf node is calulated as floor(n/2)-1, All nodes after this are leaves and already satisfy the heap property
* in a Max heap the parent node must be greater than or equal to its children
* in Min heap the parent nose must ve lesser or equal to its children

