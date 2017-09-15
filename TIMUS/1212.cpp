//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int m,n;
	cin>>n>>m;
	std::vector<std::vector<int> > ships_at_row(n);
	std::vector<std::vector<int> > ships_at_col(m);	
	int l;
	cin>>l;
	int r,c,len;
	char dir;
	for(int i=0;i<l;i++)
	{
		cin>>c>>r>>len>>dir;
		r--;
		c--;
		if(dir=='H')
		{
			for(int row=r-1;row<=r+1;row++)
			{
				if(row>=n || row<0)
					continue;
				for(int col=c-1;col<=c+len;col++)
				{
					if(col>=m || col<0)
						continue;
					ships_at_row[row].push_back(col);
					ships_at_col[col].push_back(row);		
				}
			}
		}
		else
		{
			for(int col=c-1;col<=c+1;col++)
			{
				if(col>=m || col<0)
					continue;
				for(int row=r-1;row<=r+len;row++)
				{
					if(row>=n || row<0)
							continue;
					ships_at_row[row].push_back(col);
					ships_at_col[col].push_back(row);		
				}
			}
		}
	}	
	// for(int r=0;r<m;r++)
	// {
	// 	cout<<"At col "<<r<<endl;
	// 	for(int i=0;i<ships_at_col[r].size();i++)
	// 		cout<<ships_at_col[r][i]<<" ";
	// 	cout<<endl<<endl;
	// }
	int k;
	cin>>k;
	long long int ans=0;
	for(int r=0;r<n;r++)
	{
		if(ships_at_row[r].size()==0)
		{
			if(m>=k)
				ans += (m-k)+1;
			continue;
		}
		sort(ships_at_row[r].begin(), ships_at_row[r].end());
		ships_at_row[r].push_back(m);
		int last=-1;
		for(int i=0;i<ships_at_row[r].size();i++)
		{
			int cur_len = ships_at_row[r][i]-last-1;
			last = ships_at_row[r][i];
			if(cur_len<k)
				continue;
			// cout<<"Row "<<r<<" Len: "<<cur_len<<endl;
			ans += (cur_len-k)+1;
		}
	}
	for(int c=0;c<m;c++)
	{
		if(ships_at_col[c].size()==0)
		{
			if(n>=k)
				ans += (n-k)+1;
			continue;
		}
		sort(ships_at_col[c].begin(), ships_at_col[c].end());
		ships_at_col[c].push_back(n);
		int last=-1;
		for(int i=0;i<ships_at_col[c].size();i++)
		{
			int cur_len = ships_at_col[c][i]-last-1;
			last = ships_at_col[c][i];
			if(cur_len<k)
				continue;
			// cout<<"Col "<<c<<" Len: "<<cur_len<<endl;
			ans += (cur_len-k)+1;
		}
	}
	if(k>1)
		cout<<ans;
	else
		cout<<ans/2;
}