//AC
#include "bits/stdc++.h"
using namespace std;
long long int gcd(long long int l1,long long int l2)
{
	if(l2==0)
		return l1;
	return gcd(l2,l1%l2);
}

long long int lcm(long long int l1,long long int l2)
{
	return (l1*l2)/gcd(l1,l2);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int n;
	cin>>n;
	long long int curlevel=1;
	long long int n0=2,n1;
	while(curlevel!=n+1)
	{
		n1=lcm(curlevel,curlevel+1);
			
		long double ans=n1;
		ans/=curlevel;
		
		ans=ans*n1;
		ans-=(((long double)n0)/curlevel);
		ans=round(ans);
		cout<<(long long int)ans<<endl;
		n0=n1;
		curlevel++;
	}

}