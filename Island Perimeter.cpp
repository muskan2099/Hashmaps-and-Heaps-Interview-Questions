class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                
                if(grid[i][j] == 1){
                    
                    int count = 4;
                
                    if(i > 0 && grid[i - 1][j] == 1){
                        count--;
                    }
                    if(i < grid.size() - 1 && grid[i + 1][j] == 1){
                        count--;
                    }
                    if(j > 0 && grid[i][j - 1] == 1){
                        count--;
                    }
                    if(j < grid[i].size() -1 && grid[i][j + 1] == 1){
                        count--;
                    }

                    perimeter += count;
                   // cout << count << endl;
                }
                else{
                    continue;
                }
            }
        }
        return perimeter;
    }
};