/* AC O(n^2)
   DP + Preprocessing
*/
#include "bits/stdc++.h"
using namespace std;
int dp[4000][4000]; // indx of first and indx of second
int next_indx[4000][4000];// find indx of val after first and equal to second
std::vector<int> v;
#define INF 0x3f3f3f3f

int n;
inline int solve(const int & st, const int & en)
{
	// find next value after en which equals st
	if (dp[st][en]!=-1)
		return dp[st][en];
	int indx = next_indx[en][v[st]];
	if (indx!=INF)
		return dp[st][en] = 1+ solve(en,indx);
	return dp[st][en] = 0;
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(dp, -1, sizeof dp);
	memset(next_indx, INF, sizeof next_indx);
	scanf("%d", &n);
	unordered_map<int,int> mp;
	v = std::vector<int> (n);
	int cur_indx = 0;
	for (int i=0,_;i<n;i++)
	{
		scanf("%d", &_);
		if (mp.find(_) == mp.end())
		{
			mp[_] = cur_indx++;
		}
		v[i] = mp[_];
	}
	for (int i=n-1;i>=0;i--)
	{
		for (int j=i-1;j>=0;j--)
		{
			next_indx[j][v[i]] = i;
		}
	}
	int ans = 1;
	for (int st=0;st<n;st++)
	{
		for (int en=st+1;en<n;en++)
		{
			ans = max(ans, 2+solve(st,en));
		}
	}
	printf("%d\n", ans);
}