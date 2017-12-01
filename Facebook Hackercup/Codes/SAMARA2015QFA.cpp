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
	std::vector<long long int> money(n);
	std::vector<vector<int> > grid(n,std::vector<int> (n,0));	
	for(int r=0;r<n;r++)
	{
		for (int c = 0; c < n; ++c)
		{
			cin>>grid[r][c];
			money[r]-=grid[r][c];
		}
	}
	for(int c=0;c<n;c++)
	{
		for(int r=0;r<n;r++)
		{
			money[c]+=grid[r][c];
		}
	}
	for(int i=0;i<n;i++)
	{
		// cout<<money[i]<<" ";
		if (money[i]<0)
		{
			std::vector<long long int> ans(n,0);
			for(int j=0;j<n && money[i]<0;j++)
			{
				if(money[j]>0)
				{
					ans[j]=min(money[j],-money[i]);
					money[j]-=ans[j];
					money[i]+=ans[j];
				}
			}
			for(int j=0;j<n;j++)
				cout<<ans[j]<<" ";
			cout<<endl;
		}
		else
		{
			for(int j=0;j<n;j++)
			{
				cout<<0<<" ";
			}
			cout<<endl;
		}
	}
}