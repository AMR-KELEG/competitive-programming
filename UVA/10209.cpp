#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	double long a,x,y,z;
	while(cin>>a)
	{
		y=(a*a)*(1-(sqrt(3)/4.0)-(4*atan(1)/6));
		x=((a*a)*(1-atan(1)))-(2*y);
		z=(a*a)-(4*x)-(4*y);
		x=4*x;
		y=y*4;
		x=round(x*1000)/1000;
		y=round(y*1000)/1000;
		z=round(z*1000)/1000;
		cout<<std::fixed<<setprecision(3)<<z<<" "<<x<<" "<<y<<"\n";
	}	
}