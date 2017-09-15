#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<int> > adjlist;
std::vector<long long int> v;
std::vector<bool> vis;
long long int counter=0;
long long int dfs(int node=1)
{

	vis[node]=1;
	long long int childop=0;
	for(int i=0;i<adjlist[node].size();i++)
	{
		if(!vis[adjlist[node][i]])
			childop+=dfs(adjlist[node][i]);
		// cout<<node<<" "<<childop+v[node]<<endl;
	}
	counter+=abs(v[node]+childop);
	cout<<node<<" "<<counter<<endl;
	// cout<<node<<" "<<v[node]+childop<<endl;
	// if(v[node]+childop>0)
	return -v[node];
	// return (v[node]+childop);
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	adjlist=std::vector<std::vector<int> >(n+1);
	vis=std::vector<bool> (n+1,0);
	int a,b;
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	v=std::vector<long long int> (n+1,0);
	for(int i=1;i<=n;i++)
		cin>>v[i];
	dfs();
	cout<<counter;

}