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
	char t;
	char grid[1005][1005];
	int totalbombs=0;
	map<int,int>br;
	map<int,int>bc;
	
	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=m;c++)
		{
			cin>>t;
			grid[r][c]=t;
			if(grid[r][c]=='*')
			{
				totalbombs++;
				br[r]++;
				bc[c]++;
				// cout<<r<<" "<<br[r]<<endl;
				
			}
		}
	}

	for(int r=1;r<=n;r++)
	{
		int b;
		for(int c=1;c<=m;c++)
		{
			if(grid[r][c]=='*')
			{
				b=-1;
			}	
			else
			{
				b=0;
			}
			b+=br[r];
			b+=bc[c];
			// cout<<r<<" "<<c<<" "<<b<<" "<<br[r]<<" "<<bc[c]<<endl;
			if(b==totalbombs)
			{
				cout<<"YES\n";
				cout<<r<<" "<<c;
				return 0;
			}
		}
	}
	cout<<"NO";
	// cout<<multr<<" "<<multc;
}