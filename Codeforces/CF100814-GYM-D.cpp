//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<pair<long long int,int> > > adjList;
std::vector<long long int> reach_time;

void dfs(int node = 1,long long int t=0, int p = -1)
{
	if (t> 10000000000000000LL)
		return ;
	
	if (adjList[node].size() == 0)
	{
		// cout<<"Node "<<node<<" :"<<t<<endl;
		reach_time.push_back(t);
		return ;
	}

	long long int min_edge = adjList[node][0].first;
	long long int min_t = t + min_edge;
	for (int i=0;i<adjList[node].size();i++)
	{
		dfs(adjList[node][i].second, min_t + (2*(adjList[node][i].first - min_edge)), node);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		adjList = std::vector<std::vector<pair<long long int,int> > > (n+1);
		reach_time.clear();
		for (int i=2;i<=n;i++)
		{
			int p,c;
			cin>>p>>c;
			adjList[p].push_back({c,i});
		}
		for (int i=1;i<=n;i++)
			sort(adjList[i].begin(), adjList[i].end());
		dfs();
		int q;
		cin>>q;
		sort(reach_time.begin(), reach_time.end());
		while(q--)
		{
			long long int Time;
			cin>>Time;
			int ans = upper_bound(reach_time.begin(), reach_time.end(), Time) 
				- reach_time.begin();
			printf("%d\n", ans);
		}
	}	
}