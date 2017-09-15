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
	std::vector<std::vector<bool> > grid(n+1,std::vector<bool> (m+1,0));
	std::vector<std::vector<short> > VCS(n+1,std::vector<short> (m+1,0)),HCS(n+1,std::vector<short> (m+1,0));
	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=m;c++)
		{
			short v;
			cin>>v;grid[r][c]=v;
			HCS[r][c]=HCS[r][c-1]+grid[r][c];
		}
	}
	for(int c=1;c<=m;c++)
	{
		for(int r=1;r<=n;r++)
		{
			VCS[r][c]=VCS[r-1][c]+grid[r][c];
		}
	}
	int ans=0;
	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=m;c++)
		{
			if(!grid[r][c])
			{
				if(HCS[r][c])
					ans++;
				if(VCS[r][c])
					ans++;
				if(HCS[r][m]-HCS[r][c])
					ans++;
				if(VCS[n][c]-VCS[r][c])
					ans++;
			}
		}
	}
	cout<<ans;
}