//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long double r,n;
	// r r and angle = 360/n
	// 0.5 * r * H * sin (180/n)
	// H = r cos (180/n)
	while(cin>>r>>n)
	{
		long double angle = (2*acos(0))/n;
		cout<<fixed<<setprecision(3)<<n*r*(r*cos(angle))*sin(angle)<<endl;
	} 	
}