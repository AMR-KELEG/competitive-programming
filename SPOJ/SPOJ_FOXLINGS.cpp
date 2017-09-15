//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> par;

int find(int node)
{
	if(par[node]==node)
		return node;
	return par[node]=find(par[node]);
}
void merge(int a,int b)
{
	int pa=find(a);
	int pb=find(b);
	if(find(a)!=find(b))
	{
		par[pb]=pa;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	int a,b;
	int newNodeNo = 0;
	unordered_map<int,int> trans;
	std::vector<pair<int,int>> edges(m);
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		if(trans.find(a)==trans.end())
		{
			trans[a]=newNodeNo++;
		}
		if(trans.find(b)==trans.end())
		{
			trans[b]=newNodeNo++;
		}
		a=trans[a];
		b=trans[b];
		edges[i].first=a;
		edges[i].second=b;
	}	
	par = std::vector<int> (newNodeNo);
	for(int i=0;i<newNodeNo;i++) par[i]=i;
	for(int i=0;i<edges.size();i++)
	{
		merge(edges[i].first,edges[i].second);
	}
	int ans = n - newNodeNo;
	set<int>s;
	for(int i=0;i<newNodeNo;i++)
	{
		s.insert(find(i));
	}
	cout<<ans+s.size();
}