//AC
#include "bits/stdc++.h"
using namespace std;
long double modpow(long double v,int p)
{
	if(p==0)
		return 1;
	if(p==1)
		return v;
	long double ans=modpow(v,p/2);
	if(p%2==0)
		return ans*ans;
	return ans*ans*v;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	double n,m;
	cin>>m>>n;
	long double ans=0;
	for(int i=1;i<=m;i++)
	{
		ans+=i*(modpow(i/m,n)-modpow((i-1)/m,n));
	}	
	cout<<std::fixed<<setprecision(10)<<ans;
}