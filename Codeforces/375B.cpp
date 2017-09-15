//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("a.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	std::vector<string> grid(n+1,string(m+1,' '));
	std::vector<std::vector<int> > sum(n+1,std::vector<int> (m+1,0));
	for (int r=1;r<=n;r++)
	{
		for(int c=1;c<=m;c++)
		{
			cin>>grid[r][c];
		}
	}
	for (int r=n;r>=1;r--)
	{
		sum[r][m] = (grid[r][m]=='1');
		for(int c=m-1;c>=1;c--)
		{
			if (grid[r][c]=='0')
			{
				sum[r][c] = 0;
			}
			else
			{
				sum[r][c]= 1+sum[r][c+1];
			}
		}
	}
	int ans = 0;
	for (int start = 1 ;start<=m;start++)
	{
		// find values of sum[r][start]
		std::vector<int> v;
		for (int r=1;r<=n;r++)
		{
			if (sum[r][start])
			{
				v.push_back(sum[r][start]);
			}
		}
		sort (v.begin(), v.end());
		int indx = 0;
		ans = max(ans,(int)v.size());
		for (int en = (start+1) ; en <=m && int(v.size())>0 && indx<v.size();en++)
		{
			// check all remaining rows
			indx = lower_bound(v.begin(), v.end(), en-start+1)-v.begin();
			ans = max(ans,(int(v.size())-indx) * (en-start+1));
		}
	}
	cout<<ans<<endl;
}