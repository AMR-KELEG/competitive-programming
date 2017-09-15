#include "bits/stdc++.h"
using namespace std;

int beauty[8][8];
bool vis[8][8];
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
int n,m;
int solve(int r,int c)
{
	if(r< 0 || r==n || c< 0 || c==m)
		return 0;
	if (beauty[r][c]==0)
		return 0;
	if(vis[r][c])
		return 0;
	int ans = 0;
	vis[r][c]=1;
	for (int i=0;i<4;i++)
	{
		ans = max(ans, solve(r+dr[i],c+dc[i]));
	}
	vis[r][c]=0;
	return ans + beauty[r][c];
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for (int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin>>beauty[i][j];
		}
		int ans =0;
		for (int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				ans = max(ans,solve(i,j));
		}
		cout<<ans<<endl;
	}
}