/* Passed both tests
The idea is based on using a Trie with reversed strings.

*/
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	Node * children[26];
	int no_of_paths;
	bool is_terminal;
	Node(){
		for(int i=0;i<26;i++){
			children[i] = nullptr;
		}
		is_terminal = false;
		no_of_paths = 0;
	}
	void insert(char c, Node * ch){
		children[c-'A'] = ch;
	}
	Node * get_child(char c){
		return children[c-'A'];
	}
};

class Trie{
public:
	Node * root;
	Trie(){
		root = new Node();
	}
	void insert(string s){
		Node * current = root;
		for (int i=s.size()-1;i>=0;i--){
			current->no_of_paths++;
			if(current->get_child(s[i]) == nullptr){
				current->insert(s[i], new Node());
			}
			current = current->get_child(s[i]);
		}
		current->no_of_paths++;
		current->is_terminal = true;
	}
};

int solve_r(Node * n){
	if (n==nullptr)
		return 0;
	int must_paths = 0;
	if (n->is_terminal)
		must_paths++;
	int ans = 0;
	for(int i=0; i<26;i++){
		if(n->children[i]==nullptr)
			continue;
		if (n->children[i]->no_of_paths==1){
			must_paths++;
			continue;
		}
		int current_take = solve_r(n->children[i]); 
		ans += current_take;
		current_take*=2;
		if (current_take < n->children[i]->no_of_paths){
			must_paths += n->children[i]->no_of_paths - current_take;
		}
	}
	if (must_paths>1)
		ans++;
	return ans;
}

int solve(Node * root){
	int ans =0;
	for (int i=0;i<26;i++){
		ans += solve_r(root->children[i]);
	}
	return ans;
}

int main(){
	freopen("in.txt", "r", stdin);
	int T;
	cin>>T;
	for (int t=1;t<=T;t++){
		Trie tr;
		int n;
		cin>>n;
		string s;
		for(int i=0;i<n;i++){
			cin>>s;
			tr.insert(s);
		}
		cout<<"Case #"<<t<<": "<<2*solve(tr.root)<<"\n";
	}
}
