//AC
#include "bits/stdc++.h"
using namespace std;
int rem;
int R,C,k,w=0;
std::vector<vector<char> > grid;
std::vector<vector<bool> > visited;
void dfs(int r,int c)
{
	if(rem==0)
		return ;
	visited[r][c]=1;
	grid[r][c]='v';
	rem--;
	if(c+1<C)
	{
		if(grid[r][c+1]=='.')
		{
			if(!visited[r][c+1])
			{
				dfs(r,c+1);
			}
		}
	}
	if(c-1>=0)
	{
		if(grid[r][c-1]=='.')
		{
			if(!visited[r][c-1])
			{
				dfs(r,c-1);
			}
		}
	}
	if(r+1<R)
	{
		if(grid[r+1][c]=='.')
		{
			if(!visited[r+1][c])
			{
				dfs(r+1,c);
			}
		}
	}
	if(r-1>=0)
	{
		if(grid[r-1][c]=='.')
		{
			if(!visited[r-1][c])
			{
				dfs(r-1,c);
			}
		}
	}

}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>R>>C>>k;
	grid=std::vector<vector<char> >(R,std::vector<char> (C));
	visited=std::vector<vector<bool> >(R,std::vector<bool> (C,0));
	int rr=0,cc=0;
	for(int r=0;r<R;r++)
	{
		for(int c=0;c<C;c++)
		{
			cin>>grid[r][c];
			if(grid[r][c]=='#')
				w++;
			else
			{
				rr=r;
				cc=c;
			}
		}
	}	
	rem=(R*C)-w-k;
	dfs(rr,cc);
	for(int r=0;r<R;r++)
	{
		for(int c=0;c<C;c++)
		{
			if(grid[r][c]=='v')
				printf("%c",'.');
			else if(grid[r][c]=='.')
				printf("%c",'X');
			else
				printf("%c",grid[r][c]);
		}
		printf("\n");
	}

}