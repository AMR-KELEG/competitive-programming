#include "bits/stdc++.h"
using namespace std;
int max_node;
int max_cost=0;
vector< vector< pair<int,int> > > adj_list;//node and cost
vector<int>visited;
void dfs(int start,int cost)
{
	if(visited[start])return;
	if(cost>max_cost)
		{
			max_node=start;
			max_cost=cost;
		}
	visited[start]=1;
	for(int i=0;i<adj_list[start].size();i++)
	{
		dfs(adj_list[start][i].first,cost+adj_list[start][i].second);
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	int T,N,a,b,c;
	cin>>T;
	while(T--)
	{
		cin>>N;//max is 2000
		adj_list.clear();
		adj_list.resize(N+1);//node and cost
		visited.assign(N+1,0);
		max_cost=0;
		for(int i=0;i<N-1;i++)
		{
			cin>>a>>b>>c;
			adj_list[a].push_back(pair<int,int> (b,c));
			adj_list[b].push_back(pair<int,int> (a,c));
		}
		dfs(1,0);
		max_cost=0;
		visited.assign(N+1,0);
		dfs(max_node,0);
		cout<<max_cost<<endl;
	}
	return 0;
}