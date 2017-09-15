//AC
#include "bits/stdc++.h"
using namespace std;
int n,k;
std::vector<std::vector<int> > adjlist;
std::vector<std::vector<int> > v;
std::vector<int> dis;
void update_adjlist(int node)
{
	std::vector<bool> succ(n+1,1);
	for(int p=0;p<k;p++)
	{
		int i=0;
		while(v[p][i]!=node)
		{
			succ[v[p][i]]=0;
			i++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(succ[i] && i!=node)
		{
			adjlist[node].push_back(i);
		}
	}
}
int finddis(int node)
{
	if(dis[node]!=-1)
		return dis[node];
	int d=1;
	for(int i=0;i<adjlist[node].size();i++)
	{
		d=max(d,1+finddis(adjlist[node][i]));
	}
	return dis[node]=d;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>k;
	dis=std::vector<int> (n+1,-1);
	adjlist=std::vector<std::vector<int> >(n+1);
	v=std::vector<std::vector<int> >(k,std::vector<int> (n));
	for(int i=0;i<k;i++)
		for(int j=0;j<n;j++)
			cin>>v[i][j];
	for(int i=1;i<=n;i++)
	{
		update_adjlist(i);
		// cout<<i<<": ";
		// for(int k=0;k<adjlist[i].size();k++)
		// 	cout<<adjlist[i][k]<<" ";
		// cout<<endl;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,finddis(i));
	cout<<ans;
}