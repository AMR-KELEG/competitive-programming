//AC
//More Thinking is required
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	std::vector<bool> vis(n+1,0);
	std::vector<std::vector<int> > adj_list(n+1);
	std::vector<bool> init(n+1),goal(n+1);
	int u,v;
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}	
	int t;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		init[i]=t;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		goal[i]=t;
	}

	queue<pair<int,pair<int,int>> >q;
	q.push(pair<int,pair<int,int>>(1,pair<int,int>(0,0)));
	long long int op=0;
	int c;
	int b_1,b_2;
	queue<int>cnodes;
	while(!q.empty())
	{
		c=q.front().first;
		b_1=q.front().second.first;
		b_2=q.front().second.second;
		q.pop();
		if(vis[c])
		{
			continue;
		}
		//cout<<c<<endl;
		vis[c]=1;
		if(b_2%2)
		{
			init[c]=!init[c];
		}
		if(init[c]!=goal[c])
		{
			op++;
			cnodes.push(c);
			b_2++;
		}
		for(int i=0;i<adj_list[c].size();i++)
		{
			//cout<<"l "<<adj_list[c][i]<<endl;
			if(!vis[adj_list[c][i]])
			{
				q.push(pair<int,pair<int,int>>(adj_list[c][i],pair<int,int>(b_2,b_1)));
				//cout<<q.size()<<endl;
			}
		}
	}
	cout<<op<<endl;
	while(!cnodes.empty())
	{
		printf("%d\n",cnodes.front());
		cnodes.pop();
	}

	/*
	*/
}