//AC
#include "bits/stdc++.h"
using namespace std;

int n,m;
int c11=0,c10=0,c01=0,c00=0;
std::vector<std::vector<string> > grid;
void updatecell(int r,int c)
{
	if(r==0)
	{
		if(c11>0)
		{
			grid[r][c]="11";
			c11--;
		}
		else if(c10>0)
		{
			grid[r][c]="10";
			c10--;	
		}
		else if(c01>0)
		{
			grid[r][c]="01";
			c01--;	
		}
		else
		{
			c00--;
		}
	}
	else if(c11)
	{
		grid[r][c]="11";
		c11--;
	}
	else if(grid[r-1][c]=="01")
	{
		if(c10>0)
		{
			grid[r][c]="10";
			c10--;
		}
		else if(c01>0)
		{
			grid[r][c]="10";
			c01--;	
		}
		else if(c00)
			c00--;
		else
		{
			grid[r][c]="11";
			c11--;
		}
	}
	else if(grid[r-1][c]=="10")
	{
		if(c01>0)
		{
			grid[r][c]="01";
			c01--;	
		}	
		else if(c10>0)
		{
			grid[r][c]="01";
			c10--;
		}
		else if(c00)
			c00--;
		else
		{
			grid[r][c]="11";
			c11--;
		}
	}
	else
	{
		if(c11)
		{
			grid[r][c]="11";
			c11--;
		}
		else if(c10)
		{
			grid[r][c]="10";
			c10--;
		}
		else if(c01)
		{
			grid[r][c]="01";
			c01--;
		}
		else
			c00--;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>m;
	string s;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>s;
			if(s=="11")
				c11++;
			else if(s=="10")
				c10++;
			else if(s=="01")
				c01++;
			else
				c00++;
		}
	}	

	grid=std::vector<std::vector<string> >(n,std::vector<string> (m,"00"));
	for(int r=0;r<n;r++)
	{
		if((r%2)==0)
		{
			for(int c=0;c<m;c++)
			{
				updatecell(r,c);
			}	
		}
		else
		{
			for(int c=m-1;c>=0;c--)
			{
				updatecell(r,c);
			}
		}
	}
	

	for(int r=0;r<n;r++)
	{
		for(int c=0;c<m;c++)
			printf("%s ", grid[r][c].c_str());
		printf("\n");
	}

}