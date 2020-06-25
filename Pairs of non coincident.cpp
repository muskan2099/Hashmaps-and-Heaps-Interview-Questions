#include <bits/stdc++.h>
using namespace std;
int pairnoncoincident(vector<pair<int, int>> points){
	int n = points.size();
	unordered_map<int, int> xcoordinate;
	unordered_map<int, int> ycoordinate;
	unordered_map<string, int> hash;

	int ans = 0;
	for(int i = 0; i < n; i++){
		if(xcoordinate.count(points[i].first) != 0){
			ans += xcoordinate[points[i].first];
			xcoordinate[points[i].first]++;
		}
		else{
			xcoordinate[points[i].first] = 1;
		}
		if(ycoordinate.count(points[i].second) != 0){
			ans += ycoordinate[points[i].second];
			ycoordinate[points[i].second]++;
		}
		else{
			ycoordinate[points[i].second] = 1;
		}

		string temp = to_string(points[i].first) + "," + to_string(points[i].second);
		if(hash.count(temp) != 0){

			ans = ans - 2*hash[temp];
		}
		else{
			hash[temp] = 1;
		}
	}
	return ans;
}
int main(){
	
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    
	    vector<pair<int, int>> points;
	    for(int i = 0; i < n; i++){
	        int a, b;
	        cin >> a >> b;
	        
	        points.push_back(make_pair(a, b));
	    }
	    cout << pairnoncoincident(points) << endl;
	}

	return 0;
}