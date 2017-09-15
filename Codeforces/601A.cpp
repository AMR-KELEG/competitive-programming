//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	//100*100 -> 160,000
	bool adjrail[405][405]={};
	bool adjvh[405][405]={};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
				adjvh[i][j]=1;
		}
	}
	//std::vector<std::vector<int> >adjvh=vector<std::vector<int> >(n+5,std::vector<int> ());
	//std::vector<std::vector<int> >adjrail=vector<std::vector<int> >(n+5,std::vector<int> ());
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		adjrail[u][v]=1;//
		adjrail[v][u]=1;//
		adjvh[u][v]=0;
		adjvh[v][u]=0;
	}

	
	queue<pair<int,int> >q;
	std::vector<bool> vis(n+5,0);
	q.push(pair<int,int>(1,0));
	
	int lr=-1;
	int l;
	while(!q.empty())
	{
		u=q.front().first;
		l=q.front().second;
		q.pop();
		vis[u]=1;
		if(u==n)
		{
			lr=l;
			while(!q.empty())
				q.pop();
			break;
		}
		for(int it=1;it<=n;++it)
		{
			if(adjrail[u][it] && !vis[it])
			{
				q.push(pair<int,int>(it,l+1));
				vis[it]=1;
			}
		}
	}
	vis=std::vector<bool> (n+5,0);
	q.push(pair<int,int>(1,0));
	int lv=-1;
	while(!q.empty())
	{
		u=q.front().first;
		l=q.front().second;
		q.pop();
		vis[u]=1;
		if(u==n)
		{
			lv=l;
			while(!q.empty())
				q.pop();
			break;
		}
		for(int it=1;it<=n;++it)
		{
			if(adjvh[u][it] && !vis[it])
			{
				q.push(pair<int,int>(it,l+1));
				vis[it]=1;
			}
		}
	}

	if(lr==-1 || lv==-1)
		cout<<-1;
	else
		cout<<max(lr,lv);

}