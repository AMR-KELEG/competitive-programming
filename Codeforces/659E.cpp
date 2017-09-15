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
	std::vector<std::vector<int> > adjlist(n+5,std::vector<int> ());	
	std::vector<bool> vis(n+5,0);
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		//cout<<u<<" "<<v<<endl;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
		//for(int i=0;i<adjlist[u].size();i++)
			//cout<<adjlist[u][i]<<endl;
	}
	queue<pair<int,int> >q;
	int notvis=0;
	for(int node=1;node<=n;node++)
	{
		if(vis[node])
			continue;
		q.push(pair<int,int>(node,node));
		int p;
		notvis++;
		while(!q.empty())
		{
			u=q.front().first;
			p=q.front().second;
			vis[u]=1;
			//cout<<u<<endl;
			q.pop();
			for(int i=0;i<adjlist[u].size();i++)
			{
				//cout<<adjlist[u][i]<<endl;
				if(adjlist[u][i]==p)
					continue;
				if(vis[adjlist[u][i]])
				{
					//cout<<adjlist[u][i]<<endl;
					notvis--;
					while(!q.empty())
						q.pop();
					break;
				}
				q.push(pair<int,int>(adjlist[u][i],u));
			}
		}
	}
	cout<<notvis;
}