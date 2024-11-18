//  Selection sort

#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
    vector<int> arr = {5,97,2,4,5,3,7,2,1,0,-98};
    for(int i=0;i<arr.size()-1;i++){
        int min_index = i;
        for(int j=i;j<arr.size();j++)
            if(arr[j] < arr[min_index])
                min_index = j;
        swap(arr[i], arr[min_index]);
    }
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";

    return 0;
}
