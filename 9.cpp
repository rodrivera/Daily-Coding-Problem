/*
Daily Coding Problem: Problem #9 [Jul 22]

This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.
For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/

#include <iostream>
#include <vector>
using namespace std;

int foo(vector<int> nums) {
	
	nums.push_back(0);
	nums.push_back(0);

	nums[1] = max(nums[0],nums[1]);
	for(int i=2;i<nums.size();i++) {
		nums[i] = max(nums[i-2]+nums[i],nums[i-1]);
	}

	return nums.back();
}

int main(){

	//int sol = foo({2,4,6,2,5}); // 13
	int sol = foo({5,1,1,5});		// 2
	//int sol = foo({});			// 0
	//int sol = foo({9});			// 9
	//int sol = foo({1,2});			// 2

	cout << sol << endl;

	return 0;
}