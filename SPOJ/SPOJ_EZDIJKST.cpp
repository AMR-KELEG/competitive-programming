//AC
#include "bits/stdc++.h"
#define inf 1000000000
using namespace std;
std::vector<std::vector<int> > dis;
std::vector<std::vector<pair<int,int> > > adjlist;
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	int n,m;
	int a,b,c,st,de;
	int curnode,curdis;
	while(t--)
	{
		cin>>n>>m;
		dis=vector<std::vector<int> >(n+3,std::vector<int> (n+3,inf));
		adjlist=vector<std::vector<pair<int,int> > >(n+3);
		for(int i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			adjlist[a].push_back(pair<int,int>(c,b));
		}
		cin>>st>>de;
		// sort edges according to the shortest path
		priority_queue<pair<int,int>,std::vector<pair<int,int> > ,greater<pair<int,int> > >q;
		for(int i=0;i<adjlist[st].size();i++)
		{
			q.push(adjlist[st][i]);
		}


		while(!q.empty())
		{
			curdis=q.top().first;
			curnode=q.top().second;
			q.pop();
			if(dis[st][curnode]>curdis)
			{
				dis[st][curnode]=curdis;
				for(int i=0;i<adjlist[curnode].size();i++)
				{
					q.push(pair<int,int>(adjlist[curnode][i].first+curdis,adjlist[curnode][i].second));
				}
			}
		}
		if(dis[st][de]!=inf)
			cout<<dis[st][de]<<endl;
		else
			cout<<"NO\n";
	}	
}