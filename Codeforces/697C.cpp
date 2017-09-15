#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	map<pair<long long,long long>,long long int> dis;
	int q;
	cin>>q;
	long long int t,u,v,w;
	while(q--)
	{
		cin>>t;
		if(t==1)
		{
			cin>>u>>v>>w;
			set<long long> vis;
			while(u>1)
			{
				// cout<<u<<endl;
				long long p=u/2;
				vis.insert(u);
				dis[pair<long long,long long>(p,u)]+=w;
				u=p;
			}
			// cout<<"v\n";
			while(v>1)
			{
				// cout<<v<<endl;
				long long p=v/2;
				if(vis.find(v)!=vis.end())
				{
					dis[pair<long long,long long>(p,v)]-=w;
				}
				else
				{
					dis[pair<long long,long long>(p,v)]+=w;	
				}
				v=p;
			}
		}
		else
		{
			cin>>u>>v;
			long long int ans=0;
			set<long long> vis;
			while(u>1)
			{
				long long p=u/2;
				vis.insert(u);
				ans+=dis[pair<long long,long long>(p,u)];
				u=p;
			}
			while(v>1)
			{
				long long p=v/2;
				if(vis.find(v)!=vis.end())
				{
					ans-=dis[pair<long long,long long>(p,v)];
				}
				else
				{
					ans+=dis[pair<long long,long long>(p,v)];	
				}
				v=p;
			}	
			cout<<ans<<endl;
		}
	}	
}