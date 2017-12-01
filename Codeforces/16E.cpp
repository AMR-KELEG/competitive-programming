/* AC
   Probabilities + DP
*/
#include "bits/stdc++.h"
using namespace std;
long double dp[1<<19];
bool vis[1<<19];
long double p[19][19];
int n;
long double solve(int m)
{
	if (m == (1<<n)-1)
		return 1;
	if (vis[m])
		return dp[m];
	vis[m] = 1;
	std::vector<bool> is_winner(n, 0);
	std::vector<int> winners;
	std::vector<int> losers;
	for (int i=0;i<n;i++)
	{
		if (m & (1<<i))
		{
			winners.push_back(i);
			is_winner[i] = 1;
		}
	}
	for (int i=0;i<n;i++)
	{
		if (!is_winner[i])
			losers.push_back(i);
	}
	long double ans = 0;
	long double PROB_PAIR = 0.5 * int(winners.size()) * int(1 + winners.size());
	for (int w:winners)
	{
		for (int l:losers)
		{
			ans += solve(m | (1<<l)) * (p[w][l] / PROB_PAIR);
		}
	}
	return dp[m] = ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	for (int i=0;i<n;i++)
	{
		for (int j=0,x;j<n;j++)
		{
			cin>>p[i][j];
		}
	}
	for (int i=0;i<n;i++)
	{
		printf("%0.9LF ", solve((1<<i)));
	}
}