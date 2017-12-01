// AC
#include "bits/stdc++.h"
using namespace std;
int har[5][5];
int her[5][5];
const int MOD = 1000000007;

int dp[(1<<25)][2];
char vis[(1<<25)][2];
int t;
int har_win[12];
int her_win[12];
int perm[25];
void gen_masks()
{
	int cur_indx = 0;
	for(int r=0;r<5;r++)
	{
		int cur_mask = 0;
		int cur_mask_2 = 0;
		for (int c=0;c<5;c++)
		{
			cur_mask |= (1<<har[r][c]);
			cur_mask_2 |= (1<<her[r][c]);
		}
		her_win[cur_indx] = cur_mask_2;
		har_win[cur_indx++] = cur_mask;
	}
	for (int c=0;c<5;c++)
	{
		int cur_mask = 0;
		int cur_mask_2 = 0;
		for(int r=0;r<5;r++)
		{
			cur_mask |= (1<<har[r][c]);
			cur_mask_2 |= (1<<her[r][c]);
		}
		her_win[cur_indx] = cur_mask_2;
		har_win[cur_indx++] = cur_mask;
	}
	int cur_mask =0;
	int cur_mask_2=0;
	int cur_mask_3 =0;
	int cur_mask_4=0;
	for (int r=0;r<5;r++)
	{
		cur_mask |= (1<<har[r][r]);
		cur_mask_2 |= (1<<har[r][4-r]);
		cur_mask_3 |= (1<<her[r][r]);
		cur_mask_4 |= (1<<her[r][4-r]);
	}
	har_win[10] = cur_mask;
	har_win[11] = cur_mask_2;
	her_win[10] = cur_mask_3;
	her_win[11] = cur_mask_4;
}

inline bool har_w(const int & m)
{
	int ways = 0;
	for (int i=0;i<12;i++)
	{
		if ((m & har_win[i])== har_win[i])
			ways ++;
	}
	return ways>=5;
}
inline bool her_w(const int & m)
{
	int ways = 0;
	for (int i=0;i<12;i++)
	{
		if ((m & her_win[i])== her_win[i])
			ways++;
	}
	return ways>=5;
}

int solve(int mask = 0, bool turn =0)
{	
	bool har = har_w(mask);
	bool her = her_w(mask);
	if (her)
		return 0;
	if (har)
		return 1;
	if (vis[mask][turn] == t)
		return dp[mask][turn];
	vis[mask][turn] = t;
	int ans = 0;
	if (!turn)
	{
		for (int i=0;i<=24;i++)
		{
			if (mask & (1<<i))
				continue;
			ans = ans + solve(mask | (1<<i), !turn);
			while (ans>=MOD)
				ans-= MOD;
		}
	}
	else
	{
		for (int i=0;i<25;i++)
		{
			if (mask & (1<<perm[i]))
				continue;
			ans = ans + solve(mask | (1<<perm[i]), !turn);
			while (ans>=MOD)
				ans-= MOD;
			break;
		}	
	}

	return dp[mask][turn] = ans;
}



int main()
{
	int T;
	scanf("%d", &T);
	for (t=1;t<=T;t++)
	{
		int temp;
		for (int i=0;i<5;i++)
		{
			for (int j=0;j<5;j++)
			{
				scanf("%d", &temp);
				har[i][j] = temp;
				har[i][j]--;
			}
		}
		for (int i=0;i<5;i++)
		{
			for (int j=0;j<5;j++)
			{
				scanf("%d", &temp);
				her[i][j] = temp;
				her[i][j]--;
			}
		}
		for (int i=0;i<25;i++)
		{
			scanf("%d", &temp);
			perm[i] = temp;
			perm[i]--;
		}
		gen_masks();
		printf("%d\n", solve());
	}
}