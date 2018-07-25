/*
Daily Coding Problem: Problem #11 [Jul 24]

This problem was asked by Twitter.

Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, 
return all strings in the set that have s as a prefix.
For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class autocomplete {
private:
	struct trieNode {
		bool end;
		unordered_map<char, trieNode*> children;
		trieNode() : end(false) {};
	} *root;

	void trieInsert(string word) {
		trieNode *curr = root;
		for (int i = 0; i < word.size(); ++i) {
			unordered_map<char, trieNode*>::iterator it = curr->children.find(word[i]);
			if(it == curr->children.end()) {
				curr->children[word[i]] = new trieNode();
			}
			curr = curr->children[word[i]];
		}
		curr->end = true;
	}

public:
	autocomplete(vector<string> dict) {
		root = new trieNode();
		for (int i = 0; i < dict.size(); ++i) {
			trieInsert(dict[i]);
		}
	}

	vector<string> query(string prefix) {
		trieNode *curr = root;
		vector<string> sol;
		unordered_map<char, trieNode*>::iterator it;

		for (int i = 0; i < prefix.size(); ++i) {
			it = curr->children.find(prefix[i]);
			if(it == curr->children.end()) 
				return sol;
			curr = curr->children[prefix[i]];
		}

		queue<pair<trieNode*,string> > q;
		q.push(make_pair(curr,prefix));

		while(!q.empty()) {
			curr = q.front().first;
			string ss = q.front().second; q.pop();
		
			if(curr->end) sol.push_back(ss);

			for(it = curr->children.begin(); it != curr->children.end(); it++) {
				q.push(make_pair(it->second,ss + it->first) );
			}
		}

		return sol;
	}

	void printTrie() {
		trieNode *curr = root;
		unordered_map<char, trieNode*>::iterator it;

		queue<pair<trieNode*,string> > q;
		q.push(make_pair(curr,""));

		while(!q.empty()) {
			curr = q.front().first;
			string ss = q.front().second; q.pop();
		
			cout << ss;
			if(curr->end) cout << "$";

			for(it = curr->children.begin(); it != curr->children.end(); it++) {
				q.push(make_pair(it->second,ss + it->first) );
			}
			cout << endl;
		}
		cout << endl;
	}
	
};

int main(){

	//vector<string> sol = autocomplete({"dog","deer","deal"}).query("de");
	vector<string> sol = autocomplete({"arc","abandon","ability","abstract","accept","baby","back","bag","boat","boom"}).query("bo");

	cout << "Number of possible words: " << sol.size() << endl;
	for(int i=0;i<sol.size();i++) {
		cout << " > " << sol[i] << endl;
	}

	return 0;
}