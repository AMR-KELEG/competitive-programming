//AC -- edges may repeat but its ok
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	std::vector<std::vector<int> > adjlist;
	std::vector<int> pcount;
	int i,j;
	queue<int>q;
	while(!(n==0 && m==0))
	{
		adjlist=std::vector<std::vector<int> >(n+5);
		pcount=std::vector<int> (n+5,0);
		for(int t=0;t<m;t++)
		{
			cin>>i>>j;
			adjlist[i].push_back(j);
			pcount[j]++;
		}

		for(i=1;i<=n;i++)
		{
			if(pcount[i]==0)
			{
				q.push(i);
			}
		}
		while(!q.empty())
		{
			int node=q.front();
			q.pop();
			cout<<node<<" ";
			for(j=0;j<adjlist[node].size();j++)
			{
				pcount[adjlist[node][j]]--;
				if(pcount[adjlist[node][j]]==0)
				{
					q.push(adjlist[node][j]);
				}
			}
		}
		cout<<endl;


		cin>>n>>m;
	}	
}