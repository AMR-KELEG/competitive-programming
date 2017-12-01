// WA
#include "bits/stdc++.h"
#define INF 1000000000000000000LL
using namespace std;
std::vector<std::vector<pair<int,int>> > adjlist;
std::vector<long long int> t;
std::vector<long long int> c;
std::vector<long long int> reach_cost;

std::vector<int> vis;
int cur_case = 1;
priority_queue<pair<long long int,int>>q;
void propagte(int node, long long int cur_cost, int rem_des)
{
	if (rem_des<0)
		return ;
	vis[node] = cur_case;
	if (cur_cost < reach_cost[node])
	{
		q.push({-(cur_cost+ c[node]),node});
		reach_cost[node] = cur_cost;
	}
	for (int ch=0;ch<adjlist[node].size();ch++)
	{
		int ch_node = adjlist[node][ch].first;
		int edge_cost = adjlist[node][ch].second;
		if (vis[ch_node] == cur_case)
			continue;
		propagte(ch_node, cur_cost, rem_des - edge_cost);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int	n,m;
	cin>>n>>m;
	adjlist = std::vector<std::vector<pair<int,int>> > (n+1);
	t = std::vector<long long int> (n+1);
	c = std::vector<long long int> (n+1);
	reach_cost = std::vector<long long int> (n+1,INF);
	vis = std::vector<int> (n+1,0);
	int st,des;
	cin>>st>>des;
	if (st == des)
	{
		cout<<0;
		return 0;
	}
	while(m--)
	{
		int u,v,co;
		cin>>u>>v>>co;
		bool rep = 0;
		for (int j=0;j<adjlist[u].size();j++)
		{
			if (adjlist[u][j].first == v)
			{
				rep = 1;
				if (co > adjlist[u][j].second)
					break;
				adjlist[u][j].second = co;
				for (int i=0;i<adjlist[v].size();i++)
				{
					if (adjlist[v][i].first == u)
					{
						adjlist[v][i].second = co;
					}
				}
				break;
			}
		}
		if (!rep)
			adjlist[u].push_back({v,co});
			adjlist[v].push_back({u,co});
	}
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>c[i];
	}
	reach_cost[st] = 0;
	q.push({0,st});
	while(!q.empty())
	{
		int cur_st = q.top().second;
		long long int cur_cost = -q.top().first;
		q.pop();
		if (reach_cost[cur_st] + c[cur_st]< cur_cost)
			continue;
		propagte(cur_st, reach_cost[cur_st] + c[cur_st], t[cur_st]);
		cur_case ++;
	}
	if (reach_cost[des] == INF)
		cout<<-1;
	else
		cout<<reach_cost[des];
}