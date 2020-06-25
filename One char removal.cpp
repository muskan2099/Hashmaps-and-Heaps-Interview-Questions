// C++ program to get same frequency character 
// string by removal of at most one char 
#include <bits/stdc++.h> 
using namespace std; 
#define M 26 

bool possibleSameCharFreqByOneRemoval(string str) 
{ 
	unordered_map<char, int> hash;
	for(int i = 0; i < str.length(); i++){
		if(hash.count(str[i]) == 0){
			hash[str[i]] = 1;
		}
		else{
			hash[str[i]]++;
		}
	}
	unordered_map<int, int> freq;
	unordered_map<char, int> :: iterator it;
	for(it = hash.begin(); it != hash.end(); it++){

		freq[it -> second] ++;
		//cout << it-> second << endl;
	}
	if(freq.size() == 1){
		return true;
	}
	else if(freq.size() == 2){
		unordered_map<int, int> :: iterator it1 = freq.begin();
		int a = it1 -> first;
		it1++;
		int b = it1 -> first;

		if(a != 1 && b == 1){
			return true;
		}
		else if(a == 1 && b != 1){
			return true;
		}
		else if(abs(a - b) == 1){
			return true;
		}
	}
	return false;
} 

// Driver code to test above methods 
int main() 
{ 
	string str = "xxyyyyyzz"; 
	if (possibleSameCharFreqByOneRemoval(str)) 
		cout << "Yes"; 
	else
		cout << "No"; 
} 
