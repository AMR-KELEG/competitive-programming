/* AC

*/
#include "bits/stdc++.h"
using namespace std;

int n,p;
int find_valid(int lim)
{
	if (lim%p == 0)
		return lim/p;
	return floor(double(lim)/p);	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	scanf("%d %d", &n, &p);
	std::vector<int> len(n), f(n);
	for (int i=0, l,r; i<n; i++)
	{
		scanf("%d %d", &l, &r);
		f[i] = find_valid(r) - find_valid(l-1);
		len[i] = r + 1 - l;
	}	
	long double ans = 0;
	for (int i=0; i<n; i++)
	{
		int i2 = (i+1)%n;
		long double p1 = (1.0*f[i])/len[i];
		long double p2 = (1.0*f[i2])/len[i2];
		long double p = p1 + p2 - (p1*p2);
		ans += p;
	}
	ans *=2000;
	printf("%LF", ans);

}