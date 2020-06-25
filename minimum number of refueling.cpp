class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        priority_queue<int> heap;

        int ans = 0;
        int fuel = startFuel;
        for(int i = 0; i < stations.size(); i++){

        	int dis = stations[i][0];
        	int fuelreq = stations[i][1];

        	if(fuel >= dis){
        		heap.push(fuelreq);
        	}
        	else{
        		while(!heap.empty() && fuel < dis){
        			int maxfuel = heap.top();
        			heap.pop();
        			ans++;
        			fuel += maxfuel;
                    
        		}
        		if(fuel < dis && heap.empty()){
        			return -1;
        		} 
                heap.push(fuelreq);
        	}
        }
        int dis = target;
        while(!heap.empty() && fuel < dis){
        	int maxfuel = heap.top();
        	heap.pop();
        	ans++;
        	fuel += maxfuel;
        }
        if(fuel < dis && heap.empty()){
        	return -1;
        }
        return ans;
    }
};