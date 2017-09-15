#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<int> > adjlist;
std::vector<int> depth;
std::vector<std::vector<int> > parent;
int n;

int lca(int up,int down)
{
	if(depth[up] > depth[down])
		swap(up,down);
	for(int level = 17;level>=0;level--)
	{
		if(depth[down] - (1<<level) >=depth[up])
		{
			// Go up here
			down = parent[down][level];
		}
	}
	if(up == down)
		return up;
	for(int level = 17;level>=0;level--)
	{
		if(parent[up][level]!=-1 && parent[up][level]!=parent[down][level])
		{
			// Go up here
			down = parent[down][level];
			up = parent[up][level];
		}
	}
	return parent[up][0];
}

void dfs(int node = 1,int par = -1, int d =0)
{
	depth[node]=d;
	parent[node][0]=par;
	for(auto ch:adjlist[node])
	{
		if(ch == par)
			continue;
		dfs(ch,node,d+1);
	}
}

void prepare()
{
	depth = std::vector<int> (n+1);
	parent = std::vector<std::vector<int> > (n+1,std::vector<int> (18,-1));
	dfs();
	for(int level = 17;level>0;level--)
	{
		for(int node = 1;node<=n;node++)
		{
			if(parent[node][level-1]==-1)
				continue;
			parent[node][level] = parent [parent[node][level-1]] [level-1];
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int m,q;
	cin>>n>>m>>q;
	adjlist = std::vector<std::vector<int> > (n+1);
	for(int i=1,u,v;i<n;i++)
	{
		cin>>u>>v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	prepare();
	cout<<lca(5,5);
}