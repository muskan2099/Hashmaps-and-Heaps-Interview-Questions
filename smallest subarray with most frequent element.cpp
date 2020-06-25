#include <bits/stdc++.h> 
using namespace std; 
class data{
public:
	int freq;
	int start;
	int end;

	data(int n, int s, int e){
		freq = n;
		start = s;
		end = e;
	}
};
void smallestSubsegment(int input[], int n) 
{ 
	unordered_map<int, data> hash;
	for(int i = 0; i < n; i++){
		if(hash.count(input[i]) == 0){
			data d(1, i, i);
			hash[input[i]] = d;
		}
		else{
			hash[input[i]].freq++;
			hash[input[i]].end = i;
		}
	}

	unordered_map<int, data> :: iterator it;
	int maxfreq = INT_MIN;
	int minlength = INT_MAX;
	pair<int, int> ans;
	for(it = hash.begin(); it !_ hash.end(); it++){

		if((it -> second).freq > maxfreq){
			maxfreq = (it -> second).freq;
			minlength = (it -> second).end - (it -> second).start + 1;
			ans.first = (it -> second).start;
			ans.second = (it -> second).end;
		}
		else if((it -> second).freq == maxfreq){
			if(minlength > (it -> second).end - (it -> second).start + 1){
				minlength = (it -> second).end - (it -> second).start + 1;

				ans.first = (it -> second).start;
				ans.second = (it -> second).end;
			}
		}
	}

	for(int i = ans.first; i <= ans.second; i++){
		cout << input[i] << " ";
	}
} 
 
int main() 
{ 
	int A[] = { 1, 2, 2, 2, 1 }; 
	int n = sizeof(A) / sizeof(A[0]); 
	smallestSubsegment(A, n); 
	return 0; 
} 
