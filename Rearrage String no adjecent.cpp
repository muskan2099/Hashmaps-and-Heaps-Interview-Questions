// C++ program to rearrange characters in a string 
// so that no two adjacent characters are same. 
#include<bits/stdc++.h> 
using namespace std; 
void rearrangeString(string str) 
{ 
	priority_queue<pair<int, char>> maxheap;
	unordered_map<char, int> hash;

	for(int i = 0; i < str.length(); i++){
		if(hash.count(str[i]) == 0){
			hash[str[i]] = 1;
		}
		else{
			hash[str[i]]++;
		}
	}

	unordered_map<char, int> :: iterator it;
	for(it = hash.begin(); it != hash.end(); it++){
		pair<int, char> temp = make_pair(it -> second, it -> first);

		maxheap.push(temp);
	}

	string output = "";
	pair<int, char> ignore = make_pair(1, '#');
	while(!maxheap.empty()){

		pair<int, char> temp = maxheap.top();
		maxheap.pop();
		output += temp.second;

		if(ignore.first > 0){
			maxheap.push(ignore);
		}

		temp.first = temp.first - 1;
		ignore = temp;
	}

	string ans = "";
	for(int i = 0; i < output.length() - 1; i++){
		ans+= output[i];
	}
	
	if(ans.length() != str.length()){
		cout << "NOT POSSIBLE" << endl;
		return;
	}
	else{
		cout << ans << endl;
		return;
	}
} 

// Driver program to test above function 
int main() 
{ 
	string str = "bbbaa" ; 
	rearrangeString(str); 
	return 0; 
} 
