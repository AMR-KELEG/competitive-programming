#include "bits/stdc++.h"
#define EPS 0.0000000001
using namespace std;
const long double INF=10000.00;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	while(n)
	{
		std::vector<int> x(n);
		std::vector<int> y(n);
		for(int i=0;i<n;i++)
			cin>>x[i]>>y[i];
		long double dis = INF;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int dx = x[i]-x[j];
				int dy = y[i]-y[j];
				long double cur_d = (dx*dx)+(dy*dy);
				cur_d = sqrt(cur_d);
				dis = min(dis,cur_d);
			}
		}
		if (dis<INF)
		{
			cout<<fixed<<setprecision(4)<<dis<<"\n";
		}
		else
		{
			cout<<"INFINITY\n";
		}
		cin>>n;
	}
}