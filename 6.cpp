/*
Daily Coding Problem: Problem #6 [Jul 19]

This problem was asked by Google.

An XOR linked list is a more memory efficient doubly linked list. 
Instead of each node holding next and prev fields, it holds a field named both, 
which is an XOR of the next node and the previous node. Implement an XOR linked list; 
it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python), 
you can assume you have access to get_pointer and dereference_pointer functions that converts between nodes and memory addresses.
*/

#include <vector>
#include <iostream>
using namespace std;

class xorList {

private:
	struct Node {
		int val;
		uintptr_t both;
		Node(int x) : val(x), both(0) {};
		void setBoth(Node *ptr) { both ^= (uintptr_t)ptr; };
		Node *getNext(Node *prev) { return (Node*)(both ^ (uintptr_t)prev); };
	} *head, *tail;

	int length;

public:
	xorList() {
		length = 0;
	}

	void add(int val) {
		Node *newNode = new Node(val);

		if(!length) {
			head = newNode;
			tail = head;
			head->setBoth(NULL);
		} else {
			tail->setBoth(newNode);
			newNode->setBoth(tail);
			tail = newNode;
		}
		length++;
	}

	int get(int index) {
		if(index >= length)
			return 0;

		Node *prev = NULL;
		Node *curr = head;
		while(curr && index--) {
			Node *nxt = curr->getNext(prev);
			prev = curr;
			curr = nxt;
		}
		return curr->val;
	}
	
	void print() {
		Node *prev = NULL;
		Node *curr = head;
		cout << "List:";
		while(curr) {
			cout << " " << curr->val;
			Node *nxt = curr->getNext(prev);
			prev = curr;
			curr = nxt;
		}
		cout << endl;
	}
};

int main() {

	xorList list;

	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);

	list.print();

	cout << list.get(0) << endl; // 1
	cout << list.get(2) << endl; // 3
	cout << list.get(4) << endl; // 5

	return 0;
}