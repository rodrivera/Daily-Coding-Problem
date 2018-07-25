/*
Daily Coding Problem: Problem #2 [Jul 15]

This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> foo(vector<int> nums) {
	int n = nums.size();
	if(n==0) return {};

	vector<int> acuL(n);
	vector<int> acuR(n);

	acuL[0] = nums[0];
	for (int i = 1; i < n; ++i) {
		acuL[i] = acuL[i-1]*nums[i];
	}

 	acuR[n-1] = nums.back();
	for (int i = n-2; i >= 0; --i) {
		acuR[i] = acuR[i+1]*nums[i];
	}

	vector<int> sol(n);
	sol[0] = acuR[1];
	sol[n-1] = acuL[n-2];
	for (int i = 1; i < n-1; ++i) {
		sol[i] = acuL[i-1]*acuR[i+1];
	}

	return sol;

}

int main(){

	//vector<int> sol = foo({1,2,3,4,5});
	vector<int> sol = foo({3,2,1});

	cout << "[ ";
	for (int i = 0; i < sol.size(); ++i) {
		cout << sol[i] << " ";
	}
	cout << "]" << endl;

	return 0;
}