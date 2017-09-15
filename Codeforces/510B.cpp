//AC
#include "bits/stdc++.h"
using namespace std;
int n,m;	
char grid [55][55];
bool vis[55][55]={};
bool dfs(int r,int c,int pr,int pc)
{
	//cout<<r<<" "<<c<<endl;
	if(r==0 || r>n || c==0 || c>m)
		return 0;
	if(vis[r][c])
		return 1;
	vis[r][c]=1;

	bool ans=0;
	if(grid[r][c]==grid[r+1][c])
	{
		if(!(pr==r+1 && pc==c))
		{
			ans|=dfs(r+1,c,r,c);
		}
	}
	if(grid[r][c]==grid[r-1][c])
	{
		if(!(pr==r-1 && pc==c))
		{
			ans|=dfs(r-1,c,r,c);
		}
	}
	if(grid[r][c]==grid[r][c+1])
	{
		if(!(pr==r && pc==c+1))
		{
			ans|=dfs(r,c+1,r,c);
		}
	}
	if(grid[r][c]==grid[r][c-1])
	{
		if(!(pr==r && pc==c-1))
		{
			ans|=dfs(r,c-1,r,c);
		}
	}
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cin>>grid[i][j];
	}
	bool f=0;
	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=m;c++)
		{
			if(!vis[r][c])
			{
				if(dfs(r,c,0,0))
				{
					f=1;
					r=n+2;
					break;
				}
			}
		}
	}
	if(f)
		cout<<"Yes";
	else
		cout<<"No";
}