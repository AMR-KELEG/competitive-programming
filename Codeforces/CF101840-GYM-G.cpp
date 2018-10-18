// AC
#include "bits/stdc++.h"
using namespace std;
#define PI (2*acos(0))

/*
Generated Output:
Case 1: 4314.57552
Case 2: 257.52220
Case 3: 31096.23444
*/

int main()
{
	freopen("glorious.in","r",stdin);
	int T;
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		int k,r,n;
		scanf("%d %d %d",&k, &r, &n);
		long double ans = r*r;
		long double ang = PI/n;
		ans *= (n*tan(ang)-PI);
		long double c = 1/cos(ang);
		long double S = pow(c,2*k)-1;
		S/= c+1;
		S/= c-1;
		ans *= S;
		printf("Case %d: %0.5LF\n", t,ans);
	}
}
