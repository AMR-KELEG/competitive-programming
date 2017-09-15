//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<bool> vis;
std::vector<int> a;
std::vector<int> cur;
std::vector<std::vector<int> > seg;
void dfs(int node)
{
	if(vis[node])
	{
		seg.push_back(cur);
		cur.clear();
		return ;
	}
	vis[node]=1;
	cur.push_back(node+1);
	dfs(a[node]);
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	a = std::vector<int> (n);
	std::vector<int> sorted(n);
	vis = std::vector<bool> (n,0);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sorted[i]=a[i];
	}	
	sort(sorted.begin(), sorted.end());
	map<int,int> mp; // val -> indx
	for(int i=0;i<n;i++)
	{
		mp[sorted[i]] = i;
	}
	for(int i=0; i< n ;i++)
	{
		a[i] = mp[a[i]];
	}
	for(int i=0; i< n ;i++)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
	printf("%d\n", seg.size());
	for(auto v:seg)
	{
		printf("%d ", v.size());
		for(auto el:v)
			printf("%d ", el);
		printf("\n");
	}
}