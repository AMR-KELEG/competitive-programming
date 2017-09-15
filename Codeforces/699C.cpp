//AC
#include "bits/stdc++.h"
using namespace std;
int n;
std::vector<int> st;
int dp[105][3];
int solve(int day,int last)
{
	// cout<<day<<" "<<last<<endl;
	if(day==n)
		return 0;
	if(dp[day][last]!=-1)
		return dp[day][last];
	if(st[day]==0)
	{
		return dp[day][last]=1+solve(day+1,0);
	}
	if(last==0)
	{
		int ans=1000;
		if(st[day]>=2)
			ans=solve(day+1,2);
		if(st[day]%2)
		{
			ans=min(ans,solve(day+1,1));
		}
		ans=min(ans,1+solve(day+1,0));
		return dp[day][last]=ans;
	}
	if(last==1)
	{
		//contest
		//try gym or rest
		if(st[day]>=2)
			return dp[day][last]=min(1+solve(day+1,0),solve(day+1,2));
	}
	if(last==2)
	{
		//gym
		//try contest
		if(st[day]%2)
		{
			return dp[day][last]=min(1+solve(day+1,0),solve(day+1,1));
		}
	}
	return dp[day][last]=1+solve(day+1,0);
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	memset(dp,-1,sizeof dp);
	st=std::vector<int> (n);
	for(int i=0;i<n;i++)
	{
		cin>>st[i];
	}
	cout<<solve(0,0);
}