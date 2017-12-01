/* AC
- Compress the graph to tree (remove cycles).
- Find the center of the tree.
*/
#include "bits/stdc++.h"
using namespace std;
#define Edge pair<pair<int,int>, int>
#define A first.first
#define B first.second
#define Cost second
#define INF 1000000000
std::vector<std::vector<pair<int,int>> > old_adj;
std::vector<std::vector<pair<int,int> > > adj;
std::vector<long long int> reach_time;
std::vector<int> par;
std::vector<int> vis_time;
unordered_map<int,int> mp;
int cur_time = 0;
int find(int node)
{
	if (node==par[node])
		return node;
	return par[node] = find(par[node]);
}

void merge(int a,int b)
{
	int pa = find(a);
	int pb = find(b);
	if (pa<pb)
	{
		par[pb] = pa;
	}
	else
	{
		par[pa] = pb;
	}
}

int dfs(int node = 1, int p_indx=-1)
{
	// cout<<node<<endl;
	if (vis_time[node]!=INF)
		return vis_time[node];
	mp[cur_time] = node;
	vis_time[node] = cur_time++;
	for (auto ed:old_adj[node])
	{
		int ch = ed.second;
		int indx = ed.first;
		if (indx==p_indx)
			continue;
		vis_time[node] = min(vis_time[node], dfs(ch,indx));
	}
	// find node of vis_time[node]
	merge(node, mp[vis_time[node]]);
	return vis_time[node];
}

pair<long long int, int> find_furthest_node(int node=1, int p=-1)
{
	long long int cost = 0;
	int furthest_ch = node;
	for (auto e:adj[node])
	{
		int ch = e.first;
		if (ch == p)
			continue;
		int edge_cost = e.second;
		pair<long long int, int> cur_val = find_furthest_node(ch, node);
		if (cur_val.first + edge_cost> cost)
		{
			cost = cur_val.first + edge_cost;
			furthest_ch = cur_val.second;
		}		
	}
	return {cost, furthest_ch};
}


bool find_path(int node, int des, long long int path_cost = 0,int p=-1)
{
	reach_time[node] = path_cost;
	if (node==des)
	{
		return 1;
	}
	for (auto e:adj[node])
	{
		int ch = e.first;
		if (ch == p)
			continue;
		if (find_path(ch, des, path_cost+e.second, node))
		{
			return 1;
		}
	}
	reach_time[node] = 1e18;
	return 0;
}
pair<int,long long int> find_capital()
{
	int a = find_furthest_node().second;
	pair<long long int,int> ans =  find_furthest_node(a);
	int b = ans.second;
	long long int diameter = ans.first;
	reach_time = std::vector<long long int> (adj.size(),1e18);
	find_path(a,b);
	// return {0,0};
	int center = 0;
	long long int max_dis = 1e18;
	for (int node=1;node<adj.size();node++)
	{ 
		long long int cur_max_dis = max(diameter - reach_time[node], reach_time[node]);
		if (cur_max_dis<max_dis)
		{
			max_dis = cur_max_dis;
			center = node;
		}
	}

	return {center, max_dis};
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n,m;
		scanf("%d %d", &n, &m);
		if (n==1)
		{
			printf("1 0\n");
			continue;
		}
		mp.clear();
		cur_time = 0;
		old_adj = std::vector<std::vector<pair<int,int> > > (n+1);
		vis_time = std::vector<int> (n+1,INF);
		par = std::vector<int> (n+1);
		for (int node=1;node<=n;node++)
		{
			par[node] = node;
		}
		std::vector<Edge> edges(m);
		for (int i=0,a,b,c;i<m;i++)
		{
			scanf("%d %d %d",&a, &b, &c);
			edges[i] = {{a,b},c};
			old_adj[a].push_back({i,b});
			old_adj[b].push_back({i,a});
		}
		dfs();
		int no_of_nodes = 0;
		unordered_map<int,int> node_to_new_node;
		for (int i=1;i<=n;i++)
		{
			if (i==par[i])
			{
				no_of_nodes++;
				node_to_new_node[i] = no_of_nodes;
			}
			// cout<<i<<" Par: "<<find(i)<<endl;
		}
		if (no_of_nodes == 1)
		{
			printf("1 0\n");
			continue;
		}
		adj = std::vector<std::vector<pair<int,int> > > (no_of_nodes+1);
		for (int i=0;i<m;i++)
		{
			int a = edges[i].A;
			int b = edges[i].B;
			int c = edges[i].Cost;
			int pa = find(a);
			int pb = find(b);
			if (pa==pb)
				continue;
			pa = node_to_new_node[pa];
			pb = node_to_new_node[pb];
			adj[pa].push_back({pb,c});
			adj[pb].push_back({pa,c});
			// cout<<"Edge "<<pa<<" "<<pb<<endl;
		}
		
		pair<int,long long int> cap = find_capital();
		int cur_node = 0;
		for (int i=1;i<=n;i++)
		{
			if (i==par[i])
			{
				cur_node++;
				if (cur_node == cap.first)
				{
					cap.first = i;
					break;
				}
			}
		}
		printf("%d %I64d\n", cap.first, cap.second);
	}

}