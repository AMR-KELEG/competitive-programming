//AC
#include "bits/stdc++.h"
using namespace std;
int n;
std::vector<std::vector<int> > adjlist;

long double solve(int node=1,int p=-1)
{
	if(adjlist[node].size()==1 && p!=-1)
		return 0;
	long double ways = int(adjlist[node].size())-1;
	if(p==-1)
		ways++;
	long double ans =0;
	for(auto ch: adjlist[node])
	{
		if(ch == p) continue;
		ans += 1+solve(ch,node);
	}
	return ans/ways;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	adjlist = std::vector<std::vector<int> > (n+1);
	for(int i=1,u,v;i<n;i++)
	{
		cin>>u>>v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	if(n==1)
		cout<<0;
	else
		cout<<fixed<<setprecision(9)<<solve();
}