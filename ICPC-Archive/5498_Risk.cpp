#include "bits/stdc++.h"
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int test=0;
	int no_of_connected_nodes,no,no_of_pairs,startc,endc;
	int visited[21]={};
	while(cin>>no_of_connected_nodes)
	{
		test++;
		set<int>adjacency_list[21];
		for(int node=0;node<no_of_connected_nodes;node++)
			{
				cin>>no;
				adjacency_list[1].insert(no);
				adjacency_list[no].insert(1);
			}	
		for(int i=2;i<=19;i++)
		{
			cin>>no_of_connected_nodes;
			//cout<<no_of_connected_nodes<<endl;
			for(int node=0;node<no_of_connected_nodes;node++)
			{
				cin>>no;
				adjacency_list[i].insert(no);
				adjacency_list[no].insert(i);
			}	
		}
		cin>>no_of_pairs;
		queue<pair <int,int> >next_node;//node,counter
		//if(test>1)
		cout<<"Test Set #"<< test;
		for(int i=0;i<no_of_pairs;i++)
		{
			cin>>startc>>endc;
			//cout<<startc<<" "<<endc<<endl;
			memset(visited,0,sizeof visited);
			next_node.push(pair<int,int> (startc,0));
			pair<int,int>current_node;
			while(!next_node.empty())
			{
				current_node=next_node.front();
				next_node.pop();
				if(current_node.first==endc)
				{
					// 1 to 20: 4
					if(current_node.first!=startc)
					cout<<endl;
					cout<<setw(2);
					cout<<startc;
					cout<<" to ";
					cout<<setw(2);
					cout<<endc<<": ";
					
					cout<<current_node.second;
					while(!next_node.empty())
					{
						next_node.pop();
					}
					break;
				}
				if(visited[current_node.first]==0)
				{
					visited[current_node.first]=1;
					for(set<int>::iterator it=adjacency_list[current_node.first].begin();it!=adjacency_list[current_node.first].end();it++)
					{
						next_node.push(pair<int,int> (*it,current_node.second+1));
					}	
				}
			}

		}
			cout<<endl<<endl;
		
	}
	return 0;
}