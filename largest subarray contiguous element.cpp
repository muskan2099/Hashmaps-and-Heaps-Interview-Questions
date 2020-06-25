#include<bits/stdc++.h> 
using namespace std; 

int findLength(int arr[], int n) 
{
	int maxlength = 1;
	int count = 1;
	for(int i = 0; i < n - 1; i++){
		int maxelement = arr[i];
		int minelement = arr[i];
		for(int j = i + 1; j < n; j++){
			if(arr[j] > maxelement){
				maxelement = arr[j];
			}
			if(minelement > arr[j]){
				minelement = arr[j];
			}

			if(maxelement - minelement + 1 == j - i + 1){
				count = j - i + 1;
				if(count > maxlength){
					maxlength = count;
				}
			}
		}
	}
	return maxlength;
} 
int main() 
{ 
	int arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Length of the longest contiguous subarray is "
		<< findLength(arr, n); 
	return 0; 
} 
