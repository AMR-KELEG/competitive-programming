//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int l,r,x,y,k;
	cin>>l>>r>>x>>y>>k;
	for(int i=x;i<=y;i++)
	{
		long long int val = k*i;
		if(val>=l && val<=r)
		{
			cout<<"YES";
			return 0;
		}
	}	
	cout<<"NO";
}