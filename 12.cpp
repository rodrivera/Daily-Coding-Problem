/*
Daily Coding Problem: Problem #12 [Jul 25]

This problem was asked by Amazon.

There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, 
write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.
For example, if N is 4, then there are 5 unique ways:
1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2

What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? 
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;

int aux(int N, vector<int> steps) {
	if(N < 0)
		return 0;
	if(memo[N] != -1)
		return memo[N];

	int sol = 0;
	for(int i=0;i<steps.size();i++) {
		sol += aux(N-steps[i],steps);
	}
	memo[N] = sol;
	return sol;
}

int foo(int N, vector<int> steps) {
	memo = vector<int>(N+1,-1);
	memo[0] = 1;
	memo[1] = 1;
	return aux(N,steps);
}

int main(){

	//int sol = foo(4,{1,2}) // 5
	//int sol = foo(5,{1,3,5}); // 5
	int sol = foo(10,{1,3,5,10}); // 48?

	cout << sol << endl;

	return 0;
}