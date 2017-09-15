//AC
#include "bits/stdc++.h"
using namespace std;
long long int pow2[62];

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	pow2[0]=1;
	for(int i=1;i<62;i++)
		pow2[i] =2*pow2[i-1];
	int n,m;
	cin>>n>>m;
	std::vector<std::vector<char> > grid(n,std::vector<char>(m));
	std::vector<int> rs(n);
	std::vector<int> cs(m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>grid[i][j];
		}
	}
	
	long long int ans =- (m*n);
	for(int r=0;r<n;r++)
	{
		for(int c=0;c<m;c++)
		{
			rs[r] += (grid[r][c]=='0');
		}
		ans+= pow2[rs[r]]-1;
		ans+= pow2[m-rs[r]]-1;
	}

	for(int c=0;c<m;c++)
	{
		for(int r=0;r<n;r++)
		{
			cs[c] += (grid[r][c]=='0');
		}
		ans+= pow2[cs[c]]-1;
		ans+= pow2[n-cs[c]]-1;
	}
	cout<<ans;
}