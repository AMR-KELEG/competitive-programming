// AC
#include "bits/stdc++.h"
using namespace std;
int S[1001][1001];
#define MOD 10056

int solve(int n,int k)
{
	if (k==0)
	{
		return n==0;
	}
	if (n==0)
		return 0;
	if (S[n][k]!=-1)
		return S[n][k];
	return S[n][k]= (solve(n-1,k-1) %MOD + (k * solve(n-1,k))%MOD) % MOD;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(S,-1,sizeof S);		
	int T;
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		int n;
		cin>>n;
		long long int fact = 1;
		int ans = 0;
		for (int k=1;k<=n;k++)
		{
			fact = (fact * k) %MOD;
			ans+= (solve(n,k) *fact) % MOD;
			ans %= MOD; 
		}
		printf("Case %d: %d\n", t,ans);
	}
}