/*
Daily Coding Problem: Problem #16 [Jul 29]

This problem was asked by Twitter.

You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish this, 
with the following API:
	- record(order_id): adds the order_id to the log
	- get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.

You should be as efficient with time and space as possible.
*/

#include <vector>
#include <iostream>
using namespace std;

class log {
private:
	vector<int> v;
	int last;
	int capacity;

public:
	log(int N): capacity(N), last(0), v(N) {}
	
	void record(int order_id) {
		v[last++%capacity] = order_id;
	}

	int get_last(int i) {
		return v[(last-i)%capacity];
	}

};

int main() {

	log L(2);

	L.record(1); L.record(2); L.record(3); L.record(4); L.record(5);
	cout << L.get_last(1) << endl; // 5 
	cout << L.get_last(2) << endl; // 5
	cout << L.get_last(3) << endl; // 5
	cout << L.get_last(4) << endl; // 5
	cout << L.get_last(5) << endl; // 5

	return 0;
}