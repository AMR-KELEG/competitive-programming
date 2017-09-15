//AC
#include "bits/stdc++.h"
using namespace std;
int n,m;
std::vector<int> sg;
std::vector<std::vector<int> > adjlist;
int solve(int in)
{
	if(in<=0)
		return 0;
	if(sg[in]!=-1)
		return sg[in];
	set<int>nodes;
	for(int i=0;i<adjlist[in].size();i++)
	{
		nodes.insert(solve(adjlist[in][i]));
	}
	for(int i=0;i<=n;i++)
	{
		if(nodes.find(i)==nodes.end())
			return sg[in]=i;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>m;
	sg=std::vector<int> (n+1,-1);
	 adjlist=std::vector<std::vector<int> >(n+1);
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		adjlist[u].push_back(v);
	}

	for(int node=1;node<=n;node++)
	{
		if(sg[node]==-1)
			solve(node);
	}
	int q;
	cin>>q;
	int k;
	int in;
	long long int ans=0;
	for(int i=0;i<q;i++)
	{
		ans=0;
		cin>>k;
		for(int pl=0;pl<k;pl++)
		{
			cin>>in;
			ans=ans^sg[in];
		}
		if(ans==0)
			cout<<"Iroh\n";
		else
			cout<<"Bumi\n";
	}

}