/* AC
Sort the edges to make sure that paths are strictly increasing
*/
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
	std::vector<int> dp(n+1,0);
	priority_queue<pair<int,pair<int,int>> >q;
	for (int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		q.push({-c,{a,b}});
	}

	std::vector<int> last_update(n+1,0);
	std::vector<int> old_dp(n+1,0);
	while(!q.empty())
	{
		int w = -q.top().first;
		int a = q.top().second.first;
		int b = q.top().second.second;
		q.pop();
		//from a to b
		if (last_update[a] == w)
		{
			if (old_dp[a]+1>dp[b])
			{
				old_dp[b] = dp[b];
				last_update[b] = w;
				dp[b] = old_dp[a]+1;
			}	
			continue;
		}
		if (dp[a]+1>dp[b])
		{
			old_dp[b] = dp[b];
			dp[b] = dp[a]+1;
			last_update[b] = w;
		}
	}
	int max_len = 0;
	for (auto l:dp)
		max_len = max(max_len, l);
	cout<<max_len;
}