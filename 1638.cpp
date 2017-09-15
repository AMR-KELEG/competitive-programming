//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int b,c,s,e;
	cin>>b>>c>>s>>e;
	int ans=0;
	if(s==e)
	{
		ans=b;
	}
	else if(s<e)
	{
		while(s<e)
		{
			ans+=2*c;
			s++;
			if(s==e)
				break;
			else
				ans+=b;
		}
	}
	else
	{
		ans=b;
		while(s>e)
		{
			s--;
			ans+=(2*c)+b;
			if(s==e)
				break;
		}
	}
	cout<<ans;
}