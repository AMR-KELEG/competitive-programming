//AC
#include "bits/stdc++.h"
using namespace std;
int co[5][5]={};
bool grid[4][4];
int cummsum(int r,int c)
{
	return co[r][c]+co[r-1][c]+co[r+1][c]+co[r][c-1]+co[r][c+1];
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	for(int i=1;i<4;i++)
	{
		for(int j=1;j<4;j++)
			cin>>co[i][j];
	}
	for(int r=1;r<4;r++)
	{
		for(int c=1;c<4;c++)
		{
			cout<<((cummsum(r,c)%2)==0);
		}
		cout<<endl;
	}



}