//AC
#include "bits/stdc++.h"
using namespace std;
char grid[4][4]={};
bool xWins()
{
	for(int r=0;r<4;r++)
	{
		for(int s=0;s<2;s++)
		{
			if(grid[r][s]=='x' && grid[r][s+1]=='x' && grid[r][s+2]=='x')
				return 1;
			if(grid[s][r]=='x' && grid[s+1][r]=='x' && grid[s+2][r]=='x')
				return 1;
		}
	}
	//Diagonal Check
	for(int r=0;r<2;r++)
	{
		for(int s=0;s<2;s++)
		{
			if(grid[r][s]=='x' && grid[r+1][s+1]=='x' && grid[r+2][s+2]=='x')
				return 1;
			if(grid[3-r][s]=='x' && grid[3-r-1][s+1]=='x' && grid[3-r-2][s+2]=='x')
				return 1;
		}
	}
	return 0;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	for(int r=0;r<4;r++)
		for(int c=0;c<4;c++)
			cin>>grid[r][c];
	bool win=0;
	for(int r=0;r<4;r++)
	{
		for(int c=0;c<4;c++)
		{
			if(grid[r][c]=='.')
			{
				grid[r][c]='x';
				if(xWins())
				{
					win=1;
					r=4;
					break;
				}
				grid[r][c]='.';
			}
		}
	}
	if(win)cout<<"YES";
	else	cout<<"NO";
}