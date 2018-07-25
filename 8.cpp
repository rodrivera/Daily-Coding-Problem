/*
Daily Coding Problem: Problem #8 [Jul 21]

This problem was asked by Google.

A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.
Given the root to a binary tree, count the number of unival subtrees.
For example, the following tree has 5 unival subtrees:

   0					0
  / \
 1   0					1 0
    / \
   1   0				NULL NULL 1 0
  / \
 1   1					NULL NULL NULL NULL 1 1 NULL NULL
*/

#include <iostream>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#define null INT_MIN
using namespace std;

struct bt_node {
	int val;
	bt_node *left;
	bt_node *right;
	bt_node(int x) : val(x), left(NULL), right(NULL) {};
};

bt_node* read_tree(vector<int> in) {
	vector<bt_node*> nodes(in.size(),NULL);

	for(int i = in.size()-1;i >=0; i--) {
		if(in[i] != null) {
			nodes[i] = new bt_node(in[i]);
			if(2*i+1 < in.size() && nodes[2*i+1]) {
				nodes[i]->left = nodes[2*i+1];
			}
			if(2*i+2 < in.size() && nodes[2*i+2]) {
				nodes[i]->right = nodes[2*i+2];
			}
		}
	}

	return nodes[0];
}

void printX(bt_node* root) {
	queue<bt_node*> s;
	bt_node *dummy = new bt_node(0);
	s.push(root); s.push(dummy);
	while(!s.empty()) {
		bt_node *curr = s.front(); s.pop();
		if(!curr) cout << "null ";
		else if(curr == dummy) { 			
			cout << endl;
			if(s.empty()) return;
			s.push(dummy);
		} else {
			cout << curr->val << " ";
			s.push(curr->left); s.push(curr->right);
		}
	}
}


bool unival(bt_node *root, int &cont) {
	bool left = (!root->left || (unival(root->left,cont) && root->val==root->left->val) );
	bool right = (!root->right || (unival(root->right,cont) && root->val==root->right->val) );
	if(left && right) {
		cont++;
		return true;
	}
	return false;
}

int foo(bt_node *root) {
	int sol = 0;
	unival(root,sol);
	return sol;
}

int main(){

	//bt_node *root = read_tree({0,1,0,null,null,1,0,null,null,null,null,1,1}); // 5
	//bt_node *root = read_tree({1,1,1,null,null,1,1,null,null,null,null,null,null,null,2}); // 3
	bt_node *root = read_tree({1,3,2,null,null,2,2,null,null,null,null,null,null,null,2}); // 5

	//printX(root);
	cout << foo(root) << endl;

	return 0;
}