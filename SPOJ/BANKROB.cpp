// AC
// 3:12 -> 3:44 + 5minutes
#include "bits/stdc++.h"
using namespace std;
#define OFF 1000
int adjMat[2000][2000]={};

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	int s,t;
	cin>>s>>t;
	s--;
	t--;
	if (s>t)
		swap(s,t);
	for (int i=0;i<n;i++)
	{
		if (i == s || i==t)
			continue;
		adjMat[i][i+OFF] = 1;
	}
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		u--;v--;
		if (u>v)
			swap(u,v);
		if (u==s && v==t)
		{
			// forbidden
			continue;	
		}
		if (u==s || u==t)
		{
			// connect u and in[v]
			adjMat[u][v]=1;
			adjMat[v+OFF][u] = 1;
		}
		else if (v==s || v==t)
		{
			adjMat[v][u]=1;
			adjMat[u+OFF][v] = 1;
		}
		else
		{
			// in[u] = u
			// out[u] = u+OFF
			adjMat[v+OFF][u]=1;
			adjMat[u+OFF][v] = 1;
		}
	}

	if (s==t)
	{
		cout<<0;
		return 0;
	}
	// find_path (s,t)
	bool path_found = 0;	
	int max_flow = 0;
	do
	{
		path_found = 0;
		std::vector<int> par(n+OFF,-1);
		queue<int> q;
		q.push(s);
		par[s]=s;
		while(!q.empty())
		{
			int node = q.front();
			q.pop();
			if (node == t)
			{
				// found_path
				max_flow++;
				path_found = 1;
				// use the edges
				while(node!=s)
				{
					// edge between par[node] and node
					adjMat[node][par[node]]++;
					adjMat[par[node]][node]--;
					node = par[node];
				}
				break;
			}
			for (int ch = 0;ch<n+OFF;ch++)
			{
				if(par[ch]==-1 && adjMat[node][ch])
				{
					q.push(ch);
					par[ch] = node;
				}
			}
		}
	}while(path_found);
	cout<<max_flow;
}