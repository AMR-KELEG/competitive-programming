//AC
#include "bits/stdc++.h"
#define INF 1000000000
using namespace std;

int t=1;
std::vector<std::vector<pair<int,int> > > adjlist;
int n,m,c,k;
int cost[251];

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>m>>c>>k;
	while (! (n==0 && m==0 && c==0 && k==0))
	{
		adjlist = std::vector<std::vector<pair<int,int> > > (n);
		for(int i=0;i<m;i++)
		{
			int u,v,co;
			cin>>u>>v>>co;
			if (u>v)
				swap(u,v);
			adjlist[u].push_back({v,co});
			adjlist[v].push_back({u,co});
			if (v<c && u==v-1)
			{
				cost[u] = co;
			}
		}
		priority_queue<pair<int,int>>q; // -c , n
		if (k==c-1)
		{
			cout<<0<<endl;
		}
		else
		{
			if (k<c)
			{
				q.push({-cost[k],k+1});
			}
			else
			{
				for (int i=0;i<adjlist[k].size();i++)
				{
					q.push({-adjlist[k][i].second,adjlist[k][i].first});
				}
			}
			std::vector<bool> vis(n,0);
			vis[k]=1;
			while (!q.empty())
			{
				int co = -q.top().first;
				int node = q.top().second;
				q.pop();
				if (node == c-1)
				{
					cout<<co<<endl;
					break;
				}
				if (vis[node])
					continue;
				vis[node]=1;
				if (node<c)
				{
					q.push({-(co + cost[node]),node+1});
				}
				else
				{
					for (int i=0;i<adjlist[node].size();i++)
					{
						int next_city = adjlist[node][i].first;
						int next_co = adjlist[node][i].second;
						if (vis[next_city])
							continue;
						q.push({-(co + next_co),next_city});		
					}
				}
			}
		}

		t++;
		cin>>n>>m>>c>>k;
	}	
}