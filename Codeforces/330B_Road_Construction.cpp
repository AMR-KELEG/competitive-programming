#include "bits/stdc++.h"
using namespace std;
int main()
{
	int n,m,a,b,center_node;
	set<int>found_nodes;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		found_nodes.insert(a-1);
		found_nodes.insert(b-1);
	}
	for(int i=0;i<n;i++)
	{
		if(found_nodes.find(i)==found_nodes.end())
		{
			center_node=i;
			break;
		}
	}
	cout<<n-1<<endl;
	for(int i=0;i<n;i++)
	{
		if(i!=center_node)
			cout<<center_node+1<<" "<<i+1<<endl;
	}
	return 0;
}