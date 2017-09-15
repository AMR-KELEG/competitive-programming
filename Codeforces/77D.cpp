//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int a,b;
		int ta,tb;
		cin>>ta>>tb;
		a=ta;b=tb;
		long double ans=0;
		if(b==0)
		{
			ans=1;
		}
		else if(a==0)
		{
			ans=0.5;
		}
		else if(4*b>=a)
		{
			ans=((a*b)+(0.125*a*a))/(2*a*b);
		}
		else
		{
			ans=(a-b);
			ans/=a;
		}
		cout<<fixed<<setprecision(9)<<ans<<"\n";
	}
}