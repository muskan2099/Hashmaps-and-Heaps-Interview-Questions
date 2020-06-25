#include<bits/stdc++.h> 
using namespace std; 

bool checkIsAP(int arr[], int n) 
{ 
	int first = INT_MAX;
	int second = INT_MAX;

	unordered_set<int> heap;
	for(int i = 0; i < n; i++){

		heap.insert(arr[i]);
		if(arr[i] < first){
			second = first;
			first = arr[i];
			
		}
	}

	cout << first << " " << second;

	int diff = second - first;
	int a = first;
	int num = 1;

	while(heap.size() != 0){

		int val = a + (num - 1)*diff;
		if(heap.find(val) != heap.end()){
			heap.erase(val);
			num++;
		}
		else{
			return false;
		}
	}
	return true;
} 

int main() 
{ 
int arr[] = { 20, 15, 5, 0, 10 }; 
int n = sizeof(arr)/sizeof(arr[0]); 

(checkIsAP(arr, n))? (cout << "Yes" << endl) : 
					(cout << "No" << endl); 

return 0; 
} 
