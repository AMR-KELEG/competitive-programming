// AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> v;
int n;
long long int dp[100000][2];

long long int solve(int indx, bool pos)
{
	if (indx == n-1)
		return 0;
	if (dp[indx][pos]!=-1)
		return dp[indx][pos];
	long long int ans = 0;
	if (pos)
	{
		ans = max(ans, solve(indx+1, !pos) + abs(v[indx]-v[indx+1]));
	}
	else
	{
		ans = max(ans, solve(indx+1, !pos) - abs(v[indx]-v[indx+1]));
	}
	return dp[indx][pos] = ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	v = std::vector<int> (n);
	for (int i=0,val;i<n;i++)	
	{
		scanf("%d", &val);
		v[i] = val;
	}
	long long int ans = 0;
	for (int i=0;i<n;i++)
	{
		ans = max(ans, solve(i,1));
	}
	printf("%I64d\n", ans);
}
