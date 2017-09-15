//AC
#include "bits/stdc++.h"
#define MOD 1000000007
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vector<int> x(n);
	for(int i=0;i<n;i++)	cin>>x[i];
	sort(x.begin(), x.end());
	vector<long long int> twoPower(n);
	twoPower[0]=1;
	for(int p=1;p<n;p++)
		twoPower[p]=(2*twoPower[p-1])%MOD;
	long long int ans=0;
	for(int i=0;i<n;i++)
	{
		long long int add = (x[i]*twoPower[i])%MOD;
		ans=(ans+add)%MOD;
		long long int sub = (x[i]*twoPower[n-i-1])%MOD;
		ans=(ans-sub);
		while(ans<0)
			ans+=MOD;
	}
	cout<<ans;
}