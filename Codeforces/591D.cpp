//AC
#include "bits/stdc++.h"
using namespace std;
long double x1,y1,x2,y2;
long double v,t;
long double vx,vy,wx,wy;
long double zero=0;
#define EPS 0.00000000000001
bool valid(long double T)
{
	long double xf=x1+(vx*(min(t,T)))+(wx*(max(zero,T-t)));
	long double yf=y1+(vy*(min(t,T)))+(wy*(max(zero,T-t)));
	long double d=hypot(xf-x2,yf-y2);
	long double reqT=d/v;
	return (reqT<=T) || abs(reqT-T)<=EPS;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>x1>>y1>>x2>>y2>>v>>t>>vx>>vy>>wx>>wy;
	long double l=0,r=1e12;
	long double mid=(l+r)/2;
	for(int it=0;it<500;it++)
	{
		mid=(l+r)/2;
		if(valid(mid))
		{
			r=mid;
		}
		else
		{
			l=mid;
		}
	}
	cout<<fixed<<setprecision(10)<<mid;
}