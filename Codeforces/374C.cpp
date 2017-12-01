//AC
#include "bits/stdc++.h"
using namespace std;
#define INF (100000000)

int startTime[1002][1002];
char grid[1002][1002];
int ans[1002][1002];
bool vis[1002][1002] = {};

int t = 1;
map<char,char> next_char;
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};

int dfs(int r,int c)
{
	if(startTime[r][c]==t)
	{
		return INF;
	}

	if (grid[r][c]=='D' && vis[r][c])
		return ans[r][c];

	startTime[r][c] = t;
	vis[r][c]=1;

	int inc = (grid[r][c]=='A');
	ans[r][c] = inc;
	for(int x=0,y;x<4;x++)
	{
		y=x;
		if(grid[r+dx[x]][c+dy[y]]==next_char[grid[r][c]])
		{
			ans[r][c]= max(ans[r][c], inc+dfs(r+dx[x],c+dy[y]));
		}
	}
	startTime [r][c]=0;
	return ans[r][c];
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	next_char['D'] = 'I';
	next_char['I'] = 'M';
	next_char['M'] = 'A';
	next_char['A'] = 'D';
	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=m;c++)
		{
			cin>>grid[r][c];
		}
	}
	int Fans = 0;
	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=m;c++)
		{
			// not solved yet
			if(grid[r][c]=='D' && !vis[r][c])
			{
				t++;
				Fans=max(Fans,dfs(r,c));	
			}
		}
	}
	if(Fans==0)
		cout<<"Poor Dima!";
	else if(Fans>=INF)
		cout<<"Poor Inna!";
	else
		cout<<Fans;
}