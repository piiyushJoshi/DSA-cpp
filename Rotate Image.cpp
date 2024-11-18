#include <bits/stdc++.h>

using namespace std;

void swap(int *a,int *b){
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
}

int main(){
    vector<vector<int>> image{{3,6,9},{2,5,8},{1,4,7}};
    int m = image.size();
    int n = image[0].size();
    for(int i=0;i<m/2;i++)
        for(int j=0;j<n;j++)
            swap(&image[i][j],&image[(image.size()-1)-i][j]);
    
    for(int i=0;i<m;i++)
        for(int j=i;j<n;j++){
            if(i==j)
                continue;
            swap(&image[i][j],&image[j][i]);
        }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<image[i][j]<<" ";
        
        cout<<"\n";
    }
}
