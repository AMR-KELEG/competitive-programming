//AC
#include "bits/stdc++.h"
using namespace std;
int n,m;
std::vector<std::vector<int> > adjlist;
std::vector<int> col;
bool en=0;
int ca=0,cb=0;
void dfs(int i,int c)
{
	col[i]=c;
	if(c==0)
		ca++;
	else
		cb++;
	for(int j=0;j<adjlist[i].size();j++)
	{
		if(col[adjlist[i][j]]==-1)
		{
			dfs(adjlist[i][j],!c);
		}
		else if(col[adjlist[i][j]]!=(!c))
		{
			// cout<<-1;
			en=1;
			return ;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>m;	
	adjlist=std::vector<std::vector<int> > (n+1);
	col=std::vector<int> (n+1,-1);
	set<int>nodes;
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		nodes.insert(u);
		nodes.insert(v);
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	for(set<int>::iterator it=nodes.begin();it!=nodes.end();it++)
	{
		if(col[*it]==-1)
		{
			dfs(*it,0);
		}
		if(en)
		{
			cout<<-1;
			return 0;
		}
	}
	printf("%d\n",ca );
	for(int i=1;i<=n;i++)
	{
		if(col[i]==0)
			printf("%d ", i);
	}
	printf("\n%d\n",cb );
	for(int i=1;i<=n;i++)
	{
		if(col[i]!=-1 && col[i]!=0)
			printf("%d ", i);
	}
}