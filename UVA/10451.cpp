//AC
#include "bits/stdc++.h"
#define PI (2*acos(0))
using namespace std;


int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	long double pol_area;
	cin>>n;
	int te = 1;
	while(n>2)
	{
		cin>>pol_area;
		long double th = (PI / n);
		long double out_r = (pol_area)/ (n);
		out_r /= cos(th);
		out_r /= sin(th);
		out_r = sqrt(out_r);
		long double off_area,spec_area;
		spec_area = (PI * out_r * out_r) - pol_area;
		long double in_r = out_r * cos(th);
		off_area = pol_area - (PI * in_r * in_r) ;
		
		printf("Case %d: %0.5LF %0.5LF\n", te,spec_area, off_area);
		te++;
		cin>>n;
	}	
}