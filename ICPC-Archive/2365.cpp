//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		if(t>1)
			printf("\n");
		int days;
		cin>>days;
		int D[16];
		for(int i=0;i<16;i++)
		{
			cin>>D[i];
		}
		int grid[2][22][22]={};
		for(int i=1;i<21;i++)
		{
			for(int j=1;j<21;j++)
			{
				cin>>grid[0][i][j];
				// cout<<grid[0][i][j]<<" ";
			}
			// cout<<endl;
		}
		for(int d=1;d<=days;d++)
		{
			for(int i=1;i<21;i++)
			{
				for(int j=1;j<21;j++)
				{
					int s = grid[(d-1)%2][i][j]+grid[(d-1)%2][i-1][j]+grid[(d-1)%2][i+1][j]+grid[(d-1)%2][i][j-1]+grid[(d-1)%2][i][j+1];
					// cout<<s<<endl;
					grid[d%2][i][j] = grid[(d-1)%2][i][j] + D[s];
					if(grid[d%2][i][j]<0)
						grid[d%2][i][j]=0;
					else if(grid[d%2][i][j]>3)
						grid[d%2][i][j]=3; 
				}
			}
		}
		for(int i=1;i<21;i++)
		{
			for(int j=1;j<21;j++)
			{
				int val = grid[days%2][i][j];
				if(val==0)
					printf(".");
				else if(val==1)
					printf("!");
				else if(val==2)
					printf("X");
				else if(val==3)
					printf("#");
			}
			printf("\n");
		}
	}	
}