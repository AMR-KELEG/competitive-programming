#include "bits/stdc++.h"
using namespace std;
std::vector<int> ener_boost, s;
int N;
std::vector<int> cum_s;
int solve(long long int A,long long int B,int indx =0, bool A_turn = 1)
{
	if (indx == N)
		return 0;
	if (A_turn)
	{
		int ans = s[indx] + cum_s[indx+1] - solve(A + ener_boost[indx], B, indx+1, !A_turn);
		if (A>=B && A)
		{
			ans = max(ans, cum_s[indx] - solve(A-B, 0 , indx, !A_turn));
		}
		return ans;
	}
	else
	{
		int ans = s[indx] + cum_s[indx+1] - solve(A, B+ ener_boost[indx], indx+1, !A_turn);
		if (B>=A && B)
		{
			ans = max(ans, cum_s[indx] - solve(0, B-A , indx, !A_turn));
		}
		// will win rem - ans
		return ans;
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int A, B;
	scanf("%d %lld %lld", &N, &A, &B);
	ener_boost = std::vector<int> (N);
	s = std::vector<int> (N);
	cum_s = std::vector<int> (N+1,0);
	long long int total_s = 0;
	for (int i=0;i<N;i++)
	{
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		ener_boost[i] = t1;
		s[i] = t2;
		total_s += s[i];
	}
	for (int i=N-1;i>=0;i--)
	{
		cum_s[i] = s[i] + cum_s[i+1];
	}
	int A_s = solve(A,B);
	printf("%d %d\n", A_s, total_s - A_s);
}