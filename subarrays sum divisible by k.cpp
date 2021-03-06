class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int *prefixsum = new int[nums.size()];
        prefixsum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
         	prefixsum[i] = prefixsum[i-1] + nums[i];
        }
        for(int i= 0; i < nums.size(); i++){
        	prefixsum[i] = prefixsum[i]%k;
        	if(prefixsum[i] < 0){
        		prefixsum[i] = prefixsum[i] + k;
        	}
        }

        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
        	int val = prefixsum[i];
        	if(hash.count(val) != 0){
                ans += hash[val];
            }
            if(hash.count(prefixsum[i]) == 0){
                hash[prefixsum[i]] = 1;
            }
            else{
                hash[prefixsum[i]]++;
            }
        }
        return ans;

    }
};