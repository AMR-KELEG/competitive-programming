//AC
// Try vis here??
#include "bits/stdc++.h"
#define INF 1000000000
#define Path pair<pair<int,int>,bool>
using namespace std;
int n;
std::vector<int> a;
std::vector<std::vector<int> > adjlist;
std::vector<int> ans;
set<Path> vis;

void solve(int node=0,int par =-1,int gcd = 0, bool done =0)
{
	// cout<<node<<" Still can take: "<<path_ans.first<<" Done taking: "<<path_ans.second<<endl;
	if(vis.find({{node,gcd},done}) !=vis.end())
		return ;
	vis.insert({{node,gcd},done});
	ans [node] =max(ans[node], __gcd(gcd,a[node]));
	
	for(auto ch:adjlist[node])
	{
		if(ch == par)
		{
			continue;
		}
		solve(ch,node,__gcd(gcd,a[node]),done);
	}

	if (!done)
	{
		ans [node] = max(ans[node], gcd);
		for(auto ch:adjlist[node])
		{
			if(ch == par)
			{
				continue;
			}
			solve(ch,node,gcd,1);
		}
	}


}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	a = std::vector<int> (n);
	ans = std::vector<int> (n,1);
	adjlist = std::vector<std::vector<int> > (n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		u--;v--;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	if (n==1)
	{
		cout<<a[0];
	}
	else
	{
		solve(); 
		for(int i=0;i<n;i++)
			printf("%d ", ans[i]);
	}
}