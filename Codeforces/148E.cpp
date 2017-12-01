/* AC - Complexity O(100^4) !!
   Requires Preprocessing
*/
#include "bits/stdc++.h"
using namespace std;
int Len[100];
int dp[100][10001];
int shelf_items[100][100];
int values_taking_items[100][101];
int shelves, items;
#define INF 10000000
int solve(int shelf, int rem)
{
	if (rem<0)
		return -INF;
	if (rem==0)
		return 0;
	if (shelf == shelves)
		return 0;
	if (dp[shelf][rem] !=-1)
		return dp[shelf][rem];
	int ans = 0;
	for (int take = 0; take<=min(rem, Len[shelf]);take++)
	{
		ans = max(values_taking_items[shelf][take] + solve(shelf+1, rem-take), ans);
	}
	return dp[shelf][rem] = ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(dp,-1,sizeof dp);
	scanf("%d %d", &shelves, &items);		

	for (int i=0;i<shelves;i++)
	{
		int l;
		scanf("%d", &l);
		Len[i] = l;
		for (int j=0,v;j<l;j++)
		{
			scanf("%d", &v);
			shelf_items[i][j] = v;
		}
		int left_val = 0;
		for (int l=-1;l<Len[i]-1;l++)
		{
			int right_val = 0;
			for (int r=Len[i]-1;r>l;r--)
			{
				right_val+= shelf_items[i][r];
				int cur_len = (Len[i]-r) + (l+1);
				values_taking_items[i][cur_len] = max(values_taking_items[i][cur_len], 
					right_val + left_val);
			}
			left_val += shelf_items[i][l+1];
			// l+2
			values_taking_items[i][l+2] = max(values_taking_items[i][l+2], left_val);
		}
	}
	printf("%d\n", solve(0,items));
}