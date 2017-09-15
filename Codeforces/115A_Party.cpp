#include "bits/stdc++.h"
using namespace std;
vector < set<int> >children;
int max_groups=0;
set<int>::iterator it;
void dfs(int node,int no_groups)
{
	if(no_groups>max_groups)max_groups=no_groups;

	for(set<int>::iterator it=children[node].begin();it!=children[node].end();it++)
	{
		dfs(*(it),no_groups+1);
	}
}
int main()
{
	int n;
	cin>>n;
	children.resize(n+1);
	int p;
	for(int i=1;i<=n;i++)
	{
		cin>>p;
		if(p!=-1)
		{
			children[p].insert(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,1);
	}
	cout<<max_groups;
	return 0;
}