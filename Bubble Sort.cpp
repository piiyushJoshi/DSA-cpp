//  Bubble sort

#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
    vector<int> arr = {5,97,2,4,5,3,7,2,1,0,-98};
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}
