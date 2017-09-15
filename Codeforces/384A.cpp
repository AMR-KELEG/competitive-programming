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
	std::vector<std::vector<char> > grid(n,std::vector<char> (n));
	int ans=0;
	char ca[]={'C','.'};
	for(int r=0;r<n;r++)
	{
		bool in=r%2;
		for(int c=0;c<n;c++)
		{
			if(!in)
				ans++;
			grid[r][c]=ca[in];
			in=!in;
		}
	}	
	printf("%d\n", ans);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%c", grid[i][j]);
		printf("\n");
	}
}