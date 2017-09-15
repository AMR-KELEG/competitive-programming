//AC
#include "bits/stdc++.h"
using namespace std;
int n;
std::vector<std::vector<short> > adjlist;//reversed list
set<short>path;
short ans;
void findpath(short i,bool first=1)
{
	if(first)
	{
		path.insert(i);
		if(i==1)
		{
			return;
		}
		findpath(adjlist[i][0],1);
		return;
	}

	if(path.find(i)!=path.end())
	{
		ans=i;
		return;
	}
	findpath(adjlist[i][0],0);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		printf("Case %d:\n", t);
		// n nodes
		// n lines m -> children
		// q 
		// f s
		cin>>n;
		adjlist=std::vector<std::vector<short> >(n+1);
		int u,m,v;
		for(int i=1;i<=n;i++)
		{
			cin>>m;
			for(int j=0;j<m;j++)
			{
				cin>>v;
				adjlist[v].push_back(i);
			}
		}
		int q;
		cin>>q;
		while(q--)
		{
			cin>>u>>v;
			path.clear();
			findpath(u);
			findpath(v,0);
			printf("%d\n", ans);
		}
	}	
}