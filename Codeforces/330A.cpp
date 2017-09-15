//AC
#include "bits/stdc++.h"
using namespace std;
int r,c;
std::vector<std::vector<char> > grid;
bool checkr(int r)
{
	for(int col=0;col<c;col++)
		if(grid[r][col]=='S')
			return 0;
	return 1;
}
bool checkc(int c)
{
	for(int row=0;row<r;row++)
		if(grid[row][c]=='S')
			return 0;

	return 1;
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	cin>>r>>c;
	grid=std::vector<std::vector<char> >(r,std::vector<char> (c));
	int tr=0,tc=0;
	int count=0;
	for(int row=0;row<r;row++)
	{
		for(int col=0;col<c;col++)
			cin>>grid[row][col];
	}
	for(int row=0;row<r;row++)
	{
		if(checkr(row))
		{
			count+=c;
			tr++;
		}
	}
	for(int col=0;col<c;col++)
	{
		if(checkc(col))
		{
			count+=r-tr;
		}
	}
	cout<<count;

}