//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	for(int te=1;te<=t;te++)
	{
		printf("Case %d: ",te);
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(c%__gcd(a,b)==0)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");	
		}
	}	
}