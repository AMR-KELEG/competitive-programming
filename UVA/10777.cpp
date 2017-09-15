//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n;
		cin>>n;
		int x;long double p;
		long double sigma=0;
		long double den=1;
		while(n--)
		{
			cin>>x>>p;
			if(x<0)
			{
				den-=p;
			}
			sigma+=(p*abs(x));
		}
		if(abs(den)<0.0000000000001)
		{
			cout<<"Case "<<t<<": "<<"God! Save me\n";
		}
		else
		{
			cout<<fixed<<setprecision(2)<<"Case "<<t<<": "<<sigma/den<<"\n";
		}
	}
}