/*
Daily Coding Problem: Problem #20 [Aug 25]

This problem was asked by Google.

Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.
For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.
In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
*/

#include <iostream>
using namespace std;

struct Node {
	int val;
	Node *next;
	Node(int x) : val(x), next(NULL) {}
};

struct Node* foo(Node *A, Node *B) {
	int lenA = 0, lenB = 0;
	Node *currA = A, *currB = B;

	while(currA) {
		lenA++;
		currA = currA->next;
	}
	while(currB) {
		lenB++;
		currB = currB->next;
	}

	while(lenA < lenB) {
		B = B->next;
		lenB--;
	}
	while(lenB < lenA) {
		A = A->next;
		lenA--;
	}

	while(A!=B) {
		A = A->next;
		B = B->next;
	}

	return A;

}

int main(){

	Node *A1, *A2, *A3; 	// 3,6,9
	Node *B1, *B2;			// 4,8
	Node *C1, *C2;			// 12,15

	C2 = new struct Node(15); 
	C1 = new struct Node(12); C1->next = C2;

	A3 = new struct Node(9); A3->next = C1;
	A2 = new struct Node(6); A2->next = A3;
	A1 = new struct Node(3); A1->next = A2;

	B2 = new struct Node(8); B2->next = C1;
	B1 = new struct Node(4); B1->next = B2;
	
	cout << "BEGIN" << endl;
	Node *sol = foo(A1, B1);
	cout << "END" << endl;

	cout << sol->val << endl;

	return 0;
}