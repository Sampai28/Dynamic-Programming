#include<iostream>
#include<stdio.h>

using namespace std;

bool equal_sum(int* a , int n , int s){
	bool t[n+1][s+1];
	for(int i = 0;i<n+1;i++){
		for(int j = 0;j<s+1;j++){
			if(i==0){
				t[i][j] = false;
			}
			if(j==0){
				t[i][j] = true;
			}
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<s+1;j++){
			if(a[i-1]<=j){
				t[i][j] = t[i-1][j] || t[i-1][j-a[i-1]];
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][s];
}
int main(){
	int arr[] = {1,5,11,5};
	int s = 0 , l = sizeof(arr)/sizeof(arr[0]);
	for(int i = 0;i<l;i++){
		s+=arr[i];
	}
	if(s%2!=0){
		printf("No!");
	}
	else{
		if(equal_sum(arr,l,s/2)){
			printf("Yes!");
		}
		else{
			printf("No!");
		}
	}
}
