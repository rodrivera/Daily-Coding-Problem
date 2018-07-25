/*
Daily Coding Problem: Problem #1 [Jul 14]

This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool foo(vector<int> nums, int k) {
	
	set<int> seen;

	for (int i = 0; i < nums.size(); ++i) {
		if(seen.find(k-nums[i]) != seen.end()) {
			cout << nums[i] << " and " << k-nums[i] << endl;
			return true;
		}
		seen.insert(nums[i]);
	}
	return false;

}

int main(){

	bool sol = foo({10,15,3,5,2,9},17);
	//bool sol = foo({10,15,3,5,4,9},17);

	cout << sol << endl;

	return 0;
}