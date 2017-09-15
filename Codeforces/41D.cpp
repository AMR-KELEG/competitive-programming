//AC
#include "bits/stdc++.h"
using namespace std;
char grid[105][105]={};
int dp[105][105][15];
string s[105][105][15];
int n,m,k;
int findans(int r,int c,int rem)
{
	//cout<<r<<" "<<c<<" "<<rem<<endl;
	if(r==0)
	{
		if(rem==0)
			return 0;
		return -5000;
	}
	if(c<1 || c>m )
		return -5000;
	if(dp[r][c][rem]!=-1)
	{
		return dp[r][c][rem];
	}
	int ans1=findans(r-1,c-1,((rem+grid[r][c]-'0')%(k+1)));
	int ans2=findans(r-1,c+1,((rem+grid[r][c]-'0')%(k+1)));
	if(ans1>ans2 && ans1>=0)
	{
		s[r][c][rem]="L"+s[r-1][c-1][((rem+grid[r][c]-'0')%(k+1))];
		return dp[r][c][rem]=(grid[r][c]-'0')+ans1;
	}
	if(ans2>=0)
	{
		s[r][c][rem]="R"+s[r-1][c+1][((rem+grid[r][c]-'0')%(k+1))];
		return dp[r][c][rem]=(grid[r][c]-'0')+ans2;
	}
	return dp[r][c][rem]=-5000;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>m>>k;
	memset(dp,-1,sizeof dp);
	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=m;c++)
			cin>>grid[r][c];
	}
	int ans=-1;
	int maxc=-1;
	for(int c=1;c<=m;c++)
	{
		if(findans(n,c,k+1)>ans)
		{
			ans=findans(n,c,k+1);
			maxc=c;
		}
		//cout<<"Ans "<<findans(n,c,k+1)<<endl;
	}
	cout<<ans<<endl;
	if(ans!=-1)
	{
		cout<<maxc<<endl;
		s[n][maxc][k+1].erase(s[n][maxc][k+1].size()-1);
		cout<<s[n][maxc][k+1];
	}
}