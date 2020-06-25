class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();        
        unordered_map<int, int> hash;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < wall[i].size() - 1; j++){
                sum = sum + wall[i][j];
                
                if(hash.count(sum) == 0){
                    hash[sum] = 1;
                }
                else{
                    hash[sum]++;
                }
                ans = max(ans, hash[sum]);
            }
        }
        if(ans == INT_MIN){
            return n;
        }
        else{
            return n - ans;
        }
    }
};