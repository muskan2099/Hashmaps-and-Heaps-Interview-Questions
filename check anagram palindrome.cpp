#include <bits/stdc++.h>
using namespace std;

bool tell(string str){

	unordered_map<char, int> hash;
	for(int i = 0; i < str.length(); i++){
		if(hash.count(str[i]) == 0){
			hash[str[i]] = 1;
		}
		else{
			hash[str[i]]++;
		}
	}
	//unordered_map<int, int> freq;
	unordered_map<char, int> :: iterator it;
	int even = 0;
	int odd = 0;
	for(it = hash.begin(); it != hash.end(); it++){

		if(it->second%2 == 0){
			even++;
		}
		else{
			odd++;
		}
	}
	if(odd == 0){
		return true;
	}
	else if(odd == 1){
		return true;
	}
	else{
		return false;
	}
}
int main(){

	string input = "geeksfgeeks";

	cout << tell(input) << endl;
	return 0;

}