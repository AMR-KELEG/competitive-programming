#include "bits/stdc++.h"
using namespace std;
int main()
{
	long long int prime=-1;
	long long int n,one=1;
	cin>>n;
	bool found_prime=0;

	for(int i=n-2;!found_prime && i>1;i--)
	{
		found_prime=1;
		prime=i;
		for(int j=2;j<=(i/2);j++)
		{
			if(i%j==0)
			{
				found_prime=0;
				break;
			}
		}
	}
	if(n==2)cout<<2;
	else if(n==4)cout<<12;
	else if(n==6)cout<<60;
	else if(n%2==0)
	{
		cout<<(n-1)*(n-2)*(n-3);
	}
	else
	{
		cout<<n*max(n-1,one)*max(n-2,one);
	}
	return 0;
}