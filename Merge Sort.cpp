//   Merge sort

#include <bits/stdc++.h>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> ans;
    int right = mid+1;
    int left = low;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            ans.push_back(arr[left]);
            left++;
        }
        else{
            ans.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        ans.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        ans.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i] = ans[i-low];
    }
}

void mergesort(vector<int> &arr, int low, int high){
    if(low >= high)
        return;
    int mid = (low+high)/2;
    mergesort(arr, low, mid);
    mergesort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main(){
    vector<int> arr = {57,64,2,55,478,32,10,97,-98,88};
    mergesort(arr, 0, arr.size()-1);
    for(auto i:arr)
        cout<<i<<" ";
    
    return 0;
}
