class Solution {
public:
	bool checklamps(int n, map <pair<int, int>, int> positions,int row, int col, int &r, int &c){

		if(positions.find(make_pair(row, col)) != positions.end()){
			r = row;
			c = col;

			return true;
		}
		else if(row > 0 && positions.find(make_pair(row - 1, col)) != positions.end()){

			r = row - 1;
			c = col;

			return true;
		}
		else if(row < n - 1 && positions.find(make_pair(row + 1, col)) != positions.end()){

			r = row + 1;
			c = col;

			return true;
		}
		else if(col < n - 1 && positions.find(make_pair(row, col + 1)) != positions.end()){

			r = row;
			c = col + 1;

			return true;
		}
		else if(col > 0 && positions.find(make_pair(row, col - 1)) != positions.end()){

			r = row;
			c = col - 1;

			return true;
		}
		else if(row > 0 && col > 0 && positions.find(make_pair(row - 1, col - 1)) != positions.end()){

			r = row - 1;
			c = col - 1;

			return true;
		}
		else if(row > 0 && col < n- 1 && positions.find(make_pair(row - 1, col + 1)) != positions.end()){

			r = row - 1;
			c = col + 1;

			return true;
		}
		else if(row < n - 1 && col < n - 1 && positions.find(make_pair(row + 1, col + 1)) != positions.end()){

			r = row + 1;
			c = col + 1;

			return true;
		}
		else if(row < n - 1 && col > 0 && positions.find(make_pair(row + 1, col - 1)) != positions.end()){

			r = row + 1;
			c = col - 1;

			return true;
		}
		return false;
	}
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        
        //storing the indices of lamps ans storing the lightened up lamps
        unordered_map<int, int> row;
        unordered_map<int, int> col;
        unordered_map<int, int> d1;
        unordered_map<int, int> d2;

        map<pair<int, int>, int> positions;
        for(int i = 0; i < lamps.size(); i++){

            pair<int, int> temp = make_pair(lamps[i][0], lamps[i][1]);
        	positions[temp] = 1;;

        	int r = lamps[i][0];
        	int c = lamps[i][1];

        	if(row.count(r) == 0){
        		row[r] = 1;
        	}
        	else{
        		row[r]++;
        	}
        	//__________
        	if(col.count(c) == 0){
        		col[c] = 1;
        	}
        	else{
        		col[c]++;
        	}
        	//__________
        	if(d1.count(r + c) == 0){
        		d1[r + c] = 1;
        	}
        	else{
        		d1[r + c]++;
        	}
        	//___________
        	if(d2.count(r - c) == 0){
        		d2[r - c] = 1;
        	}
        	else{
        		d2[r - c]++;
        	}
        }

        //solving queries
        vector<int> output;
        

        for(int i = 0; i < queries.size(); i++){
        	bool flag = 0;

        	int r = queries[i][0];
        	int c = queries[i][1];

        	if(row.count(r) != 0 || col.count(c) != 0 || d1.count(r + c) != 0 || d2.count(r - c) != 0){
        		flag = 1;
        	}
        	if(flag == 0){
        		output.push_back(0);
        		continue;
        	}
        	else{
        		output.push_back(1);
        		//check for the lamp in 9 directions

        		int i, j;
        		while(checklamps(N, positions,r, c, i, j)){
        		
        			positions.erase(make_pair(i, j));
        			if(row.count(i) != 0){
        				row[i]--;
                        if(row[i] == 0){
                            row.erase(i);
                        }
        			}
        			if(col.count(j) != 0){
        				col[j]--;
                        if(col[j] == 0){
                            col.erase(j);
                        }
        			}
        			if(d1.count(i + j) != 0){
        				d1[i + j]--;
                        if(d1[i + j] == 0){
                            d1.erase(i + j);
                        }
        			}
        			if(d2.count(i - j) != 0){
        				d2[i - j]--;
                        if(d2[i - j] == 0){
                            d2.erase(i - j);
                        }
        			}
        		}
        	}
        }

        return output;
    }
};