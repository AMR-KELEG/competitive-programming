/* AC
   Second MST
*/
#include "bits/stdc++.h"
using namespace std;
std::vector<pair<int,pair<int,int>>> adjList[501]; // CH, COST, INDX
int vis[501];
bool is_MST_edge[50001]={};
bool bad_edges[50001]={};
int trial = 1;
int N, M;
int EDGE_COST[50001]={};
int NODE_COST[501];
#define INF 0x3f3f3f3f
int MST()
{
	memset(NODE_COST, INF, sizeof NODE_COST);
	int mstCost =0;
	priority_queue<pair<int,pair<int,int>>>q;
	q.push({0,{1,-1}});
	while(!q.empty())
	{
		int cur_cost = -q.top().first;
		int cur_node = q.top().second.first;
		int edge_indx = q.top().second.second;
		q.pop();
		if (vis[cur_node] == trial)
			continue;
		vis[cur_node] = trial;
		mstCost += cur_cost;
		if (edge_indx!=-1)
		{
			is_MST_edge[edge_indx] = 1;
		}
		for (int i=0;i<adjList[cur_node].size();i++)
		{
			int cur_edge_indx = adjList[cur_node][i].second.second;
			int ch = adjList[cur_node][i].first;
			int cur_cost= adjList[cur_node][i].second.first;
			if (bad_edges[cur_edge_indx])
				continue;
			if (vis[ch] == trial)
				continue;
			if (NODE_COST[ch] <= cur_cost)
				continue;
			NODE_COST[ch] = cur_cost;
			q.push({-cur_cost,{ch,cur_edge_indx}});
		}
	}
	for (int i=1;i<=N;i++)
	{
		if (vis[i] !=trial)
			return -1;
	}
	return mstCost;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	scanf("%d %d", &N, &M);
	for (int i=0,u,v,c;i<M;i++)
	{
		scanf("%d %d %d", &u,&v,&c);
		adjList[u].push_back({v,{c,i}});
		adjList[v].push_back({u,{c,i}});
		EDGE_COST[i] =c;		
	}
	// FIND MST
	int MST_cost = MST();
	// EXTRACT EDGES_INDX
	std::vector<int> MST_EDGES;
	for (int i=0;i<M;i++)
	{
		if (is_MST_edge[i])
			MST_EDGES.push_back(i);
	}

	int no_of_bridges =0;
	int bridges_cost = 0;
	// FOR EACH EDGE REMOVE AND FIND MST
	for (auto temp: MST_EDGES)
	{
		trial++;
		bad_edges[temp] = 1;
		int cur_MST = MST();
		if (cur_MST == -1 || cur_MST> MST_cost)
		{
			no_of_bridges++;
			bridges_cost+= EDGE_COST[temp];
		}
		bad_edges[temp] = 0;
	}
	printf("%d %d\n", no_of_bridges, bridges_cost);
}
