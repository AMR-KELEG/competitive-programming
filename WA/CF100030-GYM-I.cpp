#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif

	#ifdef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	std::vector<set<int> > adjList(n+1);
	for (int i=0,a,b;i<n-1;i++)
	{
		cin>>a>>b;
		adjList[a].insert(b);
		adjList[b].insert(a);
	}	

	std::vector<bool> done(n+1,0);
	std::vector<bool> is_guard(n+1,0);
	for (int it=0;it<n;it++)
	{
		int cur_node = -1;
		for (int node = 1;node<=n;node++)
		{
			if (done[node])
				continue;
			if (cur_node==-1 || adjList[node].size()<adjList[cur_node].size())
				cur_node = node;
		}
		if (cur_node==-1)
			break;
		done[cur_node] = 1;
		int parent = 0;
		if (adjList[cur_node].size()==1)
		{
			parent = * (adjList[cur_node].begin());
		}
		else
		{
			parent = cur_node;
		}
		done[parent] = 1;
		is_guard[parent] = 1;
		for (auto ch:adjList[parent])
		{
			done[ch] = 1;
			adjList[ch].erase(parent);
		}
		adjList[parent].clear();
	}
	for (int i=1;i<=n;i++)
	{
		if (is_guard[i])
			cout<<1<<" ";
		else
			cout<<0<<" ";
	}
}