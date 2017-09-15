#include "bits/stdc++.h"
using namespace std;
long long int dp[35][35][35];
long long int solve(int x,int y,int z)
{
	if(x==0 && y==0 && z==0)
		return 1;
	if(x<0 || y<0 || z<0)
		return 0;
	if(dp[x][y][z]!=-1)
		return dp[x][y][z];
	long long int ans=solve(x-2,y-1,z-1)+solve(x-1,y-1,z-2)+solve(x-2,y-2,z-2);
	/*
	if(x>y && y==z)
		ans+=solve(x-2,y,z);
	else if(y>z && x==z)
		ans+=solve(x,y-2,z);
	else if(z>x && y==x)
		ans+=solve(x,y,z-2);	
	else if(x!=y && y!=z && z!=x)
		ans+=solve(x-2,y,z)+solve(x,y-2,z)+solve(x,y,z-2);
		*/
	return dp[x][y][z]=ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	while(n!=-1)
	{
		memset(dp,-1,sizeof dp);
		cout<<solve(n,n,n)<<endl;
		//n==0 -- output=??
		cin>>n;
	}
}	