#include "bits/stdc++.h"
using namespace std;
std::vector<int> edges[100000];
vector<int>nodes_color;
set <int> colors_set[100000];
int main()
{
	int n,m,c,a,b,current_node_color,neighbour_color;//nodes , edges
	cin>>n>>m;
	for(int  i=0;i<n;i++)
	{
		cin>>c;
		nodes_color.push_back(c-1);
	}
	for(int  i=0;i<m;i++)
	{
		cin>>a>>b;
		edges[a-1].push_back(b-1);
		edges[b-1].push_back(a-1);
	}

	for(int i=0;i<n;i++)
	{
		current_node_color=nodes_color[i];
		//You are at the node i, make bfs
		for(int j=0;j<edges[i].size();j++)
		{
			neighbour_color=nodes_color[edges[i][j]];
			if(neighbour_color!=current_node_color)
			{
				colors_set[current_node_color].insert(neighbour_color);
			}
		} 
	}
	int maxi_color=100001,max_color_size=0;
	for(int i=0;i<10000;i++)
	{
		if(colors_set[i].size()>max_color_size)
		{
			maxi_color=i;
			max_color_size=colors_set[i].size();
		}
	}
	if(maxi_color==100001)
	{
		int min_size=100001;
		for(int i=0;i<n;i++)
		{
			if(edges[i].size()<=min_size && nodes_color[i]<maxi_color)
			{
				min_size=edges[i].size();
				maxi_color=nodes_color[i];
			}	
		}
	}
	cout<<maxi_color+1;
	return 0;
}