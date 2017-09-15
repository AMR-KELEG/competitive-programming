#include "bits/stdc++.h"
using namespace std;
#define INF 1000000007

// Floyd here
int cost[60][60][60]; // car - src - des
int dis[60][60][60]; // src des changes
int vis[60][60][60];
int r;
int n,m,R;
#define state pair<pair<int,int>,pair<int,int>> 
#define COST first.first
#define CHA first.second
#define NODE second.first
#define CAR second.second

// -cost changes node car_indx 
int solve(int cur, int des, int ch)
{
	if(cur == des)
		return 0;
	if(dis[cur][des][ch]!=-1)
		return dis[cur][des][ch];
	priority_queue <state>q;
	for(int c=0;c<m;c++)
	{
		for(int node=0;node<n;node++)
		{
			if(node == cur)
				continue;
			q.push({{-cost[c][cur][node],-ch},{node,c}});
		}
	}
	while(!q.empty())
	{
		state cur_s = q.top();
		q.pop();
		int cur_node = cur_s.NODE;
		int cur_cost = -cur_s.COST;
		int cur_changes = -cur_s.CHA;
		int cur_car = cur_s.CAR;
		if(vis[cur_node][cur_car][cur_changes] == r)
		{
			continue;
		}
		vis[cur_node][cur_car][cur_changes] = r;
		if(dis[cur][cur_node][ch]==-1)
			dis[cur][cur_node][ch] = cur_cost;

		for(int c=0;c<m && cur_changes;c++)
		{
			if(c==cur_car)
				continue;
			q.push({{-cur_cost,-(cur_changes-1)},{cur_node,c}});
		}
		for(int node =0;node<n;node++)
		{
			if(node == cur_node)
				continue;
			if(vis[node][cur_car][cur_changes] == r)
				continue;
			q.push({{-(cur_cost+cost[cur_car][cur_node][node]),-cur_changes},{node,cur_car}});
		}
	}
	return dis[cur][des][ch];
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(dis,-1,sizeof dis);
	cin>>n>>m>>R;
	for(int c=0;c<m;c++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin >> cost[c][i][j];
			}
		}
	}
	for(r =1;r<=R;r++)
	{
		int s,d,k;
		cin>>s>>d>>k;
		s--;
		d--;
		k = min(k,59);
		int ans = solve(s,d,k);
		printf("%d\n", ans);
	}
}