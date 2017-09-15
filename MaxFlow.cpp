#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n=4;
	std::vector<vector<pair<int,int>> > adjlist(n+5);
	int s=1;
	/*

		1--(2)--2-----(2)---------4
			    |                 |
			    |--(2)--3--(2)----|
	*/
	adjlist[1].push_back(pair<int,int>(2,2));
	adjlist[2].push_back(pair<int,int>(3,2));
	adjlist[2].push_back(pair<int,int>(4,2));
	adjlist[3].push_back(pair<int,int>(4,2));
	int des=4;
	bool found=1;
	std::vector<int> vis(n+5,0);
	while(found)
	{
		found=0;
		queue<int>q;
		q.push(s);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			if(u==des)
			{
				found=1;
				cout<<"Path \n";
				break;
			}
			for(int i=0;i<adjlist[u].size();i++)
			{
				if(!vis[adjlist[u][i].first])
				{
					q.push(adjlist[u][i].first);
				}
			}
		}
		
	}
}