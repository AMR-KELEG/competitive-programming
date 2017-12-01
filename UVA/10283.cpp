// AC
#include "bits/stdc++.h"
using namespace std;
#define PI (2*acos(0))

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int iR,iN;
	while(cin>>iR>>iN)
	{
		long double R=iR,N=iN;
		if (iN==1)
		{
			long double zero = 0;
			printf("%0.10LF %0.10LF %0.10LF\n", R,zero, zero);
			continue;
		}
		long double th = PI /N;
		long double r = R * (sin(th) / (1+sin(th)));
		long double area_kiss = ((cos(th) * r* (R-r)) - ((PI*0.5 - th) * r*r)) * N;
		long double area_out = PI * R * R - area_kiss - N * PI * r * r;
		printf("%0.10LF %0.10LF %0.10LF\n", r, area_kiss, area_out);
	}
}