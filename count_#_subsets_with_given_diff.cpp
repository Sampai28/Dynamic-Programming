#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int count(int* a, int s, int n){
    int t[n+1][s+1];
    for(int i = 0 ;i<n+1;i++){
        for(int j = 0;j<s+1;j++){
            if(i==0){
                t[i][j] = 0;
            }
            if(j==0){
                t[i][j] = 1;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<s+1;j++){
            if(a[i-1]<=j){
                t[i][j] = t[i-1][j] + t[i-1][j-a[i-1]];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][s];

}
int main(){
    int arr[] = {1,1,2,3};
    int r = 0, n = sizeof(arr)/sizeof(arr[0]);
    int diff = 1;
    for(int i = 0;i<n;i++){
        r+=arr[i];
    }
    int target = diff + r;
    cout<<count(arr,target/2,n);
}
