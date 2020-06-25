class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hash;
        int maxlength = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            
            
            cout << nums[i] << " ->" << maxlength << endl;
            if(hash.count(nums[i]) != 0){
                continue;
            }
        	int less = nums[i] - 1;
        	int more = nums[i] + 1;

        	if(hash.count(less) == 0 && hash.count(more) == 0){
        		hash[nums[i]] = 1;

        		maxlength = max(maxlength, 1);
                
        	}
        	else if(hash.count(less) != 0 && hash.count(more) == 0){
        		int endpoint = nums[i];
        		int startpoint = nums[i] - hash[less];

        		hash[nums[i]] = hash[less] + 1;
        		hash[startpoint] = hash[nums[i]];

        		maxlength = max(maxlength, hash[nums[i]]);
                
        	}
        	else if(hash.count(less) == 0 && hash.count(more) != 0){
        		int startpoint = nums[i];
        		int endpoint = nums[i] + hash[more];

        		hash[nums[i]] = hash[more] + 1;
        		hash[endpoint] = hash[nums[i]];

        		maxlength = max(maxlength, hash[nums[i]]);
                
        	}
        	else if(hash.count(less) != 0 && hash.count(more) != 0){
        		int endpoint = nums[i] + hash[more];
        		int startpoint = nums[i] - hash[less];
                if(nums[i] == -3){
                    cout << startpoint << "," << endpoint;
                }

        		hash[endpoint] = endpoint - startpoint + 1;
        		hash[startpoint] = endpoint - startpoint + 1; 
                hash[nums[i]] = 1;
        		maxlength = max(maxlength, endpoint - startpoint + 1);
                
        	}
        }
        if(maxlength == INT_MIN){
            return 0;
        }
        return maxlength;
    }
};