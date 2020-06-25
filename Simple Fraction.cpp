#include <bits/stdc++.h>
using namespace std;
string changeindecimal(int n, int d){

	string q = to_string(n/d);
	n = n%d;
	//cout << n << endl;

	int numerator = n;
	int denominator = d;
	unordered_map<int, int> hash;
	string afterdecimal = "";
	int count = 0;
	while(n!= 0){
		if(hash.count(n) != 0){
			int index = hash[n];
			afterdecimal = afterdecimal.substr(0, index) + "(" + afterdecimal.substr(index) + ")";
			string finalans = q + "." + afterdecimal;
			return finalans;
		}
		hash[n] = count;
		count++;
		int quotient = (numerator*10)/denominator;
		numerator =  (numerator*10)%denominator;
		n = numerator;

		//cout << numerator << " " << count << endl;
		afterdecimal = afterdecimal + to_string(quotient);
		//cout << afterdecimal << endl;
	}
	return q + "." + afterdecimal;
}
int main(){
	int n = 500;
	int d = 22;

	cout << changeindecimal(n, d) << endl;
	return 0;
}