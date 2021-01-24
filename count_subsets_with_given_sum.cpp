#include<iostream>

using namespace std;

int count_subsets(int* a , int n , int s){
	int t[n+1][s+1];
	for(int i = 0;i<n+1;i++){
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
	int arr[] = {2,3,5,6,8,10};
	int s = 10 , l = sizeof(arr)/sizeof(arr[0]);
	int ans = count_subsets(arr,l,s);
	cout<<ans;
}
