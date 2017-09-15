#include "bits/stdc++.h"
using namespace std;
int R,C;
int sumR[20];
int sumC[20];
int grid[20][20];

void solve(int r=0,int c=0)
{
	// cout<<r<<" "<<c<<endl;
	if(r<0) return ;
	for(int r=0;r<R;r++)
	{
		for(int c=0;c<C;c++)
		{
			printf("%d ", grid[r][c]);
		}
		printf("\n");
	}
	printf("\n");
	if(r==R)
	{
		// CHECK THE GRID IS OK
		for (int c=0;c<C;c++)
		{
			int colS=0;
			for(int r=0;r<R;r++)
			{
				colS+=grid[r][c];
			}
			if(colS!=sumC[c])
			{
				solve(r-1,C-1);
				return ;
			}
		}
		return ;
	}
	if(c==C)
	{
		int curR=0;
		for(int i=0;i<c;i++)
		{
			curR += grid[r][i];
		}
		if(curR == sumR[r])
		{
			solve(r+1,0);
		}
		else
		{
			solve(r,c-1);
		}
		return ;
	}
	if(c==-1)
	{
		solve(r-1,C-1);
		return;
	}
	if(grid[r][c]==20)
	{
		grid[r][c]=0;
		solve(r,c-1);
		return ;
	}
	int curR=0,curC=0;
	for(int i=0;i<c;i++)
	{
		curR += grid[r][i];
	}
	for(int i=0;i<r;i++)
	{
		curC += grid[i][c];
	}
	int minR = curR + (C-c);
	int minC = curC + (R-r);
	int maxR = curR + (C-c)*20;
	int maxC = curC + (R-r)*20;
	if (sumR[r]< minR || sumC[c]< minC || sumR[r]>maxR || sumC[c]>maxC)
	{
		grid[r][c]=0;
		solve(r,c-1);
		return ;
	} 
	 
	grid[r][c]++;
	solve(r,c+1);
}

int main()
{
	// std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>R>>C;
		memset(grid,0,sizeof grid);
		int Sum =0,curS;
		for(int r=0;r<R;r++)
		{
			cin>>curS;
			sumR[r] = curS-Sum;
			Sum = curS;
		}
		Sum=0;
		for(int c=0;c<C;c++)
		{
			cin>>curS;
			sumC[c] = curS-Sum;
			Sum = curS;
		}
		solve();
		printf("Matrix %d\n", t); 	
		for(int r=0;r<R;r++)
		{
			for(int c=0;c<C;c++)
			{
				printf("%d ", grid[r][c]);
			}
			printf("\n");
		}			
	}
}