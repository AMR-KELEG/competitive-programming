// AC
//12:19
#include "bits/stdc++.h"
using namespace std;
#define State pair<pair<int,int>,pair<int,int>>
#define R first.first
#define C first.second
#define BOOST second.first
#define COST second.second

int n,m,k;
bool vis[20][20][21]; // from 0,0 to n-1, m-1
bool grid[20][20];

bool out_of_bound(int r,int c)
{
	if (r<0 || c<0 || r>=n || c>=m)
		return 1;
	return 0;
}


int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while(T--)
	{
		memset(vis,0,sizeof vis);
		cin>>n>>m>>k;
		for (int r=0;r<n;r++)
		{
			for(int c=0;c<m;c++)
			{
				cin>>grid[r][c];
			}
		}
		bool found = 0;
		int dr[] = {-1,1,0,0};
		int dc[] = {0,0,1,-1};
		queue<State> q;
		q.push({{0,0},{k,0}});
		while(!q.empty())
		{
			int r = q.front().R;
			int c = q.front().C;
			int co = q.front().COST;
			int bo = q.front().BOOST;
			q.pop();
			vis [r][c][bo]=1;
			// cout<<r<<" "<<c<<endl;
			if (r==n-1 && c==m-1)
			{
				cout<<co<<endl;
				found = 1;
				break;
			}
			for (int i=0;i<4;i++)
			{
				int nr = r+dr[i];
				int nc = c+dc[i];
				if (out_of_bound(nr,nc))
					continue;
				if (grid[nr][nc] && bo ==0)
					continue;
				if (grid[nr][nc])
				{
					int nb = bo-1;
					if (vis[nr][nc][nb])
						continue;
					q.push({{nr,nc},{bo-1,co+1}});
				}
				else
				{
					int nb = k;
					if (vis[nr][nc][nb])
						continue;
					q.push({{nr,nc},{k,co+1}});
				}
			}

		}
		if (!found)
			cout<<-1<<endl;
	}	
}