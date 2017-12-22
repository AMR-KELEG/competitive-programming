/* AC O(max(a,b)) -> O(10^6)
-The values will cycle at LCM(a,b)
- iterate on ranges : R = LCA(a,b) - 1 - n*a and L = LCA(a,b) - (n+1)*a
until L is -ve
- Find the timestamps that belong to each of a,b for each range 
*/
#include "bits/stdc++.h"
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int a,b;
	string sa="Dasha", sb="Masha";
	scanf("%lld %lld",&a, &b);
	if (a<b)
	{
		swap(a, b);
		swap(sa, sb);
	}
	long long int R = a * b / __gcd(a, b);
	long long int L = R -a;
	long long int ca=0,cb=0;
	R--;
	while(L>=0)
	{
		long long int c = floor(1.0*(R)/b);
		long long int mid = c*b;
		if (L+1<=mid)
		{
			cb += (mid+1-(L+1));
		}
		if (mid+1<=R)
		{
			ca += (R+1-(mid+1));
		}
		ca++;
		L-=a;
		R-=a;
	}
	if (ca==cb)
		printf("Equal");
	else if (ca>cb)
		printf("%s\n", sa.c_str());
	else
		printf("%s\n", sb.c_str());
}