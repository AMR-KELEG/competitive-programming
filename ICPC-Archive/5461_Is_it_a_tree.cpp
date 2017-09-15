#include <bits/stdc++.h>
using namespace std;
map<int,vector<int> >adjacency_list;
int main()
{
	bool istree=false;
	int T=0;
	int a=0,b=0,number_of_edges=0,number_of_nodes=0,current_node,root,number_of_visited_nodes;
	while(a!=-1 && b!=-1)
	{
		adjacency_list.clear();
		vector <int> has_in_edges (10000001,0);
		set<int>nodes;
		T++;
		number_of_visited_nodes=0;
		istree=false;
		number_of_nodes=0;
		number_of_edges=0;
		cin>>a>>b;
		if(a==-1 && b==-1)break;
		while(a>0 && b>0)
		{
			nodes.insert(a);
			nodes.insert(b);
			adjacency_list[a].push_back(b);
			has_in_edges[b]=1;
			cin>>a>>b;
			number_of_edges++;
		}
		number_of_nodes=nodes.size();
		vector<bool> visited(number_of_nodes,0); 
		if(number_of_edges==number_of_nodes && number_of_nodes==0)
		{
			istree=true;
		}
		else if(number_of_edges==number_of_nodes-1)
		{
			//search for root
			for(set<int>::iterator it=nodes.begin();it!=nodes.end();it++)
			{
				if(has_in_edges[*it]==0)
				{
					root=*it;
					break;
				}
			}
			//make bfs from the root
			istree=true;
			queue<int>myqueue;
			myqueue.push(root);
			while(!myqueue.empty())
			{
				current_node=myqueue.front();
				visited[current_node]=1;
				number_of_visited_nodes++;
				myqueue.pop();
				for(int i=0;i<adjacency_list[current_node].size();i++)
				{
					if(visited[adjacency_list[current_node][i]]==0)
						myqueue.push(adjacency_list[current_node][i]);
					else
					{
						istree=false;
						while(!myqueue.empty())
							myqueue.pop();
						break;
					}
				}
			}



		}
		if(istree && number_of_visited_nodes==number_of_nodes)
		{
			cout<<"Case "<<T<<" is a tree."<<endl;
		}
		else
		{
			cout<<"Case "<<T<<" is not a tree."<<endl;
		}
	}
	return 0;
}