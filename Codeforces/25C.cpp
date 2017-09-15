#include "bits/stdc++.h"
using namespace std;
long long int dis[305][305];
long long int sum=0;
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>dis[i][j];
			sum+=dis[i][j];
		}
	}
	int k;
	cin>>k;
	int a,b,c;
	for(int i=0;i<k;i++)
	{
		cin>>a>>b>>c;
		for(int st=1;st<=n;st++)
		{
			for(int v=1;v<=n;v++)
			{
				if(dis[st][v]>dis[st][a]+c+dis[b][v])
				{
					sum+=(dis[st][a]+c+dis[b][v])-dis[st][v];
					dis[st][v]=dis[st][a]+dis[b][v]+c;
					sum+=(dis[a][st]+c+dis[v][b])-dis[v][st];
					dis[v][st]=dis[a][st]+dis[v][b]+c;
				}
				/*
				*/
			}
		}
		cout<<std::fixed<<setprecision(0)<<sum*0.5<<" ";
	}

}

/*
2
0 5
5 0
1
1 2 3
*/