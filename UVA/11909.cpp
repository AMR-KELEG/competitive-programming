//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long double l,w,h,th;
	while(cin>>l>>w>>h>>th)
	{
		th*=acos(0)/90;
		long double ans;
		if(l*tan(th)<=h)
		{
			ans=(l*h)-(0.5*l*l*tan(th));
		}
		else
		{
			ans=(h*h)/(2*tan(th));
		}
		// cout<<l*h<<" "<<(0.5*l*l*tan(th))<<endl;
		ans*=w;
		cout<<std::fixed<<setprecision(3)<<ans<<" mL\n";
	}	
}