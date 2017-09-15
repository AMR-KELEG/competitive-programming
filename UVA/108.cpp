//AC
#include "bits/stdc++.h"
#define INF 1000000007
using namespace std;

int grid[101][101];
int cum_sum[101][101];
int vis[101][101][101][101];
int dp[101][101][101][101];
int T=1;
int find_area(int r1,int c1,int r2,int c2)
{
	// return cum_sum[r2][c2];
	return cum_sum[r2][c2]-cum_sum[r1-1][c2]-cum_sum[r2][c1-1]+cum_sum[r1-1][c1-1];
}

int max_area(int r1,int c1,int r2,int c2)
{
	if (r1>r2 || c1>c2)
		return -INF;
	if (vis[r1][c1][r2][c2]==T)
		return dp[r1][c1][r2][c2];
	vis[r1][c1][r2][c2] =T ;
	int ans = find_area(r1,c1,r2,c2);	
	ans = max(ans,max_area(r1+1,c1,r2,c2));
	ans = max(ans,max_area(r1,c1+1,r2,c2));
	ans = max(ans,max_area(r1,c1,r2-1,c2));
	ans = max(ans,max_area(r1,c1,r2,c2-1));
	// cout<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<" "<<ans<<endl;
	return dp[r1][c1][r2][c2]=ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	while(cin>>n)
	{
		for (int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>grid[i][j];
				cum_sum[i][j]= grid[i][j]+cum_sum[i-1][j]+cum_sum[i][j-1]-cum_sum[i-1][j-1];
				// cout<<i<<" "<<j<<" "<<grid[i][j]<<" "<<cum_sum[i][j]<<endl;

			}
			// cout<<endl;
		}
		// cout<<find_area(4,4,4,4)<<endl;
		cout<<max_area(1,1,n,n)<<endl;
		T++;
	}
}