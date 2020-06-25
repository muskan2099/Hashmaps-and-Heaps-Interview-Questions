#include<bits/stdc++.h> 
using namespace std; 

int findLength(int arr[], int n) 
{ 
	unordered_map<int, int> hash;
	for(int i = 0; i < n; i++){
		hash[arr[i]]++;
	}

	int maxlength = 1;
	int count = 1;
	for(int i = 0; i < n - 1; i++){
		int maxelement = arr[i];
		int minelement = arr[i];
		for(int j = i + 1; j < n; j++){

			if(hash[arr[j]] > 1){
				break;
			}
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
int main () 
{ 
	int arr[] = {10, 12, 11}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Length of the longest contiguous"
		<< " subarray is " << findLength(arr, n); 
} 
