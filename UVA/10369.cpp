// AC
//11:11 - > 11:42
#include "bits/stdc++.h"
using namespace std;
#define INF 1000000000
#define EPS 0.0000000000001
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
		int s,n;
		cin>>s>>n;
		std::vector<std::vector<long double> > dis(n,std::vector<long double> (n,INF));
		std::vector<long double> x(n),y(n);
		for (int i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
		}
		for (int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				long double d = (x[i]-x[j]) * (x[i]-x[j]) ;
				d += (y[i]-y[j]) * (y[i]-y[j]) ;
				d = sqrt(d);
				dis[i][j] = d;
			}
		}

		for (int k=0;k<n;k++)
		{
			for (int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if (i==k || i==j || j==k)
						continue;
					if (dis[i][j] > max(dis[i][k],dis[k][j]))
					{
						dis[i][j] = max(dis[i][k],dis[k][j]);
					}
				}
			}
		}

		long double max_dis = 0;
		int st = -1;
		int des = -1;
		for (int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{

				if (max_dis < dis[i][j])
				{
					max_dis = dis[i][j];
					st= i;
					des = j;
				}
			}
		}

		int rem_sat = s-2;
		std::vector<bool> has_sat(n,0);
		has_sat[st] = 1;
		has_sat[des] = 1;
		dis[st][des] = 0;
		while(rem_sat>=0)
		{
			for (int i=0;i<n;i++)
			{
				for (int j=0;j<n;j++)
				{
					if (dis[i][j] > max(dis[i][st],dis[j][des]))
						dis[i][j] = max(dis[i][st],dis[j][des]);
					if (dis[i][j] > max(dis[i][des],dis[j][st]))
						dis[i][j] = max(dis[i][des],dis[j][st]);
				}
			}
			max_dis = 0;
			st = -1;
			des = -1;
			for (int i=0;i<n;i++)
			{
				for (int j=0;j<n;j++)
				{
					if (abs(max_dis-dis[i][j]) < EPS)
					{
						// take it or leave it
						if (has_sat[i] || has_sat[j])
						{
							max_dis = dis[i][j];
							st = i;
							des = j;		
						}
					}
					else if (max_dis < dis[i][j])
					{
						max_dis = dis[i][j];
						st = i;
						des = j;
					}

				}
			}
			int done = 2;
			if (!has_sat[st])
			{
				done --;
				rem_sat --;
				has_sat[st] = 1;
			}
			if (!has_sat[des])
			{
				done --;
				rem_sat -- ;
				has_sat[des] = 1;
			}

			if (done == 2)
				break;
			dis[st][des] = 0;
		}
		cout<<fixed<<setprecision(2)<<max_dis<<"\n";
	}	
}