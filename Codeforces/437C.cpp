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
	std::vector<int> weight(n+5);
	priority_queue<pair<int,int>,std::vector<pair<int,int>> ,greater<pair<int,int>> >q;
	for(int i=1;i<=n;i++)
	{
		cin>>weight[i];
		q.push(pair<int,int>(weight[i],i));
	}	
	std::vector<std::vector<int> > adjmat(n+5,std::vector<int> (n+5,0));

	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		adjmat[u][v]+=weight[u];
		adjmat[v][u]+=weight[v];
	}

	long long int totalw=0;
	while(!q.empty())
	{
		u=q.top().second;
		q.pop();
		for(int i=1;i<=n;i++)
		{
			totalw+=adjmat[u][i];
			adjmat[u][i]=0;
			adjmat[i][u]=0;
		}
	}
	cout<<totalw;




}