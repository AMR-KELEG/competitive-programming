/* AC
- Basic Sprague Grunde 
*/
#include "bits/stdc++.h"
using namespace std;
int dp[51][51];

int solve(int n, int k)
{
	if (n<k)
		return 0;
	if (dp[n][k]!=-1)
		return dp[n][k];
	set<int> gr;
	for (int l=k-1;l<n;l++)
	{
		gr.insert(solve(l-k+1,k) ^ solve(n-(l+1),k));
	}
	for (int i=0;i<100000;i++)
	{
		if (gr.find(i)==gr.end())
			return dp[n][k] = i;
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(dp, -1, sizeof dp);
	int T;
	scanf("%d", &T);
	for (int t=1;t<=T;t++)
	{
		int n,k;
		scanf("%d %d", &n, &k);
		if (solve(n,k))
			printf("Case %d: Winning\n", t);
		else
			printf("Case %d: Losing\n", t);
	}	
}