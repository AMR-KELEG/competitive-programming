//AC
#include "bits/stdc++.h"
using namespace std;
#define State pair<int,pair<int,int> >
#define INF 1000000000
int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};
#define R second.first
#define C second.second
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
		int n,m;
		cin>>n>>m;
		std::vector<std::vector<int> > grid(n,std::vector<int> (m));
		for(int r=0;r<n;r++)
		{
			for(int c=0;c<m;c++)
				cin>>grid[r][c];
		}
		std::vector<std::vector<int> > cost(n,std::vector<int> (m,INF));
		std::vector<std::vector<bool> > vis(n,std::vector<bool> (m,0));
		priority_queue<State> q;
		q.push({-grid[0][0],{0,0}});
		cost[0][0] = grid[0][0];
		while(!q.empty())
		{
			State cur_state = q.top();
			int cur_cost = -cur_state.first;
			int cur_r = cur_state.R;
			int cur_c = cur_state.C;
			q.pop();
			if (cur_r == n-1 && cur_c == m-1)
			{
				printf("%d\n", cur_cost);
				break;
			}
			if (vis[cur_r][cur_c])
				continue;
			if (cur_cost > cost[cur_r][cur_c])
				continue;
			vis[cur_r][cur_c] = 1;
			for (int i=0;i<4;i++)
			{
				int r = cur_r + dr[i];
				int c = cur_c + dc[i];
				if (r<0 || c< 0 || r==n || c==m)
					continue;
				if (cur_cost + grid[r][c] >= cost[r][c])
					continue;
				cost[r][c] = cur_cost + grid[r][c];
				q.push({-cost[r][c],{r,c}});
			}
		}
	}	
}