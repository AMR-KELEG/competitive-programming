//AC
#include "bits/stdc++.h"
using namespace std;
int n;

// LCA
std::vector<std::vector<int> > adj_list;
int depth[100001];
std::vector<std::vector<int> > L;

// Specific for this problem
unordered_map<int,int> connected_nodes [100001];
int no_of_connected_nodes[100001];

int dfs(int node=1,int parent=-1,int dep=0)
{
	depth[node]=dep;
	L[node][0]=parent;
	int no_con =0;
	for(auto ch:adj_list[node])
	{
		if(ch==parent)
			continue;
		int child_nodes = dfs(ch,node,dep+1);
		no_con+=child_nodes;
		connected_nodes[node][ch] = child_nodes;
		no_of_connected_nodes[node]+=child_nodes;
	}
	return no_con+1;
}

void prepare()
{
	// depth = std::vector<int> (n+1,0);
	// connected_nodes = std::vector<unordered_map<int,int>> (n+1);
	// no_of_connected_nodes = std::vector<int> (n+1,0);
	L = std::vector<std::vector<int> > (n+1,std::vector<int> (18,-1));
	for(int node=1;node<=n;node++)
		connected_nodes[node].reserve(100);
	dfs();
	for(int node=1;node<=n;node++)
	{
		int parent = L[node][0];
		if(parent == -1)
			continue;
		connected_nodes[node][parent] = n-1-no_of_connected_nodes[node];
		no_of_connected_nodes[node] = n-1;
	}
	for(int lev =1 ;lev<18;lev++)
	{
		for(int node = 1;node<=n;node++)
		{
			if(L[node][lev-1] ==-1)
				continue;
			L[node][lev]=L[ L[node][lev-1] ][lev-1];
		}
	}
}

int LCA(int p,int q)
{
	if(depth[p]<depth[q])
		swap(p,q);
	int lo;
	for(lo=1;1<<lo <=depth[p];lo++);
	lo--;
	int i;
	for(i=lo; i>=0;i--)
		if(depth[p]-(1<<i) >=depth[q])
			p=L[p][i];
	if(p==q)
		return p;
	for(i=lo; i>=0;i--)
		if(L[p][i]!=-1 && L[p][i]!=L[q][i])
			p=L[p][i],q=L[q][i];
	return L[p][0];
}

int dis(int a,int b,int lca = -1)
{
	if(lca==-1) lca = LCA(a,b);
	return depth[a]+depth[b]-(2*depth[lca]);
}

int anc_at_level(int node,int level)
{
	if(level == 0)
		return node;
	for(int i=17;i>=0;i--)
	{
		if(1<<i <=level)
		{
			node = L[node][i];
			level -= (1<<i);
			break;
		}
	}
	return anc_at_level(node,level);
}

int solve(int a,int b)
{
	if(a==b)
		return n;
	// Find distance between a and b
	int d = dis(a,b);
	// If odd dis 
	if(d%2)
		return 0;
	// If even , find no of connected nodes
	// Find center of path at first
	int lca = LCA(a,b);
	int d1 = dis(a,lca,lca);
	int d2 = dis(b,lca,lca);
	if(d1==d2)
	{
		//center is lca
		// exclude 
		int node1 = anc_at_level(a,d1-1);
		int node2 = anc_at_level(b,d2-1);
		return n - connected_nodes[lca][node1]- connected_nodes[lca][node2];
	}
	if(d1<d2)
	{
		swap(d1,d2);
		swap(a,b);
	}
	int node2 = anc_at_level(a,(d/2)-1);
	int center = anc_at_level(node2,1);
	int node1 = anc_at_level(center,1);
	return n - connected_nodes[center][node1]- connected_nodes[center][node2];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	scanf("%d",&n);
	adj_list = std::vector<std::vector<int> > (n+1);
	for(int i=0,a,b;i<n-1;i++)
	{
		scanf("%d%d",&a,&b);
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	prepare();
	int m;
	int a,b;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n", solve(a,b));
	}
}