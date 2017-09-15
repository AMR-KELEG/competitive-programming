//AC -- Is it a tree?
#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<int> > adjlist ;
std::vector<bool> vis;
long long int counter=0;
void dfs(int i)
{
	if(vis[i])
		return;
	vis[i]=1;
	counter++;
	for(int j=0;j<adjlist[i].size();j++)
		dfs(adjlist[i][j]);
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	adjlist =std::vector<std::vector<int> > (n+5);
	vis=std::vector<bool>(n+5,0);
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}	
	dfs(u);
	if(m==(n-1) && counter==n)
		cout<<"YES";
	else
		cout<<"NO";

}