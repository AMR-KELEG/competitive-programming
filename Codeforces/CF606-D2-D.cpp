//5:13 
// AC
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
	std::vector<pair<int,int> > ans(m);
	std::vector<pair<int,int> > good;
	std::vector<pair<int,int> > bad;
	std::vector<int> cost(n+1,0);
	for(int i=0;i<m;i++)
	{
		int c,g;
		cin>>c>>g;
		if(g)
		{
			good.push_back({c,i});
		}
		else
		{
			bad.push_back({c,i});
		}
	}
	sort(good.begin(), good.end());
	sort(bad.begin(), bad.end());
	cost[1]=-1;
	for(int i=1;i<n;i++)
	{
		int c = good[i-1].first;
		int indx = good[i-1].second;
		ans[indx] = {i,i+1};
		cost[i+1] = c;
	}

	int rem = 0;
	for(int i=3;i<=n && rem < m-(n-1);i++)
	{
		for(int j=1;j<i-1 && rem < m-(n-1);j++)
		{
			int c = bad[rem].first;
			if (c>= cost[i])
			{
				int indx = bad[rem].second;
				ans[indx] = {i,j};
				rem++;
			}
			else
			{
				break;
			}
		}
	}

	if(rem < m-(n-1))
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<m;i++)
	{
		printf("%d %d\n", ans[i].first,ans[i].second);
	}

}