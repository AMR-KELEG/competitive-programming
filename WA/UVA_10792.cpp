// WA??
#include "bits/stdc++.h"
using namespace std;
#define EPS 1e-15

int main()
{
	// std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		long double r,d,h1;
		cin>>r>>d>>h1;
		long double x1 = sqrt (h1*(2*r - h1));
		long double L = 2 * sqrt((r*r)-((r-d)*(r-d)));
		long double A = (r-h1)/x1;
		long double B = ((x1*x1) + (h1*h1) - (L*L))/(2*x1);
		long double a = A*A + 1;
		long double b = A*B - 2*r;
		long double c = B*B;
		long double det = b*b - 4*a*c;
		cout<<"("<<x1<<", "<<h1<<") "<<sqrt(x1*x1 + (h1-r)*(h1-r))<<" ";
		cout<<"Length: "<<L<<" ";
		cout<<det<<" ";
		if (det<0)
			det = -sqrt(-det);
		else
			det = sqrt(det);
		long double h2 = (-b + det) / (2*a);
		printf("Case %d: %0.4LF\n", t,h2);
		continue;
		// long double x1 = - sqrt(h1 * (2*r-h1));
		// long double h2_l=0,h2_r = r;
		// for (int it = 0;it <300;it++)
		// {
		// 	long double h2_mid = (h2_l + h2_r) * 0.5;
		// 	long double x2_mid = sqrt(h2_mid * (2*r-h2_mid));
		// 	long double res_mid = (x1+x2_mid) * (x2_mid-x1) + (h1+h2_mid- 2*r) * (h2_mid-h1);
		// 	if (res_mid<0)
		// 	{
		// 		h2_l = h2_mid;
		// 	}
		// 	else
		// 	{
		// 		h2_r = h2_mid;		
		// 	}
		// 	continue;
		// 	long double h2_o=h2_l + (h2_r-h2_l)/3,h2_t=h2_l + 2*(h2_r-h2_l)/3;
		// 	long double x2_o = sqrt(h2_o * (2*r-h2_o));
		// 	long double x2_t = sqrt(h2_t * (2*r-h2_t));
			
		// 	long double res_o = (x1+x2_o) * (x2_o-x1) + (h1+h2_o- 2*r) * (h2_o-h1);
		// 	long double res_t = (x1+x2_t) * (x2_t-x1) + (h1+h2_t- 2*r) * (h2_t-h1);
		// 	cout<<res_o<<" "<<res_t<<endl;
		// 	if (res_o < res_t)
		// 	{
		// 		h2_r = res_t;
		// 	}
		// 	else
		// 	{
		// 		h2_l = res_o;
		// 	}
		// }
		// cout<<h2_l<<" "<<h2_r<<endl;
		// h2 = (h2_l + h2_r) * 0.5;
	}	
}