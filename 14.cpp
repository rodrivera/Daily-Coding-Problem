/*
Daily Coding Problem: Problem #14 [Jul 27]

This problem was asked by Google.

The area of a circle is defined as πr^2. 
Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.
*/

#include <iostream>
#include <cmath>
#define NP 1000000
using namespace std;

double foo() {
	double cont = 0;
	for(int i = 0; i < NP; i++) {
		int x = rand()%100 - 50;
		int y = rand()%100 - 50;
		if( x*x + y*y <= 50*50) {
			cont++;
		}
	}
	return ((double)(round(4*(cont/NP)*1000)))/1000;
}

int main(){

	srand(time(NULL));
	double sol = foo();

	cout << sol << endl;

	return 0;
}