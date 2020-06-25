#include <bits/stdc++.h>
using namespace std;

class Point{
public:
	int start;
	int end;
	int employee;
	int slot;

	Point(int m, int n, int r, int c){
		start = m;
		end = n;
		employee = r;
		slot = c;
	}
};
bool operator>(Point p1, Point p2){

	if(p1.start == p2.start){
		return p1.end > p2.end;
	}
	return p1.start > p2.start;
}
vector<pair<int, int>> employeefreetime(vector<vector<pair<int, int>>> input){

	priority_queue<Point, vector<Point>, greater<Point>> heap;
	for(int i = 0; i < input.size(); i++){

		Point p(input[i][0].first, input[i][0].second, i, 0);
		heap.push(p);
	}
	pair<int, int> ans;
	vector<pair<int, int>> output;
	Point front = heap.top();
	heap.pop();

	int endtime = front.end;
	int index = front.slot + 1;

	if(index < input[front.employee].size()){
		Point temp(input[front.employee][index].first, input[front.employee][index].second, front.employee, index);
		heap.push(temp);
	}
	while(!heap.empty()){
		Point t = heap.top();
		heap.pop();
		int tstart = t.start;
		if(tstart < endtime){
			endtime = t.end;

			int ind = t.slot + 1;
			if(ind < input[t.employee].size()){
				Point t2(input[t.employee][ind].first, input[t.employee][ind].second, t.employee, ind);
				heap.push(t2);
			}
		}
		else{

			ans.first = tstart;
			ans.second = endtime;
			endtime = t.end;

			output.push_back(ans);
			int ind = t.slot + 1;
			if(ind < input[t.employee].size()){
				Point t2(input[t.employee][ind].first, input[t.employee][ind].second, t.employee, ind);
				heap.push(t2);
			}
		}
	}
	return output;
}
int main(){
	vector<vector<pair<int, int>>> input = {{make_pair(1, 3), make_pair(6, 7)}, 
											{make_pair(2,4)},
											{make_pair(2, 5), make_pair(9, 12)}};

	vector<pair<int, int>> ans = employeefreetime(input);
	for(int i = 0; i < ans.size(); i++){
		cout << "[" << ans[i].second << "," << ans[i].first << "]" << endl;
	}
	return 0;
	
}