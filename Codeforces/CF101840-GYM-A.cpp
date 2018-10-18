// ECPC 2017
// AC

#include<bits/stdc++.h>
using namespace std;

int N;
long double p;
int x,y,k;

long double dp[50][50][3001];
int vis[50][50][3001];
int t;

bool valid_move(int pos_x, int pos_y)
{
	if (pos_x < 0 || pos_y < 0 || pos_x == N || pos_y == N || pos_x==pos_y)
		return 0;
	return 1;	
}

long double solve(int pos_x, int pos_y, int rem_r)
{
	if (pos_x < 0 || pos_y < 0 || pos_x == N || pos_y == N || pos_x==pos_y)
		return 0;
	if (vis[pos_x][pos_y][rem_r] == t)
		return dp[pos_x][pos_y][rem_r];
	
	vis[pos_x][pos_y][rem_r] = t;
	if (rem_r == 0)
	{
		if (pos_x == x && pos_y == y)
			return dp[pos_x][pos_y][rem_r] = 1;
		return dp[pos_x][pos_y][rem_r] = 0;
	}
	// probability of each pair = 1 / nC2
	long double prob_round = 1.0 / (N-1); 
	long double ans = (1-p) * solve(pos_x, pos_y, rem_r -1);
	int valid_moves = 0;

	if (abs(pos_x-pos_y) == 1)
	{
		// adjancent
		ans += prob_round * p * solve(pos_y, pos_x, rem_r - 1);
		if (valid_move(pos_y, pos_x))
			valid_moves ++;
	}
	ans += prob_round * p * solve(pos_x-1, pos_y, rem_r - 1);
	ans += prob_round * p * solve(pos_x+1, pos_y, rem_r - 1);
	ans += prob_round * p * solve(pos_x, pos_y-1, rem_r - 1);
	ans += prob_round * p * solve(pos_x, pos_y+1, rem_r - 1);

	int dx []= {-1, 1, 0, 0};
	int dy []= {0, 0, -1, 1};
	for (int i=0;i<4;i++)
	{
		if (valid_move(pos_x+dx[i], pos_y+dy[i]))
			valid_moves++;
	}
	// Prob of same location = ??

	ans += (N-1- valid_moves) * prob_round * p * solve(pos_x, pos_y, rem_r - 1);
	return dp[pos_x][pos_y][rem_r] = ans;
}

long double dp_1[50][3001];
int vis_1[50][3001];

long double solve_1(int pos_x, int rem_r)
{
	if (pos_x <0 || pos_x == N)
		return 0;
	if (vis_1[pos_x][rem_r] == t)
		return dp_1[pos_x][rem_r];
	if (rem_r == 0)
	{
		return dp_1[pos_x][rem_r] = (pos_x == x);
	}
	vis_1[pos_x][rem_r] = t;
	long double ans = (1-p) * solve_1(pos_x, rem_r -1);;
	long double prob_round = 1.0 / (N-1); 
	ans += prob_round * p * solve_1(pos_x - 1, rem_r - 1);
	ans += prob_round * p * solve_1(pos_x + 1, rem_r - 1);
	if (pos_x == 0 || pos_x == N-1)
		ans += (N-2) * prob_round * p * solve_1(pos_x, rem_r - 1);
	else
		ans += (N-3) * prob_round * p * solve_1(pos_x, rem_r - 1);
	return dp_1[pos_x][rem_r] = ans;
}
int main()
{
	int T;
	freopen("in.txt", "r", stdin);
	cin>>T;
	for (t=1;t<=T;t++)
	{
		cin>>N>>p>>x>>y>>k;

		long double ans = 1;
		if (N==1)
			ans = 1;
		else if (x==y)
			ans = solve_1(x, k);
		else
			ans = solve(y, x, k);
		printf("Case %d: %0.5LF\n", t, ans);
		// cout<<fixed<<setprecision(5)<<solve<<"\n";
	}

}