//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<int> > adjList;
std::vector<std::vector<int> > parent_at_level;
std::vector<int> level;
std::vector<int> visits;
std::vector<int> val;
int n;
void dfs(int node=0,int l=0)
{
	level[node] = l;
	for(auto ch:adjList[node])
	{
		if(ch == parent_at_level[node][0])
			continue;
		parent_at_level[ch][0] = node;
		dfs(ch,l+1);
	}
}

void prepare()
{
	dfs();
	for(int l=1;l<18;l++)
	{
		for(int node=0; node<n;node++)
		{
			if(parent_at_level[node][l-1] == -1)
				continue;
			parent_at_level[node][l] = parent_at_level[parent_at_level[node][l-1]][l-1];
		}
	}
}

int LCA(int p,int q)
{
	if(level[p]<level[q])
		swap(p,q);
	int lo;
	for(lo = 1; 1<<lo <=level[p];lo++);
	lo--;
	int i;
	for(i=lo;i>=0;i--)
	{
		if(level[p]-(1<<i) >= level[q])
			p = parent_at_level[p][i];
	}
	if(p==q)
		return p;
	for(i = lo;i>=0 ; i--)
	{
		if(parent_at_level[p][i]!=-1 && parent_at_level[p][i] != parent_at_level[q][i])
			p=parent_at_level[p][i],q=parent_at_level[q][i];
	}
	return parent_at_level[p][0];
}

void add_path(int a,int b)
{

	int lca = LCA(a,b);
	if(lca == a || lca == b)
	{
		val[lca]-= 1;
		val[a+b-lca]+= 1;
		return;
	}
	val[lca]-= 2;
	val[a]+= 1;
	val[b]+= 1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	adjList = std::vector<std::vector<int> > (n);
	level = std::vector<int> (n,0);
	val = std::vector<int> (n,0);
	parent_at_level = std::vector<std::vector<int> > (n,std::vector<int> (18,-1));
	visits = std::vector<int> (n-1);
	map<pair<int,int>, int> edgelist;
	std::vector<int> no_edges(n,0);
	for(int i=0,a,b;i<n-1;i++)
	{
		cin>>a>>b;
		a--;b--;
		no_edges[a]++;
		no_edges[b]++;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
		edgelist[{min(a,b),max(a,b)}] = i;
	}
	prepare();
	int k;
	cin>>k;
	int a,b;
	while(k--)
	{
		cin>>a>>b;
		a--;b--;
		add_path(a,b);
	}
	queue<int>q;
	for(int i=0;i<n;i++)
	{
		if(no_edges[i]==1)
			q.push(i);
	}
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		if(node==0)
			continue;
		int ans = val[node];
		int p = parent_at_level[node][0];
		visits[edgelist[{min(node,p),max(node,p)}]] = ans;
		val [p]+=ans;
		no_edges[p]--;
		if(no_edges[p] == 1)
			q.push(p);
	}
	for(int i=0;i<visits.size();i++)
	{
		printf("%d ", visits[i]);
	}
}