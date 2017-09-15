#include "bits/stdc++.h"
using namespace std;
long long int dp[1005][2];
int n,m,x,y;
int tohash[1005]={};
long long int findop(int s,int col)
{
	if(s==0)
		return tohash[col];
	
	return tohash[col+s]-tohash[s-1];
}
long long int solve(int c,bool hash)
{
	if(dp[c][hash]!=-1)
		return dp[c][hash];
	if(c==m)
		return 0;
	if(c>m)
		return 1<<29;
	long long int ans=1<<29;
	for(int col=x;col<=y && c+col<=m ;col++)
	{
		if(hash)
		{
			//cout<<findop(c,col)<<endl;
			ans=min(ans, findop(c,col-1) +solve(c+col,!hash) );
		}
		else
		{
			//cout<<(n*col)<<" "<<(n*col)-findop(c,col)<<endl;
			ans=min( ans,( (col*n) -findop(c,col-1) )+solve(c+col,!hash));
		}

	}
	//cout<<ans<<" "<<c<<endl;
	return dp[c][hash]=ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(dp,-1,sizeof dp);
	cin>>n>>m>>x>>y;
	std::vector<vector<char> > grid(n,std::vector<char> (m));
	for(int r=0;r<n;r++)
	{
		for(int c=0;c<m;c++)
			cin>>grid[r][c];
	}	
	//make an array of size m to change color to a certain value
	for(int c=0;c<m;c++)
	{
		if(c!=0)
			tohash[c]=tohash[c-1];
		for(int r=0;r<n;r++)
		{
			if(grid[r][c]=='.')
				tohash[c]++;
		}
		//cout<<tohash[c]<<endl;
	}
	//cout<<findop(1,m-2)<<endl;
	cout<<min(solve(0,0),solve(0,1));
	

}