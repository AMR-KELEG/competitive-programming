/* AC
   DP on small K values
*/
#include "bits/stdc++.h"
using namespace std;
int arr[1000001];
int n;
int dp[1000001][60];

inline int solve_dp(int indx, const int & step)
{
	if (indx>n)
		return 0;
	if (dp[indx][step] != -1)
		return dp[indx][step];
	return dp[indx][step] = 1 + solve_dp(indx + arr[indx] + step, step);
}

inline int solve_linear(int indx, const int & step)
{
	int steps = 0;
	while(indx<=n)
	{
		steps++;
		indx = indx + arr[indx] + step;
	}
	return steps;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	for (int i=1,v;i<=n;i++)
	{
		scanf("%d", &v);
		arr[i] = v;
	}	
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int start_indx, step;
		scanf("%d %d", &start_indx, &step);
		if (step<60)
		{
			printf("%d\n", solve_dp(start_indx, step));
		}
		else
		{
			printf("%d\n", solve_linear(start_indx, step));
		}
	}
}