//  Insertion sort

#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
    vector<int> arr = {5,97,2,4,5,3,7,2,1,0,-98};
    int n = arr.size();
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j] < arr[j-1]){
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}
