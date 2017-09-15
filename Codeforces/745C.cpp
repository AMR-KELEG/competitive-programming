//AC
#include "bits/stdc++.h"
using namespace std;
int n,m,k;
std::vector<bool> isGov;
std::vector<int> par;
std::vector<int> edges;
std::vector<bool> hasGov;
int find(int i)
{
	if(i==par[i])return i;
	return par[i]=find(par[i]);
}
void join(int a,int b)
{
	int pa=find(a),pb=find(b);
	if(pa==pb)
	{
		edges[pa]++;
		return;
	}
	if(pa<pb)
	{
		//Join b in a
		hasGov[pa]=hasGov[pb]||hasGov[pa];
		edges[pa]+=1+edges[pb];
		edges[pb]=0;
		hasGov[pb]=0;
		par[pb]=pa;
	}
	else
	{
		hasGov[pb]=hasGov[pa]||hasGov[pb];
		edges[pb]+=1+edges[pa];
		edges[pa]=0;
		hasGov[pa]=0;
		par[pa]=pb;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>m>>k;
	isGov=std::vector<bool> (n+1,0);
	par=std::vector<int> (n+1,0);
	edges=std::vector<int> (n+1,0);
	hasGov=std::vector<bool> (n+1,0);
	for(int i=0,node;i<k;i++)
	{
		cin>>node;
		isGov[node]=1;
	}
	for(int i=1;i<=n;i++)
	{
		par[i]=i;
		hasGov[i]=isGov[i];
	}
	for(int i=0,u,v;i<m;i++)
	{
		cin>>u>>v;
		join(u,v);
	}

	map<int,int>setSizes;
	for(int i=1;i<=n;i++)
	{
		setSizes[find(i)]++;
	}
	long long int ans=0;
	int maxGov=0;
	int totalnonGov=0;
	for(auto p:setSizes)
	{
		int ed=edges[p.first];
		ans+=(((p.second)*(p.second-1))/2)-ed;
		if(hasGov[p.first])
		{
			maxGov=max(maxGov,p.second);
		}
		else
		{
			ans+=((totalnonGov)*(p.second));
			totalnonGov+=p.second;
		}
	}
	ans+=maxGov*totalnonGov;
	cout<<ans;

}