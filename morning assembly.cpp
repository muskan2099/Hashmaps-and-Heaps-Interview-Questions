#include <bits/stdc++.h>
using namespace std;
int morningassembly(int *input, int n){

	int maxlen = INT_MIN;
	unordered_map<int, int> hash;
	for(int i = 0; i < n; i++){
		if(hash.count(input[i] - 1) == 0){
			hash[input[i]] = 1;
		}
		else{
			int length = hash[input[i] - 1] + 1;
			hash[input[i]] = length;
			maxlen = max(maxlen, length);
		}
	}
	return n - maxlen;
}
int main() {
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		int *input = new int[n];
		for(int i = 0; i < n; i++){

			cin >> input[i];
		}

		cout << morningassembly(input, n) << endl;
	}
	return 0;
}