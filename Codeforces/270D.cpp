//AC
#include "bits/stdc++.h"
using namespace std;
int dp[5001][5001];
int type [5001];
int n,m;
int solve (int flower_indx = 0, int border_indx=0)
{
	if (flower_indx == n)
		return 0;
	if (dp[flower_indx][border_indx] !=-1)
		return dp[flower_indx][border_indx];
	if (border_indx==m)
	{
		// just count the remaining flowers
		return dp[flower_indx][border_indx] = (type[flower_indx] != m-1) +solve(flower_indx+1,border_indx);
	}
	int ans  = solve(flower_indx, border_indx+1);
	if (type[flower_indx]==border_indx)
	{
		// int ans1 = ans;
		ans = min(ans, solve(flower_indx+1, border_indx));
		// cout<<"Ans1 "<<ans1<<" ";
		// cout<<type[flower_indx]<<" "<<border_indx<<" Ans2 "<<ans<<endl;
		return dp[flower_indx][border_indx]= ans;
	}
	// int ans1 = ans;
	ans = min(ans, 1+solve(flower_indx+1, border_indx));
	// cout<<"Ans1 "<<ans1<<" ";
	// cout<<type[flower_indx]<<" "<<border_indx<<" Ans3 "<<ans<<endl;
	return dp[flower_indx][border_indx]= ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(dp,-1,sizeof dp);
	cin>>n>>m;
	vector<pair<long double,int> > flowers(n);
	for (int i=0;i<n;i++)
	{
		cin>>flowers[i].second>>flowers[i].first;
	}
	sort (flowers.begin(), flowers.end());
	for (int i=0;i<n;i++)
	{
		// cout<<"Coord: "<<flowers[i].second<<" Type: "<<flowers[i].first<<endl;
		type[i] = flowers[i].second-1;
	}
	if (m>1)
	{
		cout<<solve();
	}
	else
	{
		cout<<0;
	}
}