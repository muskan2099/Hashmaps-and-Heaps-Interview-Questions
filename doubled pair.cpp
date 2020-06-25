class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {

        sort(A.begin(), A.end());
        unordered_map<int, int> hash;
        for(int i = 0; i < A.size(); i++){
        	if(hash.count(A[i]) == 0){
        		hash[A[i]] = 1;
        	}
        	else{
        		hash[A[i]]++;
        	}
        }

        for(int i = 0; i < A.size(); i++){
        	int element = A[i];
        	if(hash[element] == 0){
        		continue;
        	}
        	if(element < 0){
        		int val = element/2;
        		if(hash[val] >= 1){
        			if(hash[element] > hash[val]){
        				return false;
        			}
        			hash[val]--;
        			hash[element]--;
        		}
                else{
                    return false;
                }
        	}
        	else{
        		int val = element*2;
        		if(hash[val] >= 1){
        			if(hash[element] > hash[val]){
        				return false;
        			}
        			hash[val]--;
        			hash[element]--;
        		}
                else{
                    return false;
                }
        	}
        }
        return true;
    }
};