// AC
#include "bits/stdc++.h"
using namespace std;

std::vector<int> nodes_at_lvl(1000);
std::vector<std::vector<int> > adj;
std::vector<pair<int,int> > loc;

void dfs(int node=1,int l=0,int p =-1)
{
	loc[node]= {nodes_at_lvl[l],l};
	nodes_at_lvl[l]++;
	for (int i=0;i<adj[node].size();i++)
	{
		int ch = adj[node][i];
		if (ch == p)
			continue;
		dfs(ch,l+1,node);
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	adj = std::vector<std::vector<int> > (n+1);
	loc = std::vector<pair<int,int> > (n+1);
	for (int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	
	dfs();
	long double c = 0.00001;
	for (int i=1;i<=n;i++)
	{
		printf("%0.9LF %0.9LF\n", loc[i].first*(1+c),loc[i].second*(1+c));
	}
}