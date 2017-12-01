/* AC
   ACPC 2013
   Generate patterns
*/

#include "bits/stdc++.h"
using namespace std;

int solve(int remS, int cur_player, int m, int last_rem =-1)
{
	int prev_player = (cur_player-1) == 0 ? m: cur_player-1;
	if (remS<=0)
		return prev_player;
	if (remS==1)
		return cur_player;
	int next_player = (cur_player == m) ? 1: cur_player+1;
	int min_rem = 0;
	if (last_rem == 0)
		min_rem = 1;
	int ans[2];
	for (int d=0;d<2;d++)
	{
		ans[d] = solve(remS - (min_rem+d), next_player, m, d);
	}
	if (ans[0] == cur_player || ans[1] == cur_player)
		return cur_player;
	if (ans[0]== ans[1])
		return  ans[0];
	return -1;
}	

int find_winner(int n, int m)
{
	int winner = -1;
	if (m>=n)
	{
		// ans = m
		winner = n;
	}
	else
	{
		winner = (n%m);
		if (winner == 0)
			winner = m;
	}
	return winner;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	// int LIM = 20;
	// for (int s=1;s<=LIM;s++)
	// {
	// 	for (int m=1;m<=LIM;m++)
	// 	{
	// 		// solve(s,1,m);
	// 		// cout<<solve(s,1,m)<<" "<< find_winner(s,m)<<endl;
	// 		cout<<setw(3)<<(solve(s,1,m) == find_winner(s,m))<<" ";
	// 	}
	// 	cout<<endl;
	// }

	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n,m,x;
		scanf("%d %d %d", &n ,&m, &x);
		int winner = find_winner(n,m);		
		if (winner == x)
			printf("YES\n");
		else
			printf("NO\n");
	}	
}