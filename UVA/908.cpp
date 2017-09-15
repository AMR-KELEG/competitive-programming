#include "bits/stdc++.h"
using namespace std;
typedef pair< int,int > node;
int main()
{
	freopen("in.txt","r",stdin);
	int n,m,k;
	long long int min_weg=0;
	int f,s,wi;
	int test=0;
	while(cin>>n && !cin.eof())
	{
		if (cin.eof()) break;
		test++;
		min_weg=0;
		vector< vector< pair< int ,int> > > adjacency_list(1000001);
		for(int i=0;i<n-1;i++)
		{
			cin>>f>>s>>wi;
			//adjacency_list[f].push_back(pair<int,int>(wi,s));
			//adjacency_list[s].push_back(pair<int,int>(wi,f));
			min_weg+=wi;
		}
		printf("%lld\n",min_weg);
		
		cin>>k;
		for(int i=0;i<k;i++)
		{
			cin>>f>>s>>wi;
			adjacency_list[f].push_back(pair<int,int>(wi,s));
			adjacency_list[s].push_back(pair<int,int>(wi,f));
		}
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>f>>s>>wi;
			adjacency_list[f].push_back(pair<int,int>(wi,s));
			adjacency_list[s].push_back(pair<int,int>(wi,f));
		}
		std::vector<int> visited(1000001,0);
		priority_queue< node,vector<node>,greater<node> >nodes_queue;
		nodes_queue.push(node(0,f));//weight=0 
		min_weg=0;
		while(!nodes_queue.empty())
		{
			node current_node=nodes_queue.top();
			nodes_queue.pop();
			if(visited[current_node.second]==0)
			{
				min_weg+=current_node.first;
				visited[current_node.second]=1;
				for(int i=0;i<adjacency_list[current_node.second].size();i++)
				{
					nodes_queue.push(adjacency_list[current_node.second][i]);
				}
			}
		}
		printf("%lld\n\n",min_weg);
		
	}
	return 0;
}