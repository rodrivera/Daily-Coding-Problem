/*
Daily Coding Problem: Problem #21 [Aug 26]

This problem was asked by Snapchat.

Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int foo(vector<pair<int,int> > intervals) {

	priority_queue<int, vector<int>, greater<int> > starts, ends;

	for (int i = 0; i < intervals.size(); ++i) {
		starts.push(intervals[i].first);
		ends.push(intervals[i].second);
	}

	int cont = 0;
	while( !(starts.empty()) && !(ends.empty()) ) {
		cout << starts.top() << " vs " << ends.top() << endl;
		if(starts.top() < ends.top()) {
			cont++;
			starts.pop();
		} else {
			cont--;
			ends.pop();
		}
	}

	return cont;
}

int main(){

	int sol;

	sol = foo({{30,75},{0,50},{60,150}}); // 2

	cout << sol << endl;

	return 0;
}