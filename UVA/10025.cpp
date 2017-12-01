// AC
#include "bits/stdc++.h"
using namespace std;
#define EPS 1e-9

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
		long long int k;
		cin>>k;
		k = abs(k);
		
		long double n = -1 + sqrt(1+8*k);
		n*=0.5;
		if (abs(round(n)-n)<EPS)
		{
			n = round(n);
		}
		else
		{
			n = ceil(n);
		}
		long long int ans = max(1LL,(long long int)n);
		while (((ans*(ans+1))/2 - k)%2)
			ans++;
		printf("%d\n", (int)ans);
		if (T)
			printf("\n");
	}	
}