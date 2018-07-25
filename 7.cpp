/*
Daily Coding Problem: Problem #7 [Jul 20]

This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
You can assume that the messages are decodable. For example, '001' is not allowed.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;

int aux(string encoded, int l) {

	int sol = memo[l];
	if(sol != -1) {
		return sol;
	}

	if(encoded[l] == '0') {
		sol = 0;
	} else if( l+1<encoded.size() && (encoded[l] == '1' || (encoded[l] == '2' && encoded[l+1]<='6') ) ) {
		sol = aux(encoded,l+1) + aux(encoded,l+2);
	} else {
		sol = aux(encoded,l+1);
	}

	memo[l] = sol;
	return sol;

}

int foo(string encoded) {
	memo = vector<int>(encoded.size()+1,-1);
	memo[encoded.size()] = 1;
	return aux(encoded,0);
}

int main(){

	//int sol = foo("111"); // 3
	//int sol = foo("011"); // 0
	int sol = foo("602"); // 0

	cout << sol << endl;

	return 0;
}