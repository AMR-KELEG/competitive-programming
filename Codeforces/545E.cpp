/* AC
   Sorting - MST
*/
#include "bits/stdc++.h"
using namespace std;
#define State pair<long long, pair<int,pair<int,int> > >
#define LEN first
#define EDGE second.first
#define NODE second.second.first
#define INDX second.second.second
#define INF 0x3F3F3F3F
int tree_edges[300001];
int cur_tree_indx = 0;
int edge_to_reach[300001];
bool vis[300001]={};
std::vector<pair<int,int> > adjlist[300001];
int weight[300001];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(edge_to_reach, INF, sizeof edge_to_reach);
	int n,m;
	scanf("%d %d", &n, &m);
	for (int _=0,u,v,w;_<m;_++)
	{
		scanf("%d %d %d", &u, &v, &w);
		adjlist[u].push_back({v, _});
		adjlist[v].push_back({u, _});
		weight[_] = w;
	}
	int root;
	long long int min_tree_cost = 0;
	scanf("%d", &root);
	edge_to_reach[root] = 0;
	priority_queue<State>q;
	q.push({0, {0, {root, -1}}});
	while(!q.empty())
	{
		State cur_s = q.top();
		int cur_node = cur_s.NODE;
		q.pop();
		if (vis[cur_node])
			continue;
		vis[cur_node] = 1;
		min_tree_cost -= cur_s.EDGE;
		tree_edges[cur_tree_indx++] = cur_s.INDX;
		edge_to_reach[cur_node] = -cur_s.EDGE;
		for (int i=0;i<adjlist[cur_node].size();i++)
		{
			if (vis[adjlist[cur_node][i].first])
			{
				continue;
			}
			// find weight of this node
			State new_state = cur_s;
			new_state.NODE = adjlist[cur_node][i].first;
			new_state.INDX = adjlist[cur_node][i].second;
			new_state.EDGE = -weight[new_state.INDX];
			new_state.LEN += new_state.EDGE;
			if (-new_state.EDGE >= edge_to_reach[new_state.NODE])
				continue;
			edge_to_reach[new_state.NODE] = -new_state.EDGE;
			q.push(new_state);
		}
	}
	printf("%lld\n", min_tree_cost);
	for (int i=1;i<n;i++)
	{
		printf("%d ", tree_edges[i]+1);
	}
}