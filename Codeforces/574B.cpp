//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	std::vector< set<int> > adjlist(n+2);
	std::vector<int> con(n+2,0);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		con[u]++;
		con[v]++;
		if(u<v)
			adjlist[u].insert(v);
		else
			adjlist[v].insert(u);
	}

	int minweight=INT_MAX;
	for(int f=1;f<=n;f++)
	{
		for(set<int>::iterator it=adjlist[f].begin();it!=adjlist[f].end();++it)
		{
				for(set<int>::iterator t=adjlist[*it].begin();t!=adjlist[*it].end();++t)
				{
					if(adjlist[f].find(*t)!=adjlist[f].end())
					{
						//cycle
						int w=con[f]+con[*it]+con[*t]-6;
						//cout<<w<<" "<<f<<" "<<*it<<" "<<*t<<endl;
						minweight=min(w,minweight);
					}
				}
			
		}
	}	
	if(minweight==INT_MAX)
		cout<<-1;
	else
		cout<<minweight;
}