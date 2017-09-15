#include "bits/stdc++.h"
using namespace std;
typedef pair<int,pair<int,int> > edge;//w,n,p
typedef pair<int,int> edgee;
vector< vector< pair<int,int> > > adj_list;//node - weight
vector< pair<long long int,int> >distance_parent;
vector<bool>visited;
void dijkstra(int s)
{
	priority_queue<edge,std::vector<edge>,greater<edge> > c_node;//weight,node
	c_node.push(edge(0,edgee(s,-1)));
	while(!c_node.empty())
	{
		edge e=c_node.top();
		int w=e.first;
		int current_node=e.second.first;
		c_node.pop();
		if(visited[current_node]==0)
		{
			visited[current_node]=1;
			distance_parent[current_node].first=w;
			distance_parent[current_node].second=e.second.second;
			for(int i=0;i<adj_list[current_node].size();i++)
			{
				if(visited[adj_list[current_node][i].first]==0)
				{
					c_node.push(edge(w+adj_list[current_node][i].second,edgee(adj_list[current_node][i].first,current_node)));
				}
			}
		}
	}
}

int main()
{
	int n,m;
	int a,b,c;
	cin>>n>>m;
	adj_list.resize(n+1);
	visited.assign(n+1,0);
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		adj_list[a].push_back(pair<int,int> (b,c));
		adj_list[b].push_back(pair<int,int> (a,c));
	}
	distance_parent.assign(n+1,pair<int,int>(1<<29,-1));
	distance_parent[1].first=0;


	dijkstra(1);
	stack<int>my_numbers;
	int node_i=n;
	my_numbers.push(node_i);
	while(distance_parent[node_i].second!=-1)
	{
		node_i=distance_parent[node_i].second;
		my_numbers.push(node_i);
	}
	if(node_i==1)
	{
		while(!my_numbers.empty())
		{
			cout<<my_numbers.top()<<" ";
			my_numbers.pop();
		}
	}
	else
	{
		cout<<"-1";
	}
	return 0;
}