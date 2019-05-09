// AC
#include <bits/stdc++.h>

using namespace std;
std::vector<std::vector<int> > adj_list;
std::vector<int> color;

bool same_color(int node, int p){
	for(auto ch: adj_list[node]){
		if (ch == p)
			continue;
		if (! (same_color(ch, node) && color[ch] == color[node]))
			return false;
	}
	return true;
}

bool can_remove(int node){
	for(auto ch: adj_list[node]){
		if(!same_color(ch, node))
			return false;
	}
	return true;
}


pair<int,int> dfs(int node, int p){
	for(auto ch: adj_list[node]){
		if (color[ch] != color[node])
			return {ch, node};
		if (ch == p)
			continue;
		pair<int, int> nodes = dfs(ch, node);
		if(nodes.first == -1)
			continue;
		else
			return nodes;
	}
	return {-1, -1};
}

int main(){
	int n;
	cin>>n;
	adj_list = std::vector<std::vector<int> > (n+1);
	color = std::vector<int> (n+1);
	int t=0;
	for(int i=0; i<n-1;i++){
		int u,v;
		cin>>u>>v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	bool same = true;
	for(int i=1; i<=n;i++){
		cin>>color[i];
		if (t==0){
			t=color[i];
		}
		else if (t!= color[i]){
			same=false;
		}
	}

	if (same){
		cout<<"YES\n1";
	}
	else{
		pair<int, int> nodes = dfs(1, 0);
		if (can_remove(nodes.first))
			cout<<"YES\n"<<nodes.first;
		else if (can_remove(nodes.second))
			cout<<"YES\n"<<nodes.second;
		else
			cout<<"NO";
	}

}