#include "bits/stdc++.h"
using namespace std;

int main()
{
	int visited[10001]={};
	unsigned long long int min_weight=0;
	int n,m,f,s,w;//nodes -edges
	cin>>n>>m;
	vector< vector< pair<int,int> > >adjacency_list(n+1);//we edge
	for(int i=0;i<m;i++)
	{
		cin>>f>>s>>w;
		adjacency_list[f].push_back(pair<int,int>(w,s));
		adjacency_list[s].push_back(pair<int,int>(w,f));
	}
	
	priority_queue< pair <int,int>  ,std::vector< pair <int,int> > , greater< pair<int,int> > > my_queue;//wei , edge
	my_queue.push(pair<int,int> (0,1));	

	while(!my_queue.empty())
	{
		pair <int,int> current_node=my_queue.top();
		my_queue.pop();
		if(visited[current_node.second]==0)
		{
			min_weight+=current_node.first;
			visited[current_node.second]=1;
			for (int i=0;i<adjacency_list[current_node.second].size();i++)
			{
				my_queue.push(adjacency_list[current_node.second][i]);
			}
		}
	}
	cout<<min_weight;
	return 0;
}