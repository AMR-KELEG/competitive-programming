#include "bits/stdc++.h"
#define INF (100000000000000LL)
using namespace std;
int grid[300][300];
int n,m,p;
long long int dp[300][300];
std::vector<std::vector<pair<int,int>>> typeCor;
long long int solve(int r,int c)
{
	if(grid[r][c]==0)
		return r+c;
	if(dp[r][c]!=-1)
		return dp[r][c];
	//search for 
	long long int ans=INF;
	int nextType=grid[r][c]-1;
	for(int i=0;i<typeCor[nextType].size();i++)
	{
		pair<int,int>p=typeCor[nextType][i];
		ans=min(ans,
			abs(p.first-r)+abs(p.second-c)+solve(p.first,p.second));
	}
	return dp[r][c]=ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>m>>p;	
	p--;
	memset(dp,-1,sizeof dp);
	typeCor=std::vector<std::vector<pair<int,int>>>(n*m);
	for(int r=0;r<n;r++)
	{
		for(int c=0;c<m;c++)
		{
			cin>>grid[r][c];
			grid[r][c]--;
			typeCor[grid[r][c]].push_back({r,c});
		}
	}
	cout<<solve(typeCor[p][0].first,typeCor[p][0].second);
}