/* AC
   ACPC 2013
   Sort Edges in Increasing Order and relax distances
*/
#include "bits/stdc++.h"
using namespace std;
#define EDGE pair<int, pair<int,int> >
#define COST first
#define FROM second.first
#define TO second.second
int dp[151][151][151];
// int vis[151][151][151];
const int INF =0x3f3f3f3f;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	scanf("%d", &T);
	for (int t=1;t<=T;t++)
	{
		int n,m,q;
		scanf("%d %d %d", &n, &m, &q);
		std::vector<EDGE> edges(m);	
		for (int i=0;i<m;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a, &b, &c);
			edges[i].COST = c;
			edges[i].FROM = a;
			edges[i].TO = b;
		}
		sort(edges.begin(), edges.end());
		// for (int a=1;a<=n;a++)
		// {
		// 	for (int b=a;b<=n;b++)
		// 	{
		// 		for (int c=0;c<=n;c++)
		// 		{
		// 			dp[a][b][c] = INF;
		// 			dp[b][a][c] = INF;
		// 		}
		// 	}
		// }
		memset(dp, INF, sizeof dp);
		for (int i=0;i<m;i++)
		{
			int to = edges[i].TO;
			int from = edges[i].FROM;
			int cost = edges[i].COST;
			// if (vis[from][to][1] !=t)
			// {
			// 	vis[from][to][1] =t;
			// 	dp[from][to][1] = INF;
			// }
			dp[from][to][1] = min(cost,dp[from][to][1]);
			
			for (int src=1;src<=n;src++)
			{
				for (int no_edges = 1; no_edges<150;no_edges++)
				{
					// if(vis[src][to][no_edges+1] !=t)
					// {
					// 	dp[src][to][no_edges+1] = INF;
					// 	vis[src][to][no_edges+1] = t;
					// } 
					// if(vis[src][from][no_edges] !=t)
					// {
					// 	dp[src][from][no_edges] = INF;
					// 	vis[src][from][no_edges] = t;
					// } 
					dp[src][to][no_edges+1] = min(dp[src][to][no_edges+1], 
							dp[src][from][no_edges] + edges[i].COST);
				}
			}
		}

		while(q--)
		{
			int a,b,l;
			scanf("%d %d %d", &a, &b, &l);
			int ans = INF;
			for (int i=1;i<=min(n-1,l);i++)
			{
				// if (t != vis[a][b][i])
				// 	continue;
				ans = min(ans, dp[a][b][i]);
			}
			if (ans== INF)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", ans);
			}
		}

	}	
}