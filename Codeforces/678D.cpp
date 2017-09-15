//AC
#include "bits/stdc++.h"
using namespace std;
#define mod 1000000007
long long int modpow(long long int po,long long int val)
{
	if(po==0)
		return 1;
	if(po==1)
		return val%mod;
	if(po%2)
	{
		// odd power
		long long int powdiv2=modpow(po/2,val)%mod;
		return ((((val%mod)*(powdiv2%mod))%mod)*(powdiv2%mod))%mod;
	}
	else
	{
		long long int powdiv2=modpow(po/2,val)%mod;
		return ((((1%mod)*(powdiv2%mod))%mod)*(powdiv2%mod))%mod;
	}
}

long long InverseEuler(long long int n)
{
    return modpow(mod-2,n);
}

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	long long int a,b,n,x;
	cin>>a>>b>>n>>x;
	long long int ans=0;
	if(a==1)
	{
		ans=(n%mod)*(b%mod);
		ans%=mod;
		ans+=x;
		ans%=mod;
	}
	else
	{
		long long int an=modpow(n,a)%mod;
		// cout<<an<<endl;
		ans=(an+mod-1)%mod;
		// cout<<ans<<endl;
		ans=(ans*(b%mod))%mod;
				// cout<<ans<<endl;

		ans=ans%mod;
		ans*=(InverseEuler(a-1)%mod);
		ans=ans%mod;
		// div by inverse of a-1

		ans+=((an%mod)*(x%mod))%mod;
		ans=ans%mod;

	}
	cout<<ans;
}