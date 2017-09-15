//AC after 3 submissions -- errors in power by squaring / mod with negative value and formula
#include "bits/stdc++.h"
using namespace std;
# define N 1000000009
long long int modpow(long long int r,long long int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return r%N;
	long long int ans=modpow(r,n/2)%N;
	if(n%2==0)
	{
		return (ans*ans)%N;
	}
	return (((ans*ans)%N)*r)%N;
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	long long int n,m,k;
	cin>>n>>m>>k;
	long long int part=n/k;
	long long int suc=part-n+m;
	// cout<<part<<endl;
	// cout<<suc<<endl;
	long long int ans= m- ((k*max(0LL,suc))%N);
	// cout<<ans<<endl;
	ans=ans%N;
	if(suc>0)
	{
		// cout<<modpow(2,suc+1)<<endl;
		ans+=((k%N)*(( (modpow(2,suc+1)%N) +N-2)%N))%N;
		ans%=N;	
	}
	cout<<ans%N;

}