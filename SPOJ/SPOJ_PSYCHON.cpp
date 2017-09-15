//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	int n;
	while(t--)
	{
		int e=0,o=0;
		cin>>n;
		int cur=0;
		int lim=sqrt(n);
		if(n%2==0 && n!=0)
		{
			while(n%2==0)
			{
				cur++;
				n/=2;
			}
			if(cur%2)
				o++;
			else
				e++;
			cur=0;
		}
		for(int i=3;n>1 && i<=lim;i+=2)
		{
			if(n%i==0)
			{
				while(n%i==0)
				{
					cur++;
					n/=i;
				}
				if(cur%2)
					o++;
				else
					e++;
				cur=0;
			}	
		}
		if(n>1)
		{
			o++;
		}
		if(e>o)
			printf("Psycho Number\n");
		else
			printf("Ordinary Number\n");
	}	
}