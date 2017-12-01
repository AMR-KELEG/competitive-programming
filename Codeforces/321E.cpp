/* AC
   Divide and conquer DP Optimization
*/
#include "bits/stdc++.h"
using namespace std;
int count_unfamiliar[4001][4001]={};
int cum_sum[4001][4001]={};
int dp[4001][801]={};


inline void fill(const int & g, const int & l1, const int &  l2, const int &  p1, const int &  p2)
{
	if (l1>l2)
		return ;
	int lmid = (l1+l2)>>1;
	dp[lmid][g] = 1000000000;
	int best_k = -1; 
	for (int k=p1;k<=p2;k++)
	{
		int cur_ans = dp[k][g-1] + count_unfamiliar[k+1][lmid];
		if (cur_ans < dp[lmid][g])
		{
			dp[lmid][g] = cur_ans;
			best_k = k;
		}
	}
	fill(g,l1,lmid-1,p1,best_k);
	fill(g,lmid+1,l2,best_k,p2);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,k;
	scanf("%d %d", &n, &k);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			while(cum_sum[i][j] = getchar(), cum_sum[i][j] == '\n' || cum_sum[i][j] == ' ');
			cum_sum[i][j] -= '0';
			cum_sum[i][j] += cum_sum[i][j-1];
		}
	}

	for (int l=1;l<=n;l++)
	{
		for (int r=l;r<=n;r++)
		{
			count_unfamiliar[l][r] = 
			count_unfamiliar[l][r-1] + (cum_sum[r][r-1] - cum_sum[r][l-1]);
		}
	}

	for (int i=1;i<=n;i++)
	{
		dp[i][1] = count_unfamiliar[1][i];
	}

	for (int g=2;g<=k;g++)
	{
		fill(g,1,n,1,n);
	}
	printf("%d\n", dp[n][k]);

}