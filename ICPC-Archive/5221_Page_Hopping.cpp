#include "bits/stdc++.h"
using namespace std;
set<int>nodes;
bool visited[101]={};
queue< pair<int,int> >next_node;
int main()
{
	int a=1,b=1;
	int T=0;
	cin>>a>>b;
	while(a!=0 && b!=0)
	{
		T++;
		nodes.clear();
		vector<int> adjacency_list[101];
		while(a!=0 && b!=0)
		{
			nodes.insert(a);
			nodes.insert(b);
			adjacency_list[a].push_back(b);
			cin>>a>>b;	
		}
		unsigned long long int clicks=0,dis;
		pair<int,int>current_node;
		for(set<int>::iterator it = nodes.begin();it!=nodes.end();it++)
		{
			dis=0;
			memset(visited,0,sizeof visited);
			next_node.push(pair<int,int>(*it,0));
			while(!next_node.empty())
			{
				current_node=next_node.front();
				next_node.pop();
				if(visited[current_node.first]==0)
				{
					clicks+=current_node.second;
					visited[current_node.first]=1;
					for(int j=0;j<adjacency_list[current_node.first].size();j++)
					{
						if(visited[adjacency_list[current_node.first][j]]==0)
						{
							//cout<<"first , second , clicks "<<*it<<" "<<adjacency_list[current_node.first][j]<<" "<<current_node.second+1<<endl;
							//clicks+=current_node.second+1;
							next_node.push(pair<int,int>(adjacency_list[current_node.first][j],current_node.second+1));
						}
					}
				}
				
			}
		}

		//Case 1: average length between pages = 1.833 clicks
		cout<<std::fixed<<setprecision(3);
		cout<<"Case "<< T<<": average length between pages = "<<double(clicks)/((nodes.size())*(nodes.size()-1))<<" clicks"<<endl;

		cin>>a>>b;
	}
	
	
	return 0;
}