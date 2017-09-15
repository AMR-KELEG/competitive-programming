//AC
#include <bits/stdc++.h>
using namespace std;
int n;
std::vector<int> v;
int dp[501][501];

int solve(int s,int e)
{
	if(s>e)
		return 0;
	if(dp[s][e]!=-1)
		return dp[s][e];
	int ans = 1+solve(s+1,e);
	for(int j=s+1;j<=e;j++)
	{
		if(v[s]==v[j])
		{
			ans=min(ans,solve(s+1,j-1)+solve(j+1,e));
		}
	}
	return dp[s][e]=ans;
}
int main()
{
	cin>>n;
	v=std::vector<int> (n);
	memset(dp,-1,sizeof dp);
	cout<<solve(0,n-1);
}