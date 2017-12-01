// AC
#include "bits/stdc++.h"
using namespace std;

long double dp[401][401]={};

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,k;
	cin>>n>>k;
	dp[0][0] = 1;
	
	for(int st = 0;st<k;st++)
	{
		for(int h=0;h<n;h++)
		{
			dp[h][st+1] +=0.5*dp[h][st];
			dp[h+1][st+1] +=0.5 * dp[h][st];
		}
		dp[n][st+1] += dp[n][st]*0.5;
		dp[n-1][st+1] += dp[n][st]*0.5;
	}
	long double ans = 0;
	for (int h=0;h<=n;h++)
	{
		ans += h* dp[h][k];
	}
	cout<<fixed<<setprecision(9)<<ans;
}