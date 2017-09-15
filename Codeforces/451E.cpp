//AC
#include "bits/stdc++.h"
#define MOD (1000000007)
using namespace std;

long long int modPow(long long int a,long long int p)
{
	if(p==0)
		return 1;
	if(p==1)
		return a;
	long long int ans = modPow(a,p/2);
	ans *= ans;
	ans %=MOD;
	if(p%2)
	{
		ans *=a;
	}
	return ans%MOD;
}

long long int inv(long long int a)
{
	return modPow(a,MOD-2);
}

long long int nCr(long long int n,long long int r)
{
	if(r>n)
		return 0;
	if(r==n)
		return 1;
	long long int ans =1;
	for(long long int i=n;i>n-r;i--)
	{
		ans = (ans*(i%MOD)) %MOD;
	}	
	long long int den =1;
	for(long long int i=2;i<=r;i++)
	{
		den = (den*i) %MOD;
	}
	ans = (ans*inv(den)) % MOD;
	return ans;
}	

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int n;
	long long int s;
	cin>>n>>s;
	if(s==0)
	{
		// 1??
		cout<< 1;
		return 0;
	}
	std::vector<long long int> f(n);
	long long int sum =0;
	for(int i=0;i<n;i++)
	{
		cin>>f[i];
		sum += f[i];
	}

	if(sum<s)
	{
		cout<<0;
		return 0;
	}

	long long int ans = nCr(s+n-1,n-1);
	for (int m=1;m< (1<<n);m++)
	{
		long long int rem = s + n - 1;
		for(int i=0;i<n;i++)
		{
			if ((m>>i) & 1)
			{
				// n-1-i is av
				rem -= f[n-1-i]+1;
			}
		}
		// cout << rem <<": "<<nCr(rem,n-1)<<endl;
		if (__builtin_popcount(m) %2)
		{
			ans -= nCr(rem,n-1);
			while (ans<0)
				ans += MOD;
		}
		else
		{
			ans += nCr(rem,n-1);
			ans %= MOD;
		}
	}
	cout<<ans %MOD;
}