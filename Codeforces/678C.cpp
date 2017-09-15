//AC
#include "bits/stdc++.h"
using namespace std;
long long int gcd(long long int a,long long int b)
{
	if(a==0)
		return b;
	return gcd(b%a,a);
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	long long int n,a,b,p,q;
	// a=2,b=3;
	cin>>n>>a>>b>>p>>q;
	long long int lcm=(a*b)/gcd(a,b);
	long long int diva=n/a,divb=n/b,divboth=n/lcm;
	diva-=divboth;
	divb-=divboth;
	long long int ans=(p*diva)+(q*divb)+(max(p,q)*divboth);
	cout<<ans;
}