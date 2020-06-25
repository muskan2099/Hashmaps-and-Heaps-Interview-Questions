bool mirrorAxis(vector<vector<int>> points){

	int minimum = INT_MAX;
	int maximum = INT_MIN;

	unordered_map<string, int> hash;

	for(int i = 0; i < points.size(); i++){

		minimum = min(minimum, points[i][0]);
		maximum = max(maximum, points[i][0]);

		string temp = to_string(points[i][0]) + "*" + to_string(points[i][1]);
	}

	int k = (minimum + maximum)/2;

	int count = 0;
	for(int i = 0; i < points.size(); i++){

		int x2 = 2*k - points[i][0];

		string temp1 = to_string(x2) + "*" + to_string(points[i][1]);
		string temp12 = to_string(points[i][0]) + "*" + to_string(points[i][1]);

		if(hash.count(temp1) != 0){
			hash.erase(temp1);
			hash.erase(temp2);
		}
		else{
			return false;
		}
	}
	return true;
}