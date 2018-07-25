/*
Daily Coding Problem: Problem #4 [Jul 17]

This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. 
In other words, find the lowest positive integer that does not exist in the array. 
The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/

#include <vector>
#include <iostream>
using namespace std;

int foo(vector<int> nums) {

	int length = nums.size();
	int first_positive = 0;

	for (int i = 0; i < length; ++i) {
		if(nums[i] < 1) {
			swap(nums[i], nums[first_positive]);
			nums[first_positive++] *= -1;
		}
	}

	for(int i = first_positive; i< length; i++) {
		int abs_index = abs(nums[i]);
		if(abs_index<=length && nums[abs_index-1] > 0) nums[abs_index-1] *= -1;
	}

	for(int i = 0; i<length; i++) {
		if(nums[i]>0) return i+1;
	}
	return length+1;
}

int main() {

	int sol = foo({3,4,-1,1});	// answer = 1
	//int sol = foo({1,2,0});		// answer = 3
	//int sol = foo({1,2,3,4,6});	// answer = 5
	//int sol = foo({1,2,3,4,5});	// answer = 6
	//int sol = foo({});			// answer = 1
	//int sol = foo({-1,-2,-3});	// answer = 1

	cout << sol << endl;

	return 0;
}