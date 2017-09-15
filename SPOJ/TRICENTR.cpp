#include "bits/stdc++.h"

#define Point complex<double> 
#define X real()
#define Y imag()
#define dis(a,b) (abs((a)-(b)))
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while(T--)
	{
		long double a, d1,d2,d3;
		cin>>a>>d1>>d2>>d3;
		long double xm = ((15*a*a* 0.25) + (d1*d1) - (4*d2*d2) )/ (3*a);
		long double ym = (d1*d1)- (xm*xm) + (a*xm) - (0.25*a*a);
		if (ym < 0)
		{
			swap(d2,d3);
			xm = ((15*a*a/4.0) + (d1*d1) - 4*d2*d2 )/ (3*a);
			ym = (d1*d1)- (xm*xm) + (a*xm) - (0.25*a*a);
		}
		ym = sqrt(abs(ym));
		Point M (xm,ym);
		Point A(0,0);
		Point B(a,0);
		Point C = (M + M + M - B);
		Point M3 = 0.5 * C;
		cout<<"X: "<<xm<<" Y: "<<ym<<endl;
		cout<<d3<<" " << dis(M,M3)<<endl;
	}
}