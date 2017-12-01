#include <bits/stdc++.h>
using namespace std;
#define ll long long
int sum, n;
long long int dp[5001][50];
int vis[5001][50];
int tt = 1;
int C[50] , V[50];
int co;
 
long long int solve(int rem_sum, int i)
{
	if (i== n)
	{
		return rem_sum == 0;
	}
	if (rem_sum < 0)
		return 0;
	if (rem_sum == 0)
		return 1;
	if (vis[rem_sum][i] == tt)
	{
		return dp[rem_sum][i];
	}
	vis[rem_sum][i] = tt;
	long long int ans = solve(rem_sum, i+1);
	if (co <= C[i])
		ans += solve(rem_sum - (co * V[i]), i+1);
	return dp[rem_sum][i] = ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif	
	int T;
	// cin>>T;
	scanf("%d", &T);
	for (int t = 1;t<=T;t++)
	{
		long long int ans =0;
		// cin>>sum>>n;
		scanf("%d%d", &sum , &n);
		int max_count = 0;
		for (int i=0;i<n;i++)
		{
			// cin>>V[i]>>C[i];
			scanf("%d%d", &V[i] , &C[i]);
			max_count = max (max_count, C[i]);
		}
		for (co = 1;co<=max_count;co++)
		{
			ans += solve(sum,0);
			tt++;
		}
		printf("Case %d: %lld\n", t,ans);
	}
}