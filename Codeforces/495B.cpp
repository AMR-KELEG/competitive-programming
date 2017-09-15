//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int a,b;
	cin>>a>>b;
	if(a==b)
		cout<<"infinity";
	else if(b>a)
		cout<<0;
	else
	{
		int x=a-b;
		int ans=0;
		int d;
		for(d=1;d*d<x;d++)
		{
			if(x%d==0)
			{
				if(d>=b+1 && d<=a)
					ans++;
				if(x/d>=b+1 && x/d<=a)
					ans++;
			}
		}
		if(d*d==x && d>=b+1 && d<=a)
			ans++;
		cout<<ans;
	}	
}