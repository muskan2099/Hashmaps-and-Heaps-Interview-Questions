class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	bool tempprimes[200];
        vector<int> primes;

        for(int i = 0; i < 200; i++){
            tempprimes[i] = 1;
        }
		tempprimes[0] = 0;
		tempprimes[1] = 0;

		for(int i = 2; i <= sqrt(n); i++){
			if(tempprimes[i] == 1){
				for(int j = i; j *i <= sqrt(n); j++){
					tempprimes[i*j] = 0;
				}
			}
		}
        int count = 0;
        int i = 0;
        while(count < 26){
            if(tempprimes[i] == 0){
                i++;
            }
            else{
                primes.push_back(i);
                i++;
                count++;
            }
        }
        
        unordered_map<long, vector<string>> hash;

        for(int i = 0; i < strs.size(); i++){
        	long product = 1;
        	for(int j = 0; j < strs[i].length(); j++){
        		product = product * primes[strs[i][j] - 'a'];
        	}
        	if(hash.count(product) != 0){
        		hash[product].push_back(strs[i]);
        	}
        	else{
        		vector<string> temp;
        		hash[product] = temp;
        	}
        }

        vector<vector<string>> output(hash.size());
        int count = 0;
        unordered_map<long, vector<string>> :: iterator it;
        for(it = hash.begin(); it != hash.end(); it++){
        	output[count] = it -> second;
        	count++;
        }
        return output;
    }
};