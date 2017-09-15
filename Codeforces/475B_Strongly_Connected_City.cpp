#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n,m;
	int visited[202][202]={};
	char row_dir[202],col_dir[202];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>row_dir[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>col_dir[i];
	}
	bool connected=true;
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=m;col++)
		{
			memset(visited,0,sizeof visited);
			int number_of_nodes=0;
			queue< pair<int,int> >next_node;
			next_node.push(pair<int,int> (row,col));
			while(!next_node.empty())
			{
				pair<int,int>current_node=next_node.front();
				next_node.pop();
				if(visited[current_node.first][current_node.second]==0)
				{
					number_of_nodes++;
					visited[current_node.first][current_node.second]=1;
					if(row_dir[current_node.first]=='>' && current_node.second<m)
					{
						next_node.push(pair<int,int> (current_node.first,current_node.second+1));
					}
					else if(row_dir[current_node.first]=='<' && current_node.second>1)
					{
						next_node.push(pair<int,int> (current_node.first,current_node.second-1));
					}
					//'^' and 'v
					if(col_dir[current_node.second]=='v' && current_node.first<n)
					{
						next_node.push(pair<int,int> (current_node.first+1,current_node.second));
					}	
					else if(col_dir[current_node.second]=='^' && current_node.first>1)
					{
						next_node.push(pair<int,int> (current_node.first-1,current_node.second));
					}	
						
				}
				
			}

			if(number_of_nodes<n*m)
			{
				row=n+1;
				connected=false;
				break;
			}



		}
	}

	if(connected)cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
