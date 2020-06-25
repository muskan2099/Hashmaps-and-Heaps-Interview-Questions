class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> heap;
                
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<int>> visited(m, (vector<int>(n, 0)));

        for(int i = 0; i < n; i++){
        	pair<int, pair<int, int>> temp1;
        	temp1.first = heightMap[0][i];
        	temp1.second.first = 0;
        	temp1.second.second = i;

            //cout << heightMap[0][i] << ",";
        	visited[0][i] = 1;
        	heap.push(temp1);

        	pair<int, pair<int, int>> temp2;
        	temp2.first = heightMap[m - 1][i];
        	temp2.second.first = m - 1;
        	temp2.second.second = i;

           //cout << heightMap[m-1][i] << ",";
        	visited[m-1][i] = 1;
        	heap.push(temp2);
        }
        for(int i = 0; i < m; i++){
        	pair<int, pair<int, int>> temp1;
        	temp1.first = heightMap[i][0];
        	temp1.second.first = i;
        	temp1.second.second = 0;
            
           // cout << heightMap[i][0] << ",";

        	visited[i][0] = 1;
        	heap.push(temp1);

        	pair<int, pair<int, int>> temp2;
        	temp2.first = heightMap[i][n-1];
        	temp2.second.first = i;
        	temp2.second.second = n-1;
            
            //cout << heightMap[i][n-1] << ",";

        	visited[i][n-1] = 1;
        	heap.push(temp2);
        }
        
        int ans = 0;
        while(!heap.empty()){
        	pair<int, pair<int, int>> front = heap.top();
        	heap.pop();
        	int element = front.first;
        	int row = front.second.first;
        	int col = front.second.second;

        	//check neighbours
        	//top
        	if(row > 0 && !visited[row - 1][col]){
        		int height = heightMap[row - 1][col];

        		if(height < element){

        			ans += element - height;
        			pair<int, pair<int, int>> temp;
        			temp.first = element;
		        	temp.second.first = row - 1;
		        	temp.second.second = col;

		        	visited[row - 1][col] = 1;
		        	heap.push(temp);
        		}
        		else{
        			pair<int, pair<int, int>> temp;
        			temp.first = height;
		        	temp.second.first = row - 1;
		        	temp.second.second = col;

		        	visited[row - 1][col] = 1;
		        	heap.push(temp);
        		}
        	}
        	//bottom
        	if(row < m-1 && !visited[row + 1][col]){
        		int height = heightMap[row + 1][col];

        		if(height < element){

        			ans += element - height;
        			pair<int, pair<int, int>> temp;
        			temp.first = element;
		        	temp.second.first = row + 1;
		        	temp.second.second = col;

		        	visited[row + 1][col] = 1;
		        	heap.push(temp);
        		}
        		else{
        			pair<int, pair<int, int>> temp;
        			temp.first = height;
		        	temp.second.first = row + 1;
		        	temp.second.second = col;

		        	visited[row + 1][col] = 1;
		        	heap.push(temp);
        		}
        	}
        	//right
        	if(col < n - 1 && !visited[row][col + 1]){
        		int height = heightMap[row][col + 1];

        		if(height < element){

        			ans += element - height;
        			pair<int, pair<int, int>> temp;
        			temp.first = element;
		        	temp.second.first = row;
		        	temp.second.second = col + 1;

		        	visited[row][col + 1] = 1;
		        	heap.push(temp);
        		}
        		else{
        			pair<int, pair<int, int>> temp;
        			temp.first = height;
		        	temp.second.first = row;
		        	temp.second.second = col + 1;

		        	visited[row][col + 1] = 1;
		        	heap.push(temp);
        		}
        	}
        	//left
        	if(col > 0 && !visited[row][col - 1]){
        		int height = heightMap[row][col - 1];

        		if(height < element){

        			ans += element - height;
        			pair<int, pair<int, int>> temp;
        			temp.first = element;
		        	temp.second.first = row;
		        	temp.second.second = col - 1;

		        	visited[row][col - 1] = 1;
		        	heap.push(temp);
        		}
        		else{
        			pair<int, pair<int, int>> temp;
        			temp.first = height;
		        	temp.second.first = row;
		        	temp.second.second = col - 1;

		        	visited[row][col - 1] = 1;
		        	heap.push(temp);
        		}
        	}
        }
        return ans;
    }
};