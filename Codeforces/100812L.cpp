//AC
#include "bits/stdc++.h"
#define INF 2000000007
using namespace std;

long long int powMod(int val,int p,int mod = INF)
{
	if (p==0)
		return 1;
	if (p==1)
		return val;
	long long int ans = powMod(val,p>>1,mod);
	ans = (ans*ans) %mod;
	if (p%2)
		ans *=val;
	return ans % mod;
}

long long int findPhi(int val)
{
	long long int ans = 1;
	int cur_prime = 2;
	int cur_count = 0;
	while (val %2 == 0)
	{
		val/=2;
		cur_count++;
	}
	if (cur_count)
	{
		ans = powMod(2,cur_count)-powMod(2,cur_count-1);
	}
	int max_val = val;
	for (int i = 3;val>1 && i*i<=max_val;i+=2)
	{
		if (val % i==0)
		{
			cur_count = 0;
			while(val%i ==0 )
			{
				val/=i;
				cur_count ++ ;
			}
			ans *= (powMod(i,cur_count)-powMod(i,cur_count-1));
		}
	}
	if (val>1)
		ans *= (val-1);
	return ans;
}

long long int neg_mod(int val,int mod)
{
	long long int l = 1;
	long long int r = INF;
	long long int mid = (l+r)>>1;
	while(l<r)
	{
		mid = (l+r)>>1;
		if ((mid* mod) + val <0)
		{
			l= mid+1;
		}
		else
		{
			r = mid;
		}
	}
	mid = (l+r)>>1;
	return val + mid* mod;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int n,m;
	cin>>n>>m;
	if (n==m)
		cout<<n;
	else if (n==1 || m==1)
	{
		cout<<2;
	}
	else
	{
		long long int ans = (n*m)/__gcd(n,m);
		// try solving the equations
		if (n<m)
			swap(n,m);
		long long int base_val = n%m;
		int phi_m = findPhi(m);
		if (__gcd(base_val, m) == 1)
		{
			// coprime
			// find Phi(m)
			// 
			long long int a_mod_m = powMod(base_val,phi_m-1,m);
			// cout<<"Found sol1 "<<a_mod_m * n<<endl;
			ans = min(ans,a_mod_m*n);
		}
		base_val = neg_mod(-n,m);
		// cout<<-n<<" % "<<m<<" = "<<base_val<<endl;
		if (__gcd(base_val, m) == 1)
		{
			// coprime
			// find Phi(m)
			// 
			long long int a_mod_m = powMod(base_val,phi_m-1,m);
			// cout<<"Found sol2 "<<1+(a_mod_m * n)<<endl;
			ans = min(ans,(a_mod_m*n)+1);
		}
		cout<<ans;
	}

}