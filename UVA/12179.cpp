//AC
#include "bits/stdc++.h"
#define INF 100007
using namespace std;
int dis[100][100];
long double dp[100][3000];
int vis[100][3000];
int t;
int n,r;
long double solve(int edges,int cost)
{
	if(cost<0)
		return 0;
	if(edges==0)
	{
		return dp[edges][cost] = (cost==0);
	}
	if(t == vis[edges][cost])
	{
		return dp[edges][cost];
	}
	vis[edges][cost] = t;
	long double ans = 0;
	for(int c=1;c<=r;c++)
	{
		ans += (solve(edges-1,cost-c)/r);
	}
	return dp[edges][cost]=ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	for(t=1;t<=T;t++)
	{
		if(t!=1)
			cout<<"\n";
		cin>>n>>r;
		char con;
		for(int r=0;r<n;r++)
		{
			for(int c=0;c<n;c++)
			{
				cin>>con;
				if(con == 'N')
				{
					dis[r][c]=INF;
				}
				else
				{
					dis[r][c]=1;
				}
				if(r==c)
					dis[r][c]=0;
			}
		}
		// 1) Find dis
		for(int piv = 0;piv<n;piv++)
		{
			for(int st=0;st<n;st++)
			{
				for(int en =0;en<n;en++)
				{
					if(st == en)
					{
						dis[st][en]=0;
						continue;
					}
					if (dis[st][en]>dis[st][piv]+dis[piv][en])
					{
						dis[st][en]=dis[st][piv]+dis[piv][en];	
					}
				}
			}
		}

		int couples;
		cin>>couples;

		cout<<fixed<<setprecision(6)<<"Case "<<t<<"\n";
		for (int i=0;i<couples;i++)
		{
			int a,b,m;
			cin>>a>>b>>m;
			a--;b--;
			int edges = dis[a][b];
			long double ans =0;
			for(int cost = edges;cost<=min(edges*r,m);cost++)
			{
				ans += solve(edges,cost);
			}
			cout<<ans<<"\n";
		}

	}
}