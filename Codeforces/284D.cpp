//AC
//10:50 - 11:03
#include "bits/stdc++.h"
using namespace std;
long long int dp[200001][2];
int n;
std::vector<int> a;
long long int solve(int val, bool add)
{
	if (val<=0 || val>n)
		return 0;
	if (dp[val][add] !=-1)
		return dp[val][add];
	dp[val][add] = -2;
	long long int next_indx,ans;
	if (add)
	{
		next_indx = val + a[val];
		ans = a[val];
	} 
	else
	{
		next_indx = val - a[val];
		ans = a[val];
	}
	if (solve (next_indx,!add)==-2)
		ans = -2;
 	else
 		ans +=solve (next_indx,!add);
	return dp[val][add]=ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(dp,-1,sizeof dp);
	cin>>n;
	a = std::vector<int> (n+1);
	for(int i=2;i<=n;i++)
		cin>>a[i];		
	for(int i=1;i<n;i++)
	{
		if (solve (i+1,0) == -2)
		{
			printf("-1\n");
			;
		}
		else
		{
			// cout<<i+solve(i+1,0)<<" ";
			printf("%I64d\n", i+solve(i+1,0));
		}
	}
}