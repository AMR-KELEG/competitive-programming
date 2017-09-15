//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<int> > adjlist,in;
std::vector<int> cost;
std::vector<bool> vis;
int dfs(int node,int par,int reverse)
{
	// cout<<node<<endl;
	vis[node]=1;
	int ans=0;
	for(int i=0;i<adjlist[node].size();i++)
	{
		if(adjlist[node][i]==par || vis[adjlist[node][i]])
			continue;	
		ans+=dfs(adjlist[node][i],node,0);
	}
	for(int i=0;i<in[node].size();i++)
	{
		if(in[node][i]==par || vis[in[node][i]])
			continue;
		ans+=dfs(in[node][i],node,1);
	}
	return ans+reverse;
}
void updatecost(int node,int par,int rev)
{
	cost[node]=cost[par]+rev;
	vis[node]=1;
	for(int i=0;i<adjlist[node].size();i++)
	{
		if(adjlist[node][i]==par || vis[adjlist[node][i]])
			continue;	
		updatecost(adjlist[node][i],node,1);
	}
	for(int i=0;i<in[node].size();i++)
	{
		if(in[node][i]==par || vis[in[node][i]])
			continue;
		updatecost(in[node][i],node,-1);
	}
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	adjlist=std::vector<std::vector<int> >(n+2);
	in=std::vector<std::vector<int> >(n+2);
	cost=std::vector<int> (n+2,1<<29);
	vis=std::vector<bool> (n+2,0);
	int a,b;
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		adjlist[a].push_back(b);
		in[b].push_back(a);
	}
	cost[1]=dfs(1,-1,0);
	vis=std::vector<bool> (n+2,0);
	updatecost(1,1,0);
	int mincost=1<<29;
	for(int i=1;i<=n;i++)
	{
		mincost=min(mincost,cost[i]);
		// cout<<i<<" "<<cost[i]<<endl;
	}
	printf("%d\n", mincost);
	for(int i=1;i<=n;i++)
	{
		if(cost[i]==mincost)
			printf("%d ",i);
	}
	/*
	*/
}