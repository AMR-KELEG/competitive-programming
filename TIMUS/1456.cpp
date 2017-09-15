//Done: 12:08
#include "bits/stdc++.h"
#define INF 1000000007
using namespace std;

int get_phi(int val)
{
	int limit = val;
	int phi = 1;
	for (int i=2;i*i<=limit;i++)
	{
		if (val%i == 0)
		{
			int cur_m = 1;
			while (val % i == 0)
			{
				val /= i;
				cur_m *= i;
			} 
			phi *= (cur_m)- (cur_m/i);
		}
	}
	if (val>1)
		phi*= val-1;
	return phi;
}

int find_pow(int val, int p, int mod)
{
	if (p==0)
		return 1;
	if (p==1)
	{
		return val;
	}
	long long int ans1 = find_pow(val, p>>1 , mod);
	long long int ans2 = ans1;
	if (p%2)
	{
		ans2 = (ans2* val) % mod;
	}
	return (ans1 * ans2) % mod;
}


int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int a,n;
	cin>>a>>n;
	if (__gcd(a,n) != 1)
	{
		cout<<0;
	}	
	else
	{
		int phi = get_phi(n);
		int min_valid_pow = phi;
		// find all divisors of phi
		for (int i=2;i*i <= phi; i++)
		{
			if (phi % i == 0)
			{
				if (find_pow(a, i , n) == 1)
					min_valid_pow = min(min_valid_pow, i);
				if (find_pow(a, phi/i , n) == 1)
					min_valid_pow = min(min_valid_pow, phi/i);
			}
		}
		cout<< min_valid_pow<<endl;
	}
}