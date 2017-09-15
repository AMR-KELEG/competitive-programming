#include "bits/stdc++.h"
#define MOD 1000000007
using namespace std;

unordered_map<int,int> inv_mp;
int modPow(int val,int p)
{
	if (p==0)
		return 1;
	if (p==1)
		return val;
	long long int ans = modPow(val,p>>1);
	ans *= ans;
	if (ans>=MOD)
		ans %=MOD;
	
	if (p%2)
	{
		ans *= val;
	}
	if (ans>=MOD)
		ans %=MOD;

	return ans;
}

int inv(int val)
{
	if (inv_mp.find(val)== inv_mp.end())
	{
		int inv_val = modPow(val,MOD-2);
		inv_mp[val] = inv_val;
	}
	return inv_mp[val];
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	long double last_ans = 1;

	while(t--)
	{
		int n;
		cin>>n;
		if (n==0)
		{
			cout<<1<<endl;
			continue;
		}
		long long int ans = 0;
		long long int num = 1;
		long long int den = 1;
		for (int i=1;i<=n;i++)
		{
			num = (num * (n+1-i));
			if (num>=MOD)
				num %=MOD;
			den = (den * i);
			if (den>=MOD)
				den %=MOD;
			long long int inv_den = inv(den);
			long long int cur_val = (num * inv_den) % MOD;
			cur_val = (cur_val*cur_val)%MOD;
			cur_val = (cur_val*i)%MOD;
			ans = (ans+cur_val);
			if (ans>=MOD)
				ans %=MOD;
		}
		cout<<ans<<endl;
	}	
}