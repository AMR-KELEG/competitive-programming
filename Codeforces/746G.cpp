//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,t,k;
	cin>>n>>t>>k;
	std::vector<int> a(t+1);
	int minLeaves=0;
	for(int i=0;i<t;i++)
	{
		cin>>a[i];
	}	
	a[t]=a[t-1];
	minLeaves=a[t-1];
	for(int i=0;i<t-1;i++)
	{
		if(a[i]>a[i+1])
			minLeaves+=a[i]-a[i+1];
	}
	if(minLeaves>k)
	{
		cout<<-1;
	}
	else
	{
		//Increase leaves
		int req=k-minLeaves;
		std::vector<std::vector<int> > nodes(t+1);
		std::vector<pair<int,int> > edges(n-1);
		int curEdge=0;
		nodes[0].push_back(1);
		int nextNode=2;
		int curIndexPerLevel=0,limit;
		for(int level=1;level<=t;level++)
		{
			curIndexPerLevel=0;
			limit=nodes[level-1].size();
			if(a[level-1]<limit)
				req+=limit-a[level-1];
			if(req>=limit)
			{
				req-=limit-1;
				limit=1;
			}
			else
			{
				limit-=req;
				req=0;
			}

			while(a[level-1])
			{
				if(curIndexPerLevel==limit)
				{
					curIndexPerLevel=0;
				}
				edges[curEdge++]={nodes[level-1][curIndexPerLevel++],nextNode};
				nodes[level].push_back(nextNode++);
				a[level-1]--;
			}
		}	 
		if(req==0)
		{
			printf("%d\n", n);
			for(int i=0;i<n-1;i++)
			{
				printf("%d %d\n", edges[i].first,edges[i].second);
			}
		}
		else
		{
			cout<<-1;
		}
	}
}