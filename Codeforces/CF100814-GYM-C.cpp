// AC
// 1:33

#include "bits/stdc++.h"
using namespace std;
int n;
#define INF 1000000007
// LCA
std::vector<std::vector<int> > LCA;
std::vector<std::vector<int> > max_val;


// DFS
std::vector<int> level;
// MAIN

std::vector<std::vector<pair<int,int>> > adjlist;
std::vector<int> par;
int find(int a)
{
	if (par[a]==a)
		return a;
	return par[a] = find(par[a]);
}

void merge(int a,int b)
{
	int pa = find(a);
	int pb = find(b);
	par[pa] = pb;
}

void dfs(int node, int l=0)
{
	level[node] =l;
	for (int i=0;i<adjlist[node].size();i++)
	{
		int next_node = adjlist[node][i].first;
		if (level[next_node] !=-1)
			continue;
		dfs(next_node,l+1);
		LCA[next_node][0] = node;
		max_val[next_node][0] = adjlist[node][i].second;
	}
}
void prepare()
{
	LCA = std::vector<std::vector<int> > (n+1,std::vector<int> (18,-1));
	max_val = std::vector<std::vector<int> > (n+1,std::vector<int> (18,INF));
	level = std::vector<int> (n+1,-1);
	for (int i=1;i<=n;i++)
	{
		if (level[i] == -1)
			dfs(i);
	}

	for (int l = 1;l<17;l++)
	{
		for (int node = 1;node<=n;node++)
		{
			if (LCA[node][l-1] == -1)
				continue;
			LCA[node][l] = LCA[LCA[node][l-1]][l-1];
			max_val[node][l] = max(max_val[node][l-1], max_val[LCA[node][l-1]][l-1]);
		}
	}
}

int solve(int a,int b,int ti)
{
	if (a==b)
		return 0;
	if (find(a) !=find(b))
		return -1;
	int ans = 0;
	if (level[a] > level[b])
		swap(a,b);
	for (int shift = 17;shift>=0 ;shift--)
	{
		if (level[b] - (1<<shift) <level[a])
			continue;
		ans = max(ans, max_val[b][shift]);
		b = LCA[b][shift];
	}
	if (a!=b)
	{
		// find the LCA 
		for (int shift = 17;shift>=0;shift--)
		{
			if (LCA[a][shift] == LCA[b][shift])
				continue;
			ans = max(ans, max_val[a][shift]);
			ans = max(ans, max_val[b][shift]);
			a = LCA[a][shift];
			b = LCA[b][shift];
		}
		if (a!=b)
		{
			ans = max(ans,max_val[a][0]);
			ans = max(ans,max_val[b][0]);
		}
	}
	if (ans>=ti)
		return -1;
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while(T--)
	{
		int q;
		cin>>n>>q;
		// vis and par and LCA and adjlist
		par = std::vector<int> (n+1);
		adjlist = std::vector<std::vector<pair<int,int>> > (n+1);
		for (int i=1;i<=n;i++)
			par[i]=i;
		std::vector<pair<int,pair<int,int>>> queries;
		for (int i=1;i<=q;i++)
		{
			int t,u,v;
			cin>>t>>u>>v;
			if (t==2)
				queries.push_back({i,{u,v}});
			else
			{
				if (find(u)==find(v))
					continue;
				adjlist[u].push_back({v,i});
				adjlist[v].push_back({u,i});
				merge(u,v);
			}
		}
		prepare();
		for (int i=0;i<queries.size();i++)
		{
			printf("%d\n", solve(queries[i].second.first,queries[i].second.second,queries[i].first));
		}
	}	
	return 0;
}