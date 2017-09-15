//AC
#include "bits/stdc++.h"
#define INF 1000000
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	for(int test = 1;test<=T;test++)
	{
		int n;
		cin>>n;
		int xl = -INF , xr = INF;
		int yd = -INF , yu = INF;
		while(n--)
		{
			int x,y;
			cin>>x>>y;
			xl = max(xl,x);
			yd = max(yd,y);
			cin>>x>>y;
			xr = min(xr,x);
			yu = min(yu,y);
		}
		long long int ans;
		if(xl>=xr || yd>=yu)
			ans=0;
		else
		{
			ans = (xr-xl);
			ans*= (yu-yd);
		}
		printf("Case %d: %d\n", test,ans);
	}
}