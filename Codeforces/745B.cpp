//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	std::vector<std::vector<char> > grid(n,std::vector<char> (m));
	int minr=n,minc=m,maxr=0,maxc=0;
	for(int r=0;r<n;r++)
	{
		for(int c=0;c<m;c++)
		{
			cin>>grid[r][c];
			if(grid[r][c]=='X')
			{
				minr=min(minr,r);
				maxr=max(maxr,r);
				minc=min(minc,c);
				maxc=max(maxc,c);
			}
		}
	}
	for(int r=minr;r<=maxr;r++)
	{
		for(int c=minc;c<=maxc;c++)
		{
			if(grid[r][c]=='.')
			{
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
}