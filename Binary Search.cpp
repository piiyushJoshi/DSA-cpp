
// Binary Search in a rotated sorted array.

#include <bits/stdc++.h>

using namespace std;

int pivot_index(vector<int> arr){
    int start = 0,end = arr.size()-1;
    while(start<end){
        int mid = start + (end-start)/2;
        if(arr[mid] > arr[arr.size()-1])
            start = mid+1;
        else
            end = mid;
    }
    return start;
}

int b_search(vector<int> arr,int start,int end,int key){
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == key)
            return mid;

        if(key>arr[mid])
            start = mid+1;
        else
            end = mid-1;

    }
    return -1;
}

int b_rotated(){
    vector<int> arr{7,8,9,0,2,3,5};
    int key;
    cout<<"Enter the key: ";
    cin>>key;
    int pivot = pivot_index(arr);
    if(pivot == 0)
        return b_search(arr,0,arr.size()-1,key);
    if(key > arr[pivot] && key >= arr[0])
        return b_search(arr,0,pivot-1,key);
    else if(key>=arr[pivot] && key<=arr[arr.size()-1])
        return b_search(arr,pivot,arr.size()-1,key);
    else
        return -1;

}

int main(){
        cout<<b_rotated();
    return 0;
}
