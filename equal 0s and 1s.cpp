#include <bits/stdc++.h> 

using namespace std; 
int countSubarrWithEqualZeroAndOne(int arr[], int n) 
{
	int *count1 = new int[n];
	if(arr[0] == 1){
		count1[0] = 1;
	}
	else{
		count1[0] = 0;
	}
	for(int i = 1; i < n; i++){
		if(arr[i] == 1){
			count1[i] = count1[i-1] + 1;
		}
		else{
			count1[i] = count1[i-1];
		}
	}
	int *count0 = new int[n];
	if(arr[0] == 0){
		count0[0] = 1;
	}
	else{
		count0[0] = 0;
	}
	for(int i = 1; i < n; i++){
		if(arr[i] == 0){
			count0[i] = count0[i-1] + 1;
		}
		else{
			count0[i] = count0[i-1];
		}
	}
	int * diff = new int[n];
	for(int i = 0; i < n; i++){
		diff[i] = count0[i] - count1[i];
	}
	unordered_map<int, int> hash;
	hash[0] = 1;

	int ans = 0;
        for(int i = 0; i < n; i++){
        	int val = diff[i];
        	if(hash.count(val) != 0){
                ans += hash[val];
            }
            if(hash.count(diff[i]) == 0){
                hash[diff[i]] = 1;
            }
            else{
                hash[diff[i]]++;
            }
        }
        return ans;
} 
int main() 
{ 
	int arr[] = { 1, 0, 0, 1, 0, 1, 1 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Count = "
		<< countSubarrWithEqualZeroAndOne(arr, n); 
	return 0; 
} 
