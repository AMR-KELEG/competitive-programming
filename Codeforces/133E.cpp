/* AC
Maximize distance and not displacement
*/
#include "bits/stdc++.h"
using namespace std;
string s;
int k;	
// -100 -> 100 (201)
int dp[201][101][51][2][2]={};// cur_pos , cur_op, rem_ch, dir
bool vis[201][101][51][2][2]={};
inline int offset(int dir)
{
	if (!dir)
		return 1;
	return -1;
}

int solve(int pos, int op_indx, int rem_ch, bool dir=0, bool change = 0)
{
	if (op_indx == s.size())
	{
		if (rem_ch)
			return 0;
		return abs(101-pos);
	}
	if (vis[pos][op_indx][rem_ch][dir][change])
		return dp[pos][op_indx][rem_ch][dir][change];
	vis[pos][op_indx][rem_ch][dir][change] = 1;
	int ans = 0;
	char op = s[op_indx];
	if (op == 'T')
	{
		if (change)
		{
			ans = abs(solve(pos+offset(dir), op_indx+1, rem_ch, dir, 0));
		}
		else
		{
			ans = abs(solve(pos, op_indx+1, rem_ch, !dir, 0));	
		}
	}
	else
	{
		if (change)
		{
			ans = abs(solve(pos, op_indx+1, rem_ch, !dir, 0));	
		}
		else
		{
			ans = abs(solve(pos+offset(dir), op_indx+1, rem_ch, dir, 0));
		}	
	}

	if (rem_ch)
	{
		ans = max(ans, abs(solve(pos, op_indx, rem_ch-1,dir,!change)));
	}
	
	return dp[pos][op_indx][rem_ch][dir][change] = ans;
}


int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>s>>k;
	cout<<solve(101,0,k);
}