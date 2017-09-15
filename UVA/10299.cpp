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
	cin>>n;
	while(n!=0)
	{
		if(n==1)
			printf("0\n");
		else
		{
			int ans=n;
			if(n%2==0)
			{
				while(n%2==0)
					n/=2;
				ans-=(ans/2);
			}
			for(int p=3;p*p<=n;p+=2)
			{
				if(n%p==0)
				{
					while(n%p==0)
						n/=p;
					ans-=(ans/p);
				}
			}
			if(n>1)
			{
				ans-=(ans/n);
			}
			printf("%d\n", ans);
		}			

		cin>>n;

	}	
}