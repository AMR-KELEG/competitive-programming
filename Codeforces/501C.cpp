//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	std::vector<int> deg(n),xorSum(n);
	for(int i=0;i<n;i++)	
	{
		cin>>deg[i]>>xorSum[i];
	}

	std::vector<pair<int,int> > edges;

	queue<int>q;
	for(int i=0;i<n;i++)
	{
		if(deg[i]==1)
			q.push(i);
	}

	int node;
	int othernode;
	while(!q.empty())
	{
		node=q.front();
		othernode=xorSum[node];
		q.pop();
		if(deg[node]==0)
		{
			continue;
		}
		deg[node]--;
		// insert edge bet node and xorSum of it
		edges.push_back({node,othernode});
		//decrement dege
		deg[othernode]--;
		xorSum[othernode]^=node;
		if(deg[othernode]==1)
		{
			q.push(othernode);
		}
	}

	cout<<edges.size()<<endl;
	for(int i=0;i<edges.size();i++)
		printf("%d %d\n", edges[i].first,edges[i].second);

}