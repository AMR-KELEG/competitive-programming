//AC
#include "bits/stdc++.h"
#define INF (100000007)
using namespace std;
std::vector<int> par;
int find(int node)
{
	if(par[node]==node)
		return par[node];
	return par[node]=find(par[node]);
}
void join(int a,int b)
{
	int pa=find(a);int pb=find(b);
	if(pa==pb)
		return ;
	if(pa<pb)
	{
		par[pb]=pa;
	}
	else
	{
		par[pa]=pb;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m,k;
	cin>>n>>m>>k;
	par=std::vector<int> (n+1);
	std::vector<int> t(k);
	for(int i=0;i<=n;i++)
	{
		par[i]=i;
	}
	std::vector<int> c(k);
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		if(i==0)
			t[i]=c[i];
		else
			t[i]=t[i-1]+c[i];
	}
	int x,y,co;
	priority_queue<pair<int,pair<int,int>>>q;//-cost x y
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>co;
		if(co==0)
			join(x,y);
		else
			q.push({-co,{x,y}});
	}
	int cur=1;
	for(int type=0;type<k;type++)
	{
		int p=find(cur);
		for(int i=0;i<c[type];i++)
		{
			if(find(cur+i)!=p)
			{
				cout<<"No";
				return 0;
			}
		}
		cur+=c[type];
	}

	printf("Yes\n");
	std::vector<std::vector<int> > dis(k+1,std::vector<int> (k+1,INF));
	for(int i=1;i<=k;i++)
		dis[i][i]=0;

	cur=1;
	map<int,std::vector<int>> mp;
	for(int t=0;t<k;t++)
	{
		int p=find(cur);
		if(mp.find(p)!=mp.end())
		{
			for(auto d:mp[p])
				dis[t+1][d]=dis[d][t+1]=0;
		}
		mp[p].push_back(t+1);
		cur+=c[t];
	}
	while(!q.empty())
	{
		co=-q.top().first;
		x=q.top().second.first;
		y=q.top().second.second;
		q.pop();
		int px=find(x);
		int py=find(y);
		//you need to find the type
		if(px==py)
			continue;
		px=1+(lower_bound(t.begin(), t.end(),x)-t.begin());
		py=1+(lower_bound(t.begin(), t.end(),y)-t.begin());
		// cout<<px<<" "<<py<<endl;
		if(dis[px][py]>co)
		{
			dis[px][py]=dis[py][px]=co;
			for(int st=1;st<=k;st++)
			{
				for(int et=st+1;et<=k;et++)
				{
					if(dis[st][px]+dis[px][py]+dis[py][et]<dis[st][et])
					{
						dis[st][et]=dis[et][st]=dis[st][px]+dis[px][py]+dis[py][et];
					}
					if(dis[st][py]+dis[px][py]+dis[px][et]<dis[st][et])
					{
						dis[st][et]=dis[et][st]=dis[st][py]+dis[px][py]+dis[px][et];
					}
				}
			}	
		}
	}

	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(dis[i][j]>=INF)
				dis[i][j]=-1;
			printf("%d ", dis[i][j]);
		}
		printf("\n");
	}
}