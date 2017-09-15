//AC
#include "bits/stdc++.h"
using namespace std;
int axor(int a)
{
	if(a%4==0)
		return a;
	if(a%4==1)
		return 1;
	if(a%4==2)
		return a+1;
	return 0;
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int n;
	int p;
	long long int ans=0,oldval=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p;
		ans=ans^p;
		oldval^=(i-1);
		if(int(n/i)%2)
		{
			//odd 
			ans^=oldval;
		}
		ans^=axor(n%i);
	}
	cout<<ans;
}
