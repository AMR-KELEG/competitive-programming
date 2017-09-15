#include "bits/stdc++.h"
using namespace std;
bool can_be_reached[101][101]={};
int main()
{
	freopen("out.txt","w",stdout);
	int n;//number of nodes
	int m;//number of starting indexes
	//vector<int>edge_list;
	int first_node;
	int start_index;
	int temp_int;
	while(cin>>n)
	{
		memset(can_be_reached,0,sizeof can_be_reached);
		cin>>first_node;
		cin>>temp_int;
		while(temp_int!=0)
		{
			can_be_reached[first_node][temp_int]=1;
		//	edge_list.push_back(temp_int);
			cin>>temp_int;
		//	cin>>temp_int;
		}
		
		//start taking the starting indexes
		cin>>m;
		cin>>start_index;
		while(start_index!=0)
		{
			vector<int>unreached_nodes;
			for(int i=1;i<=n;i++)
			{
				if(!can_be_reached[start_index][i])
					unreached_nodes.push_back(i);
			}
			cout<<unreached_nodes.size();
			for(int i=0;i<unreached_nodes.size();i++)
			{
				cout<<" "<<unreached_nodes[i];
			}
			cout<<endl;
			cin>>start_index;
		}

	}
}
