#include "iostream"
#include "vector"
#include "cstring"
using namespace std;
vector<int>edges[10000];
int last_node,max_distance=0;
int count=0;
bool visited[10000]={};
void dfs(int node,int distance)
{
	visited[node]=1;
	for(int i=0;i<edges[node].size();i++)
	{
		if(visited[edges[node][i]]==0)
		{
			dfs(edges[node][i],distance+1);
		}
			
	}
	if(distance>=max_distance)
	{
		max_distance=distance;
		last_node=node;
	}
	//return max_distance;
}

int main()
{
	int N,first,second;
	cin>>N;
	for(int i=0;i<N-1;i++)
	{
		cin>>first>>second;
		edges[first-1].push_back(second-1);
		edges[second-1].push_back(first-1);
	}
	dfs(first-1,0);
	//cout<<last_node<<endl<<max_distance<<endl;
	max_distance=0;
	memset(visited,0,sizeof(visited));
	dfs(last_node,0);
	cout<<max_distance;
	return 0;
}