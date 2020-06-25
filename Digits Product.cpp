#include<bits/stdc++.h> 
using namespace std; 

#define MAX 50 

int findSmallest(int n) 
{ 
	vector<int> res;

	if(n < 10){
		return n + 10; 
	}
	for(int i = 9; i > 1; i--){

		while(n%i == 0){
			n = n/i;
			res.push_back(i);
		}
	}
	if(n > 10){
		return -1;
	}
	int ans = 0;

	for(int i = res.size() - 1; i >= 0; i--){
		ans = ans * 10 + res[i];
	}
	return ans;
} 

// Driver Code 
int main() 
{ 
	cout << findSmallest(7) << endl; 

	cout << findSmallest(36) << endl; 

	cout << findSmallest(13) << endl; 

	cout << findSmallest(100) << endl; 
	return 0; 
} 