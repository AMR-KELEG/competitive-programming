#include "bits/stdc++.h"
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector< set<int> >adjacency_list(n+1);
	//vector <int>number_of_connected_nodes(n+1,0);
	int a,b;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		//number_of_connected_nodes[a]++;
		//number_of_connected_nodes[b]++;
		adjacency_list[a].insert(b);
		adjacency_list[b].insert(a);
	}
	int number_of_groups=0;
	bool change=true;
	stack<int>nodes_to_be_removed;
	while(change)
	{
		change=false;
		for(int i=1;i<=n;i++)
		{
			if(adjacency_list[i].size()==1)
			{
				change=true;
				nodes_to_be_removed.push(i);
				//number_of_connected_nodes[adjacency_list[i][0]]--;
				//adjacency_list[i].clear();
			}
		}
		if(change)
		{
			number_of_groups++;
			//number_of_connected_nodes[adjacency_list[i][0]]--;
			while(!nodes_to_be_removed.empty())
			{
				int node=nodes_to_be_removed.top();
				nodes_to_be_removed.pop();
				adjacency_list[*adjacency_list[node].begin()].erase(node);
				adjacency_list[node].clear();
			}
			//adjacency_list[i].clear();
		}
	}
	cout<<number_of_groups;
	return 0;
}