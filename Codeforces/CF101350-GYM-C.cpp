// AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		int G = 0;
		long long int cost = 0;
		while(n--)
		{
			int v;
			scanf("%d", &v);
			cost += v;
			G = __gcd(G, v);
		}
		printf("%I64d %d\n", cost, G);
	}	
}