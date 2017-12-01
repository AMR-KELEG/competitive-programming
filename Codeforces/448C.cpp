/* AC

*/
#include "bits/stdc++.h"
using namespace std;
std::vector<int> h;
long long int solve(int l, int r)
{
	if (l>r)
		return 0;
	int n = r-l+1;
	int min_val = h[l];
	for (int i=l+1;i<=r;i++)
	{
		min_val = min(min_val, h[i]);
	} 
	if (n<=min_val)
		return n;
	int range_start = l;
	long long int ans = min_val;
	if (ans>n)
		return n;
	for (int i=l;i<=r;i++)
	{
		h[i] -= min_val;
		if (h[i] == 0)
		{
			if (i - range_start)
			{
				ans += solve(range_start, i-1);
			}
			range_start = i+1;
		}
	}
	if (range_start<=r)
		ans += solve(range_start,r);
	return min(ans, (long long int)n);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	scanf("%d", &n);
	h = std::vector<int> (n);
	for (int i=0,t;i<n;i++)
	{
		scanf("%d", &t);
		h[i] = t;
	}
	printf("%d\n", solve(0,n-1));
}