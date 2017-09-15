//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<int> > adjlist;
std::vector<short> c;
bool dfs(int i,int color)
{
	if(c[i]!=-1)
	{
		if(c[i]==color)
			return 1;
		else
			return 0;
	}
	c[i]=color;
	bool ans=1;
	for(int j=0;j<adjlist[i].size();j++)
	{
		ans=ans&&dfs(adjlist[i][j],(color+1)&1);
	}
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,l;
	int a,b;
	cin>>n;
	while(n!=0)
	{
		cin>>l;
		adjlist=std::vector<std::vector<int> > (n+2);
		c=std::vector<short> (n+2,-1);
		for(int i=0;i<l;i++)
		{
			cin>>a>>b;
			adjlist[a].push_back(b);
			adjlist[b].push_back(a);
		}
		if(dfs(0,0))
		{
			cout<<"BICOLORABLE.\n";
		}
		else
		{
			cout<<"NOT BICOLORABLE.\n";
		}
		cin>>n;
	}	
}