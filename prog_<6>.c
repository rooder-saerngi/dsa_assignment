#include <stdio.h>
void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp ;
}

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
void buildmaxheap(int arr[], int n){
    for (int i = ((n /2) -1);i >=0 ; i --){
        maxheap(arr, n, i);
    }
}
void buildminheap(int arr[],int n){
    for (int i = ((n/2)-1);i>=0;i--){
        minheap(arr,n,i);
    }
}
void printarr(int arr[],int n){
    for (int i = 0 ;i < n;++i){
        printf("%d",arr[i]);
    }printf("\n");
}

int main(){

    int array[]={1,4,2,66,7,8,90,9};
    int n = sizeof(array)/sizeof(array[0]);

    int maxArray[n], minArray[n];
    for (int i = 0; i< n ;i++ ){
        maxArray[i]= array[i];
        minArray[i]= array[i];
 
    }
    buildmaxheap(maxArray,n);
    printf("Max-Heap array: ");
    printarr(maxArray,n);

    buildminheap(minArray,n);
    printf("Min-Heap array: ");
    printarr(minArray,n);

    return 0;


}


