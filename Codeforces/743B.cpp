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
	long long int k;
	cin>>n>>k;
	int ans=1;
	while(k%2==0)
	{
		ans++;
		k/=2;
	}
	cout<<ans;
}
