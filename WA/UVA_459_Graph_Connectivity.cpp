#include "bits/stdc++.h"
using namespace std;
bool visited[26]={0};
vector<int> adjacency_list[26];
void dfs(int start)
{
	visited[start]=1;
	for(int i=0;i<adjacency_list[start].size();i++)
	{
		dfs(adjacency_list[start][i]);
	}
}

int main()
{
	cout<<"amr"<<endl;
	int n;
	string temp;
	char c,c1;
	cin>>c;
	n=c-'A'+1;
	c= getchar();
	c= getchar();
	c1= getchar();
	
	while(c!=c1)
	{
		cin>>c;
		adjacency_list[c-'A'].push_back(c1-'A');
		adjacency_list[c1-'A'].push_back(c-'A');
		c= getchar();
		c1= getchar();
	}
	int counter=0;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			counter++;
			dfs(i);
		}
	}
	cout<<counter;
	return 0;
}