/* AC
	
*/
#include "bits/stdc++.h"
#define MOD 1000000007LL
using namespace std; 
long long mod_pow(int val,long long p, long long mod)
{
	if (p==0)
		return 1;
	if (p==1)
		return val % mod;
	long long int ans = mod_pow(val,p >> 1,mod);
	ans = (ans*ans) % mod;
	if (p%2)
		ans = (ans*val) % mod;
	return ans;
}

long long int inv(int val)
{
	return mod_pow(val, MOD-2,MOD);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	long long int N;
	while(T--)
	{
		cin>>N;
		long long int must_div = 1;
		std::vector<long long int> zeros;
		for (long long int i=0;i<6;i++)
		{
			char v;
			cin>>v;
			v-='0';
			if (v==1)
			{
				long long int gcd = __gcd(i+1, must_div);
				must_div *= i+1;
				must_div /= gcd;
			}
			else if (v==0)
				zeros.push_back(i+1);
		}
		long long int base = mod_pow(10,N,MOD) -1;
		while (base<0)
			base += MOD;
		long long int ans = 0;
		long long int div_base = base;
		long long int rem = mod_pow(10,N,must_div) - 1;
		while(rem<0)
			rem += must_div;
		rem %= MOD;
		div_base -= rem;
		while (div_base<0)
			div_base += MOD;
		div_base %= MOD;
		ans = ( 1 + div_base * inv(must_div)) % MOD;
		for (int m=1;m< (1<<zeros.size());m++)
		{
			long long int mul = must_div;
			int co = 0;
			for (int i=0;i<zeros.size();i++)
			{
				if ((m>>i) & (1LL))
				{
					co ++;
					long long int gcd = __gcd(mul,zeros[i]);
					mul *= zeros[i];
					mul /= gcd;
				}
			}
			long long div_base = base;
			long long int rem = mod_pow(10,N,mul) - 1;
			// cout<<rem<<endl;
			while(rem<0)
				rem += mul;
			rem %= MOD;
			div_base -= rem;
			while (div_base<0)
				div_base += MOD;
			div_base %= MOD;
			if (co%2)
			{
				ans -= (1 + div_base * inv(mul)) % MOD;
			}
			else
			{
				ans += (1 + div_base * inv(mul)) % MOD;	
			}
			while (ans<0)
				ans += MOD;
			ans %= MOD;
		}
		cout<<ans<<endl;
	}	
}