//AC
#include "bits/stdc++.h"
using namespace std;
char grid[3][3];
bool wins(char cc)
{
	for(int r=0;r<3;r++)
	{
		if(grid[r][0]==cc && grid[r][1]==cc && grid[r][2]==cc)
		{
			return 1;
		}
	}
	for(int c=0;c<3;c++)
	{
		if(grid[0][c]==cc && grid[1][c]==cc && grid[2][c]==cc)
			return 1;
	}
	if(grid[0][0]==cc && grid[1][1]==cc && grid[2][2]==cc  )
		return 1;
	if(grid[0][2]==cc && grid[1][1]==cc && grid[2][0]==cc  )
		return 1;
	return 0;

}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int x=0,o=0;
	for(int r=0;r<3;r++)
		for(int c=0;c<3;c++)
		{
			cin>>grid[r][c];
			if(grid[r][c]=='X')
				x++;
			else if(grid[r][c]=='0')
				o++;
		}

	if(x==o)
	{
		//first turn
		if(wins('0'))
		{
			if(!wins('X'))
			{
				//second wins
				cout<<"the second player won";
			}
			else
			{
				cout<<"illegal";
			}
		}
		else
		{
			if(wins('X'))
			{
				cout<<"illegal";
			}
			else
			{
				cout<<"first";
			}
		}
	}
	else if(x==o+1)
	{
		// second turn
		//First could have won
		//Second could'n win
		if(wins('X'))
		{
			if(!wins('0'))
			{
				//first wins
				cout<<"the first player won";
			}
			else
			{
				cout<<"illegal";
			}
		}
		else if(wins('0'))
		{
			cout<<"illegal";
		}
		else if(x==5)
		{
			//draw
			cout<<"draw";
		}
		else
		{
			cout<<"second";
		}
		
	}
	else
	{
		cout<<"illegal";
	}

}