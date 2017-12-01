/* AC
  Editorial: https://lscct.com/challenge/2016solution.pdf
*/
#include "bits/stdc++.h"
#define EPS 1e-9
using namespace std;

long long int solve(long long int r)
{
	if (r<0)
		return 0;
	if (r==0)
		return 1;
	long long int ans =0;
	for (long long int y=1;y<=r;y++)
	{
		long double x = r*r;
		x -= y*y;
		x = sqrt(x);
		long long rounded_x = round(x);
		if (abs(x - rounded_x) < EPS)
		{
			ans += 1+rounded_x;
		}
		else
		{
			ans += 1+floor(x);
		}
	}
	return 4*ans +1;
}

long long int point_on_circum(long long int r)
{
	if (r<0)
		return 0;
	if (r==0)
		return 1;
	long long int ans =0;
	for (long long int y=1;y<=r;y++)
	{
		long double x = r*r;
		x -= y*y;
		x = sqrt(x);
		long long rounded_x = (long long int)(x);
		if (rounded_x*rounded_x + y*y == r*r)
		{
			ans++;
		}
	}
	return 4*ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int R,D;
	scanf("%d %d", &R, &D);
	printf("%lld\n", solve(R+D) - solve(R-D) + point_on_circum(R-D));	
}