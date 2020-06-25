class Solution {
public:
	int helper(int a, int b){

		if(a == 0){
			return b;
		}

		return helper(b%a, a);
	}
	int gcd(vector<int> input){

		int n = input.size();
		int res = input[0];

		for(int i = 1; i < n; i++){
			res = helper(input[i], res);

			if(res == 1){
				return 1;
			}
		}
		return res;
	}
    bool hasGroupsSizeX(vector<int>& deck) {
        int n = deck.size();
        unordered_map<int, int> hash;
        vector<int> freq;

        for(int i = 0; i < n; i++){
        	if(hash.count(deck[i])  == 0){
        		hash[deck[i]] = 1;
        	}
        	else{
        		hash[deck[i]]++;
        	}
        }
        unordered_map<int, int> :: iterator it;
        for(it = hash.begin(); it != hash.end(); it++){
        	freq.push_back(it -> second);
        }

        int gcdoffreq = gcd(freq);

        if(gcdoffreq >= 2){
        	return true;
        }
        else{
        	return false;
        }
    }
};