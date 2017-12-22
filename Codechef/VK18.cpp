// AC
#include "bits/stdc++.h"
using namespace std;
const int LIM = 1000001;
int cum_sum[2*LIM];
long long int dp[LIM];

int find_val(int n)
{
	int e=0;
	int o=0;
	while(n)
	{
		int c = n%10;
		n /=10;
		if (c%2)
			o+=c;
		else
			e+=c;
	}
	return abs(e-o);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cum_sum[0] = 0;
	cum_sum[1] = 0;
	for (int n=2;n<2*LIM;n++)
	{
		cum_sum[n] = cum_sum[n-1] + find_val(n);
	}
	dp[1] = 2;
	for (int n=2;n<LIM;n++)
	{
		dp[n] = dp[n-1] + (cum_sum[2*n] - cum_sum[n]) + (cum_sum[2*n-1] - cum_sum[n]);
	}

	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
	return 0;
}