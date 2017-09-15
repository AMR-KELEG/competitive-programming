//WA
#include "bits/stdc++.h"
using namespace std;
int nodes=0;
std::vector<vector<char> > grid;
int countrow[300];
int countcol[300];
bool dfs(int r,int c)
{
	grid[r][c]='2';
	nodes++;
	countrow[r]++;
	countcol[c]++;
	if(grid[r+1][c]=='1')
	{
		dfs(r+1,c);
	}
	if(grid[r][c+1]=='1')
	{
		dfs(r,c+1);
	}
	if(grid[r-1][c]=='1')
	{
		dfs(r-1,c);
	}
	if(grid[r][c-1]=='1')
	{
		dfs(r,c-1);
	}

	if(grid[r-1][c-1]=='1')
	{
		dfs(r-1,c-1);
	}
	if(grid[r-1][c+1]=='1')
	{
		dfs(r-1,c+1);
	}
	if(grid[r+1][c+1]=='1')
	{
		dfs(r+1,c+1);
	}
	if(grid[r+1][c-1]=='1')
	{
		dfs(r+1,c-1);
	}
}


bool checkrhom(int r,int c)
{
	grid[r][c]='3';
	if(grid[r][c+1]=='2')
		return 0;
	if(grid[r+1][c]=='2')
		return 0;
	if(grid[r][c-1]=='2')
		return 0;
	if(grid[r-1][c]=='2')
		return 0;

	if(grid[r-1][c-1]=='2')
	{
		return checkrhom(r-1,c-1);
	}
	if(grid[r-1][c+1]=='2')
	{
		return checkrhom(r-1,c+1);
	}
	if(grid[r+1][c+1]=='2')
	{
		return checkrhom(r+1,c+1);
	}
	if(grid[r+1][c-1]=='2')
	{
		return checkrhom(r+1,c-1);
	}
	return 1;
}



int check(int rr,int cc)
{
	// find no of rows and cols
	int ro=0,co=0;
	int minrow=300,maxrow=0,mincol=300,maxcol=0;
	bool rhom=1;
	for(int r=0;r<300;r++)
	{
		if(countrow[r])
		{
			ro++;
			maxrow=max(maxrow,r);
			minrow=min(minrow,r);
		}
		if(countrow[r]>2)
			rhom=0;
	}
	for(int c=0;c<300;c++)
	{
		if(countcol[c])
		{
			co++;
			maxcol=max(maxcol,c);
			mincol=min(mincol,c);
		}
		if(countcol[c]>2)
			rhom=0;		
	}

	int n=(maxrow+1-minrow);
	// cout<<ro<<" "<<co<<" "<<nodes<<" "<<4+(4*((n/2)-1))<<endl;

	if(ro==co && ro==n)
	{
		if(nodes==4*(n-1) && countrow[minrow]==n && countrow[maxrow]==n && countcol[maxcol]==n && countcol[mincol]==n)
		{
			//100% RIGHT
			return 1;
		}
		if(nodes==4+(4*((n/2)-1)) && rhom && countrow[minrow]==1 && countrow[maxrow]==1 && countcol[maxcol]==1 && countcol[mincol]==1)
		{
			// cout<<"IN\n";
			if(checkrhom(rr,cc))
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
	int t;
	cin>>t;
	int n,m;

	while(t--)
	{
		int count=0;
		cin>>n>>m;
		grid=std::vector<vector<char> >(n+5,std::vector<char> (m+5,'0'));
		for(int r=1;r<=n;r++)
		{
			for(int c=1;c<=m;c++)
				cin>>grid[r][c];
		}
		for(int r=1;r<=n;r++)
		{
			for(int c=1;c<=m;c++)
			{
				if(grid[r][c]=='1')
				{
					nodes=0;
					memset(countrow,0,sizeof countrow);
					memset(countcol,0,sizeof countcol);
					dfs(r,c);
					count+=check(r,c);
					// if(check())
					// cout<<t<<" "<<r<<" "<<c<<endl;
				}
			}
		}
		cout<<count<<endl;
	}	
}