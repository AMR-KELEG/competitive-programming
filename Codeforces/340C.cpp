//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	std::vector<int> a(n+1,0);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a.begin(), a.end());
	std::vector<long long int > cs(n+1);
	cs[0]=0;
	for(int i=1;i<=n;i++)
		cs[i]=a[i]+cs[i-1];
	long long int ans=0;
	for(long long int i=n;i>=1;i--)
	{
		ans+=a[i];
		ans+=2*a[i]*(i-1);
		ans-=2*cs[i-1];
	}
	int GCD=__gcd((long long)n,ans);
	n/=GCD;
	ans/=GCD;
	cout<<ans<<" "<<n;

}