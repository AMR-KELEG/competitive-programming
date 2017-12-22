/* AC
   Typical Game Theory Problem -> PATTERNS!
*/
#include "bits/stdc++.h"
using namespace std;
const int N=1000;
int dp[N];
std::vector<int> primes;
void find_primes()
{
	memset(dp,-1,sizeof dp);
	std::vector<bool> is_prime(N+1,1);
	for (int i=2;i<N;i++)
	{
		if (is_prime[i])
		{
			primes.push_back(i);
			for (int m=2;m*i<N+1;m++)
				is_prime[m*i]=0;
		}
	}
}

int solve(int i)
{
	if (i==0)
		return 0;
	if (dp[i]!=-1)
		return dp[i];
	if (!solve(i-1))
		return dp[i] = 1;
	for (int p:primes)
	{
		if (p>i)
			break;
		for (int x=1;round(pow(p,x))<=i;x++)
		{
			if (!solve(i-round(pow(p,x))))
				return dp[i] = 1;
		}
	}
	return dp[i] = 0;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	// find_primes();
	// for (int i=0;i<N;i++)
	// {
	// 	if (solve(i) != (i%6!=0))
	// 		cout<<i<<": "<<solve(i)<<endl;
	// }
	// return 0;

	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		if (n%6)
			printf("Chef\n");
		else
			printf("Misha\n");
	}
}