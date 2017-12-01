// WA
#include "bits/stdc++.h"
using namespace std;
int dp[200000];
int n;
#define INF 1000000007
std::vector<pair<int,int>> v;
std::vector<int> next_indx;
int solve(int i)
{
	if (i==n)
		return 0;
	if (dp[i] !=-1)
		return dp[i];
	return dp[i] = max(1+solve(next_indx[i],v[i].first),solve(i+1));
}	

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(dp, -1, sizeof dp);
	cin>>n;
	v = std::vector<pair<int,int>> (n);
	next_indx = std::vector<int> (n);
	for (int i=0;i<n;i++)
	{
		int x,w;
		cin>>x>>w;
		v[i] = {x+w,x-w};
	}
	sort(v.begin(), v.end());
	int indx = n;
	int start_time = 
	for (int i=0;i<n;i++)
		next_indx[i] = v[i].second;
	// Reverse Problem
	int ans = 1;
	for (int i=0;i<n;i++)
		ans = max(ans,solve(i));
	cout<<ans;
}