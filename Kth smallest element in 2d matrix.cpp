class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int ans;
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> heap;

        int count = 0;
        for(int i = 0; i < matrix.size(); i++){
        	pair<int, pair<int, int>> temp;
        	temp.first = matrix[i][0];
        	temp.second.first = i;
        	temp.second.second = 0;

        	heap.push(temp);
        }
    
        while(count < k){

        	pair<int, pair<int, int>> front = heap.top();
        	heap.pop();
            
            count++;
            //cout << front.first << "," << front.second.first << "," << front.second.second << endl;
            ans = front.first;

        	
        	
        	if(front.second.second < matrix.size()-1){
        		pair<int, pair<int, int>> temp;
	        	temp.first = matrix[front.second.first][front.second.second + 1];
	        	temp.second.first = front.second.first;
	        	temp.second.second = front.second.second + 1;

	        	heap.push(temp);
        	}
        }
        
        return ans;
    }
};