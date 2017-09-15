//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int s,x1,x2,t1,t2,p,d;
	cin>>s>>x1>>x2>>t1>>t2>>p>>d;
	int ans=abs(x2-x1)*t2;
	//Try riding the tram
	if(x1<x2)
	{
		if(d==1)
		{
			if(p<=x1)
			{
				ans=min(ans,(x2-p)*t1);
			}
			else
			{
				ans=min(ans,(2*s+x2-p)*t1);	
			}
		}
		else
		{
			ans=min(ans,(x2+p)*t1);
		}
	}
	else
	{	
		if(d==1)
		{
			ans=min(ans,(2*s-x2-p)*t1);
		}
		else
		{	
			if(p>=x1)
			{
				ans=min(ans,(p-x2)*t1);
			}
			else
			{
				ans=min(ans,(2*s+p-x2)*t1);
			}
		}
	}
	cout<<ans;
}