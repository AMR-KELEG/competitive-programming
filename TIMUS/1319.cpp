//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	std::vector<std::vector<int> > grid(n,std::vector<int> (n));
	int cel=1;
	for(int col = n-1;col>=0;col--)
	{
		int r=0;
		int c=col;
		while(r<n && c<n)
		{
			grid[r][c]=cel++;
			r++;
			c++;
		}
	}
	for(int row = 1;row<n;row++)
	{
		int r=row;
		int c=0;
		while(r<n && c<n)
		{
			grid[r][c]=cel++;
			r++;
			c++;
		}
	}
	for(int r=0;r<n;r++)
	{
		for(int c=0;c<n;c++)
		{
			printf("%d ",grid[r][c]);
		}
		printf("\n");
	}
}