#include "bits/stdc++.h"
using namespace std;
vector<int>no_of_dependencies;
vector< vector<int> >children; 
int main()
{
	ios::sync_with_stdio(false);
	int n,m,d,u;
	bool more_than_one_arrangement=false;
	int no_of_taken_nodes=0;
	queue<int>next_node;
	cin>>n>>m;
	while(n!=0 && m!=0)
	{
		more_than_one_arrangement=0;
		no_of_dependencies.assign(n+1,0);
		children.clear();
		children.resize(n+1);
		for(int i=0;i<m;i++)
		{
			cin>>d>>u;
			children[d].push_back(u);
			no_of_dependencies[u]++;
		}
		//Get the starting nodes
		for(int i=1;i<n+1;i++)
		{
			if(no_of_dependencies[i]==0)
			{
				next_node.push(i);
			}
		}

		if(next_node.size()>1)
		{
			more_than_one_arrangement=1;
		}
		int current_node;
		no_of_taken_nodes=0;
		while(!next_node.empty())
		{
			no_of_taken_nodes++;
			current_node=next_node.front();
			next_node.pop();
			for(int i=0;i<children[current_node].size();i++)
			{
				if(--no_of_dependencies[children[current_node][i]]==0)
				{
					next_node.push(children[current_node][i]);
				}
			}
			if(next_node.size()>1)
			{
				more_than_one_arrangement=true;
			}
		}

		if(no_of_taken_nodes<n)
		{
			cout<<0<<endl;
		}
		else if(more_than_one_arrangement)
		{
			cout<<2<<endl;
		}
		else
		{
			cout<<1<<endl;
		}
		cin>>n>>m;
	}
	
	return 0;
}