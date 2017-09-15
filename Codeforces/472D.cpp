//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<int> > adjmatrix;
std::vector<std::vector<long long int> > dis;
std::vector<std::vector<pair<int,int> > > adjlist;//node weight
int n;
bool check()
{
	for(int r=0;r<n;r++)
	{
		if(adjmatrix[r][r]!=0)
			return 0;
	}
	for(int r=0;r<n;r++)
	{
		for(int c=0;c<n;c++)
		{
			if(adjmatrix[r][c]!=adjmatrix[c][r])
				return 0;
		}
	}
	return 1;
}
bool check2()
{
	for(int r=0;r<n;r++)
	{
		for(int c=0;c<n;c++)
			if(adjmatrix[r][c]!=dis[r][c] || (r!=c && dis[r][c]==0))
				return 0;
	}
	return 1;
}
int curNode;
void dfs(int node,int par,long long int curW=0)
{
	dis[curNode][node]=curW;
	for(int in=0;in<adjlist[node].size();in++)
	{
		if(adjlist[node][in].first==par)continue;
		dfs(adjlist[node][in].first,node,curW+adjlist[node][in].second);
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	adjmatrix=std::vector<std::vector<int> > (n,std::vector<int> (n));
	adjlist=std::vector<std::vector<pair<int,int> > > (n);
	for(int r=0;r<n;r++)
	{
		for(int c=0;c<n;c++)
		{
			scanf("%d",&adjmatrix[r][c]);
		}
	}
	if(!check())
	{
		cout<<"NO";
		return 0;
	}
	else
	{
		//GET MIN SPANNING TREE
		//ADD EDGES TO ADJLIST
		//DFS FROM ALL NODES TO GET DISMAT
		priority_queue<pair<int,pair<int,int>>>q;//-w u
		q.push({0,{0,0}});
		std::vector<bool> vis(n,0);
		while(!q.empty())
		{
			int w=-q.top().first;
			int u=q.top().second.first;
			int v=q.top().second.second;
			q.pop();
			if(vis[v])
				continue;
			vis[v]=1;
			if(u!=v)
			{
				adjlist[u].push_back({v,w});
				adjlist[v].push_back({u,w});
			}
			for(int i=0;i<n;i++)
			{
				if(i==v)
				{
					continue;
				}
				if(!vis[i])
				{
					//add edge between v and i
					q.push({-adjmatrix[i][v],{v,i}});
					// vis[i]=1;
				}
			}
		}
		dis=std::vector<std::vector<long long int> >(n,std::vector<long long int>(n,0));
		for(int i=0;i<n;i++)
		{
			curNode=i;	
			dfs(i,i);
		}
		if(check2())
			cout<<"YES";
		else
			cout<<"NO";
	}
}