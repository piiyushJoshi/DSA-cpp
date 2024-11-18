                        /**Sorting Algorithms**/

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

void printarray(int arr[], int size);
void insertionsort(int arr[], int size);
void selectionsort(int arr[], int size);
void bubblesort(int arr[], int size);
void radixsort(int arr[], int size);
void countingsort(int arr[], int size);
void merge(int arr[],int mid,int low,int high);
void mergesort(int arr[],int low,int high);
void countSort(int arr[], int size, int pos){
    int output[size+1],i;
    int *count = (int *)calloc(10,sizeof(int));
    
    for(i=0;i<size;i++){
        count[(arr[i]/pos)%10]++;
    }
    for(i=0;i<10;i++){
        count[i] += count[i-1];
    }
    for(i=size-1;i>=0;i--){
        output[count[(arr[i]/pos)%10]-1] = arr[i];
        count[(arr[i]/pos)%10]--;
    }
    for(i=0;i<size;i++){
        arr[i] = output[i];
    }
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int maximum(int arr[], int size){
    int i,max;
    max = arr[0];
    for(i=1;i<size;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int arr[MAX_SIZE], i, size,choice;
    printf("Enter the size of the array: \n");
    scanf("%d", &size);
    for(i=0;i<size;i++){
        printf("Enter the %d element: \n", i+1);
        scanf("%d", &arr[i]);
    }
    printf("Enter '1' for insertion sort: \nEnter '2' for selection sort: \nEnter '3' for bubble sort: \n");
    printf("Enter '4' for counting sort: \nEnter '5' for radix sort: \nEnter '6' for merge sort: \n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
        insertionsort(arr,size);
        break;
        case 2:
        selectionsort(arr,size);
        break;
        case 3:
        bubblesort(arr,size);
        break;
        case 4:
        countingsort(arr,size);
        break;
        case 5:
        radixsort(arr,size);
        break;
        case 6:
        mergesort(arr,0,size-1);
        break;
    }
    printarray(arr,size);
    return 0;
}

void printarray(int arr[], int size){
    int i;
    printf("Array after sorting is : \n");
    for(i=0;i<size;i++){
        printf("%d  ", arr[i]);
    }
}

void insertionsort(int arr[], int size){
    int i,j,key;
    for(i=0;i<size;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionsort(int arr[], int size){
    int i,j,min_index,temp;
    for(i=0;i<size-1;i++){
        min_index = i;
        for(j=i+1;j<size;j++){
            if(arr[min_index]>arr[j]){
                min_index = j;
            }
        }
        swap(&arr[min_index],&arr[i]);
    }
}

void bubblesort(int arr[], int size){
    int i,j;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void countingsort(int arr[], int size){
    int i,j,max;
    max = maximum(arr,size);
    int *count = (int *)calloc((max+1),sizeof(int));
    for(i=0;i<size;i++){
        count[arr[i]]++;
    }
    i=0;j=0;
    while(i<=max){
        if(count[i]>0){
        arr[j] = i;
        count[i]--;
        j++;
        }
        else{
            i++;
        }
    }
}

void radixsort(int arr[], int size){
    int pos;
    int max = maximum(arr, size);
    for(pos=1;(max/pos)>0;pos*=10){
        countSort(arr,size,pos);
    }
}

void merge(int arr[], int beg, int mid, int end){    
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int LeftArray[n1], RightArray[n2];
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = arr[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = arr[mid + 1 + j];
    i = 0,
    j = 0;
    k = beg;
    while (i < n1 && j < n2){    
        if(LeftArray[i] <= RightArray[j]){    
            arr[k] = LeftArray[i];    
            i++;    
        }    
        else{    
            arr[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1){    
        arr[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
    while (j<n2){    
        arr[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    

void mergesort(int arr[], int beg, int end){  
    if (beg < end){  
        int mid = (beg + end) / 2;  
        mergesort(arr, beg, mid);  
        mergesort(arr, mid + 1, end);  
        merge(arr, beg, mid, end);  
    }  
}  
