// C++ program to check if two strings are k anagram 
// or not. 
#include<bits/stdc++.h> 
using namespace std; 
const int MAX_CHAR = 26; 

// Function to check that string is k-anagram or not 
bool arekAnagrams(string s1, string s2, int k) 
{ 
	if(s1.length() != s2.length()){
		return false;
	}
	int ans = 0;

	unordered_map<char, int> hash1;
	unordered_map<char, int> hash2;

	for(int i = 0; i < s1.length(); i++){

		hash1[s1[i]]++;
		hash2[s2[i]]++;
	}

	//cout << hash2.size() << endl;
	unordered_map<char, int> :: iterator it;

	for(it = hash1.begin(); it != hash1.end(); it++){

		if(hash2.count(it -> first) == 0){
			ans += it -> second;
		}
		else if(hash2.count(it -> first) != 0){

			if(it -> second > hash2[it -> first]){
				ans += it -> second - hash2[it -> first];
			}
		}
	}
	cout << ans << endl;
	if(ans == k){
		return true;
	}
	else{
		return false;
	}
} 

int main() 
{ 
	string str1 = "geeks"; 
	string str2 = "eggkf"; 
	int k = 1; 
	if (arekAnagrams(str1, str2, k)) 
		cout << "Yes"; 
	else
		cout<< "No"; 
	return 0; 
} 
