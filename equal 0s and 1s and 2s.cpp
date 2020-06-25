#include <bits/stdc++.h> 
using namespace std; 

int getSubstringWithEqual012(string arr) 
{ 
	int n = arr.length();

	int *count1 = new int[n];
	if(arr[0] == '1'){
		count1[0] = 1;
	}
	else{
		count1[0] = 0;
	}
	for(int i = 1; i < n; i++){
		if(arr[i] == '1'){
			count1[i] = count1[i-1] + 1;
		}
		else{
			count1[i] = count1[i-1];
		}
	}
	/*for(int i = 0; i < n; i++){

		cout << count1[i] << " ";
	}
	cout << endl;*/
	int *count0 = new int[n];
	if(arr[0] == '0'){
		count0[0] = 1;
	}
	else{
		count0[0] = 0;
	}
	for(int i = 1; i < n; i++){
		if(arr[i] == '0'){
			count0[i] = count0[i-1] + 1;
		}
		else{
			count0[i] = count0[i-1];
		}
	}
	/*for(int i = 0; i < n; i++){

		cout << count0[i] << " ";
	}
	cout << endl;*/
	int *count2 = new int[n];
	if(arr[0] == '2'){
		count2[0] = 2;
	}
	else{
		count2[0] = 0;
	}
	for(int i = 1; i < n; i++){
		if(arr[i] == '2'){
			count2[i] = count2[i-1] + 1;
		}
		else{
			count2[i] = count2[i-1];
		}
	}
	/*for(int i = 0; i < n; i++){

		cout << count2[i] << " ";
	}
	cout << endl;*/

	int * diff01 = new int[n];
	for(int i = 0; i < n; i++){
		diff01[i] = count0[i] - count1[i];
	}
	int * diff02 = new int[n];
	for(int i = 0; i < n; i++){
		diff02[i] = count0[i] - count2[i];
	}
	/*for(int i = 0; i < n; i++){

		cout << diff01[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < n; i++){

		cout << diff02[i] << " ";
	}*/
	unordered_map<string, int> hash;
	hash["0*0"] = 1;

	int ans = 0;
	  for(int i = 0; i < n; i++){
        	int val1 = diff01[i];
        	int val2 = diff02[i];

        	string val = to_string(val1) + "*" + to_string(val2);

        	if(hash.count(val) != 0){
                ans += hash[val];
                hash[val]++;
            }
            if(hash.count(val) == 0){
                hash[val] = 1;
            }
        }
        return ans;
} 
int main() 
{ 
	string str = "0102010"; 
	cout << getSubstringWithEqual012(str) << endl; 
	return 0; 
} 
