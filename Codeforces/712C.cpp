//AC
#include "bits/stdc++.h"
using namespace std;
int n;
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int x,y;
	cin>>x>>y;
	int f=y,s=y,t=y;
	long long int ans=0;
	while(f<x || s<x || t<x)
	{
		ans++;
		if(f<=s && f<=t)
		{
			f=min(x,s+t-1);
		}
		else if(s<=f && s<=t)
		{
			s=min(x,f+t-1);
		}
		else if(t<=f && t<=s)
		{
			t=min(x,s+f-1);
		}
	}
	cout<<ans;
}