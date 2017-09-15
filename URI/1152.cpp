//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	while(! (n==0 && m==0))
	{
		std::vector<vector<pair<int,int>>> adjlist(n);
		std::vector<bool> vis(n,0);
		vis[0]=1;
		int min_cost =0;
		int total_cost = 0;
		for (int i=0;i<m;i++)
		{
			int u,v,c;
			cin>>u>>v>>c;
			total_cost+=c;
			adjlist[u].push_back({v,c});
			adjlist[v].push_back({u,c});
		}
		// continue;
		priority_queue<pair<int,int> >q; // -c and n
		for (int i=0;i<adjlist[0].size();i++)
		{
			q.push({-adjlist[0][i].second,adjlist[0][i].first});
		}
		while(!q.empty())
		{
			int node = q.top().second;
			int cost = -q.top().first;
			q.pop();
			if (vis[node])
				continue;
			min_cost+=cost;
			vis[node]=1;
			for (int i=0;i<adjlist[node].size();i++)
			{
				int next_node = adjlist[node][i].first;
				if (vis[next_node])
					continue;
				q.push({-adjlist[node][i].second,adjlist[node][i].first});
			}
		}
		
		// cout<<total_cost<<endl;
		cout<<total_cost-min_cost<<endl;
		cin>>n>>m;
	}
}