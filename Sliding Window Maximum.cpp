class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        int *maxleft = new int[n];
        maxleft[0] = nums[0];
        for(int i = 1; i < n; i++){

        	if(i%k == 0){
        		maxleft[i] = nums[i];
        	}
        	else{
        		maxleft[i] = max(maxleft[i - 1], nums[i]);
        	}
        }
        int *maxright = new int[n];
        maxright[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){

        	if((i+1)%k == 0){
        		maxright[i] = nums[i];
        	}
        	else{
        		maxright[i] = max(maxright[i + 1], nums[i]);
        	}
        }

        vector<int> output(n - k + 1);
        for(int i = 0; i < n - k + 1; i++){

        	if(i%k == 0){
        		output[i] = maxright[i];
        	}
        	else{
        		output[i] = max(maxleft[i + k - 1], maxright[i]);
        	}
        }
        return output;
    }
};