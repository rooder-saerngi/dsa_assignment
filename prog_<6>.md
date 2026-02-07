#***Given the array of the data (unsorted), Write a program to build the min and max heap.***

* -> to build a heap from an undorted array , the process if ***Heapify*** is used
* -> instead of inserting the elements one by one , we start from the last non leaf noade and work our way up to the root, sinking the elements into their correct positions.

#**Main Logic**
* the last non leaf node is calulated as floor(n/2)-1, All nodes after this are leaves and already satisfy the heap property
* in a Max heap the parent node must be greater than or equal to its children
  ```
  void maxheap(int arr[], int n , int i ){
    int largest = i ;
    int left = (i*2) +1;
    int right = (i*2)+2;

    if (left < n && arr[left]>arr[largest]){
        largest = left ;
    }
    if(right <n && arr[right]> arr[largest]){
        largest = right ;

    }
    if (largest != i ){
        swap (&arr[i], &arr[largest]);
        maxheap(arr,n,largest);
    }
  }

  ```
* in Min heap the parent nose must be lesser or equal to its children
  ```
  void minheap(int arr[], int n , int i ){
    int smallest = i;
    int left = (i*2) +1;
    int right = (i*2)+2;

    if (left < n && arr[left]<arr[smallest]){
        smallest = left ;
    }
    if (right < n && arr[right]<arr[smallest]){
        smallest = right ;
    }
    if (smallest != i){
        swap(&arr[i], &arr[smallest]);
        minheap(arr,n,smallest);
    }
  }
  ```

