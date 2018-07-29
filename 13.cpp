/*
Daily Coding Problem: Problem #13 [Jul 26]

This problem was asked by Amazon.

Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.
For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
*/

#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int foo(string s, int k) {
	int L = 0, R, sol = 0;
	unordered_map<char, int> m;

	for(R = 0; R < s.size(); R++) {
		m[s[R]] = R;
		if (m.size() > k) {
			int minP = INT_MAX;
			auto i = m.begin();
			auto minI = i;
			for (; i != m.end(); ++i) {
				if(i->second < minP) {
					minP = i->second;
					minI = i;
				} 
			}
			L = minP + 1;
			m.erase(minI);
		}
		sol = max(sol,R-L+1);
	}
	return sol;
}

int main(){

	int sol = foo("abcba",2); // 3
	//int sol = foo("abcdefgfedcba",5); // 9
	//int sol = foo("",3); // 0
	//int sol = foo("abcd",0); // 0

	cout << sol << endl;

	return 0;
}