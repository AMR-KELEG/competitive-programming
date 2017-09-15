#include "bits/stdc++.h"
using namespace std;
#define INF (100000000)
long long int curMin=0;
long long int t=0;
long long int startTime[1002][1002];
char grid[1002][1002];
int ans[1002][1002];
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
int dfs(int r,int c,long long int time)
{
	t=max(t,time);
	if(grid[r][c]=='D')
	{
		if(ans[r][c]!=-1)
			return ans[r][c];
		startTime[r][c]=time;
		for(int x=0,y;x<4;x++)
		{
			y=x;
			if(grid[r+dx[x]][c+dy[y]]=='I')
			{
				return ans[r][c]=dfs(r+dx[x],c+dy[y],time);
			}
		}
		return ans[r][c]=0;
	}
	if(startTime[r][c]==time)
	{
		return ans[r][c];
	}
	startTime[r][c]=time;
	if(grid[r][c]=='I')
	{
		for(int x=0,y;x<4;x++)
		{
			y=x;
			if(grid[r+dx[x]][c+dy[y]]=='M')
			{
				return ans[r][c]=dfs(r+dx[x],c+dy[y],time);
			}
		}
		return ans[r][c]=0;
	}
	if(grid[r][c]=='M')
	{
		for(int x=0,y;x<4;x++)
		{
			y=x;
			if(grid[r+dx[x]][c+dy[y]]=='A')
			{
				return ans[r][c]=dfs(r+dx[x],c+dy[y],time);
			}
		}
		return ans[r][c]=0;
	}
	if(grid[r][c]=='A')
	{
		for(int x=0,y;x<4;x++)
		{
			y=x;
			if(grid[r+dx[x]][c+dy[y]]=='D')
			{
				if(startTime[r+dx[x]][c+dy[y]]>=curMin)
				{
					return ans[r][c]=INF;
				}
				ans[r][c]=1;
				int a=dfs(r+dx[x],c+dy[y],time+1);
				return ans[r][c]=min(a+1,INF);
			}
		}
		return ans[r][c]=1;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;	
	memset(startTime,-1,sizeof startTime);
	memset(ans,-1,sizeof ans);
	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=m;c++)
			cin>>grid[r][c];
	}
	int Fans=0;
	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=m;c++)
		{
			if(grid[r][c]=='D' && startTime[r][c]==-1)
			{
				t++;
				curMin=t;
				Fans=max(Fans,dfs(r,c,t));	
			}
			else if(grid[r][c]=='D')
			{
				t++;
				curMin=t;
				Fans=max(Fans,dfs(r,c,t));
			}
		}
	}
	if(Fans==0)
		cout<<"Poor Dima!";
	else if(Fans==INF)
		cout<<"Poor Inna!";
	else
		cout<<Fans;
}