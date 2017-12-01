//AC
#include <bits/stdc++.h>
#define edge pair<int,pair<int,int> >
using namespace std;
int par[100001];
int setSize[100001]={};

int findp(int in)
{
	if(in==par[in])return in;
	par[in]=findp(par[in]);
	setSize[in]=setSize[par[in]];
	return par[in];
}

void merge(int a,int b)
{
	int pa=findp(a);
	int pb=findp(b);
	if(pa==pb)return;
	setSize[pa]=setSize[pa]+setSize[pb];
	setSize[pb]=setSize[pa];
	par[pa]=pb;
}

int main()
{
	ios::sync_with_stdio(0);
	for(int i=0;i<100001;i++)
		par[i]=i,setSize[i]=1;
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int u,v;
	priority_queue<edge>q;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		u--,v--;
		q.push({min(a[u],a[v]),{u,v}});
	}
	long long int totalW=0;
	while(!q.empty())
	{
		long long int cost=q.top().first;
		u=q.top().second.first;
		v=q.top().second.second;
		q.pop();
		if(findp(u)==findp(v))
		{
			continue;
		}
		long long int sa=setSize[findp(u)];
		long long int sb=setSize[findp(v)];
		totalW+=(sa*sb)*cost;
		merge(u,v);
	}
	long double val=totalW;
	val/=(((long long int)n)*(n-1))/2.;
	cout<<fixed<<setprecision(6)<<val;
}
