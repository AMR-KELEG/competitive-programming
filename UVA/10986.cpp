//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		int n,m,s,t;
		cin>>n>>m>>s>>t;
		std::vector<vector<pair<int,int> > > adjlist(n);
		long long int u,v,w,d;
		for(int i=0;i<m;i++)
		{
			cin>>u>>v>>w;
			adjlist[u].push_back(pair<int,int>(w,v));
			adjlist[v].push_back(pair<int,int>(w,u));
		}
		if(s==t)
		{
			cout<<"Case #"<<T<<": "<<0<<endl;
			continue;
		}
		std::vector<long long> dis(n,1000000000000LL);
		dis[s]=0;
		priority_queue<pair<long long,long long>,std::vector<pair<long long,long long> >,greater<pair<long long,long long> > >q;
		for(int i=0;i<adjlist[s].size();i++)
			q.push(adjlist[s][i]);
		while(!q.empty())
		{
			d=q.top().first;
			u=q.top().second;
			q.pop();
			if(u==t)
			{
				dis[t]=d;
				// cout<<"Case #"<<T<<": "<<d<<endl;
				while(!q.empty())
					q.pop();
				break;
			}
			if(dis[u]<1000000000000LL)
				continue;
			dis[u]=d;
			for(int i=0;i<adjlist[u].size();i++)
			{
				v=adjlist[u][i].second;
				d=dis[u]+adjlist[u][i].first;
				if(dis[v]==1000000000000LL)
					q.push(pair<long long,long long>(d,v));
			}
		}
		if(dis[t]==1000000000000LL)
		{
			cout<<"Case #"<<T<<": unreachable\n";
		}	
		else
		{
			cout<<"Case #"<<T<<": "<<d<<endl;
		}
	}	
}