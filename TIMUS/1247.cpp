//AC
#include "bits/stdc++.h"
#define INF 1000000000
using namespace std;
std::vector<int> a;
int dp[30000]={};
int n,N;
int solve(int i=0)
{
	if(i==n)
		return 0;
	return dp[i]=max(a[i],a[i]+solve(i+1));
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>N;
	a=std::vector<int> (n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]--;
	}
	solve();
	int maxSum = -INF;
	for(int i=0;i<n;i++)
		maxSum=max(maxSum,dp[i]);
	if(maxSum<=N)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
}