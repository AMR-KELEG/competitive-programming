// AC
#include "bits/stdc++.h"
#define INF 1000000000
using namespace std;
std::vector<std::vector<int> > adjlist;
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
		int n,m;
		cin>>n>>m;
		adjlist = std::vector<std::vector<int> > (n);
		std::vector<int> dis(n,INF);
		dis[0] = 0;
		for (int i=1;i<n;i++)
		{
			int is_blocked;
			cin>>is_blocked;
			if (is_blocked)
				dis[i] = -1;
		}
		while(m--)
		{
			int u,v;
			cin>>u>>v;
			adjlist[u].push_back(v);
			adjlist[v].push_back(u);	
		}
		priority_queue<pair<int,int> >q;
		q.push(make_pair(0,0));
		while(!q.empty())
		{
			int node = q.top().second;
			int cost = -q.top().first;
			q.pop();
			if (cost> dis[node])
				continue;
			dis[node] = cost;
			for (int i=0;i<adjlist[node].size();i++)
			{
				if (dis[adjlist[node][i]] == -1)
					continue;
				if (dis[adjlist[node][i]] > cost + 1)
				{
					dis[adjlist[node][i]] = cost+1;
					q.push(make_pair(-(cost+1),adjlist[node][i]));
				}
			}
		}
		for (int i=1;i<n;i++)
		{
			if (dis[i]==INF)
				dis[i] = -1;
			printf("%d ", dis[i]);
		} 
		printf("\n");
	}
}