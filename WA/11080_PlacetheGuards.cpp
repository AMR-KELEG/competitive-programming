//not right
#include "bits/stdc++.h"
using namespace std;
std::vector<bool> visited;
std::vector<vector<int> > adjl;
bool dfs(int i,int p)
{
	if(visited[i])
		return 0;
	visited[i]=1;
	for(int it=0;it<adjl[i].size();it++)
	{
		if(adjl[i][it]==p)
			continue;
		if(!dfs(adjl[i][it],i))
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	int v,e,f,s;
	int m;
	while(t--)
	{
		m=0;
		cin>>v>>e;
		visited=std::vector<bool> (v,0);
		adjl=vector<vector<int> > (v);
		while(e--)
		{
			cin>>f>>s;
			adjl[f].push_back(s);
			adjl[s].push_back(f);
		}
		for(int i=0;i<v;i++)
		{
			if(!visited[i])
			{
				if(dfs(i,-1))
				{
					m++;
				}
				else
				{
					m=-1;
					break;
				}
			}
		}
		cout<<m<<endl;
	}

}