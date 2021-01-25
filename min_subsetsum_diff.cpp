#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int min_subsetsum_diff(int* a, int r, int n){
    bool t[n+1][r+1];
    for(int i = 0 ;i<n+1;i++){
        for(int j = 0;j<r+1;j++){
            if(i==0){
                t[i][j] = false;
            }
            if(j==0){
                t[i][j] = true;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<r+1;j++){
            if(a[i-1]<=j){
                t[i][j] = t[i-1][j] || t[i-1][j-a[i-1]];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    vector<int> v;
    for(int i = 0;i<r+1;i++){
        if(t[n][i]){
            v.push_back(i);
        }
    }
    int mn = INT_MAX;
    for (int i = 0;i<v.size()/2;i++){
        mn = std::min(mn,r - 2*v[i]);
    }
    return mn;

}
int main(){
    int arr[] = {3, 1, 4, 2, 2, 1};
    int r = 0, n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i<n;i++){
        r+=arr[i];
    }
    cout<<min_subsetsum_diff(arr,r,n);
}
