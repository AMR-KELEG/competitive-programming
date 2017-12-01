/* AC
   Greedy (AND then OR)
*/
#include "bits/stdc++.h"
using namespace std;
unsigned long long arr[20001];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		for (int i=0;i<a+b+1;i++)
		{
			unsigned long long no;
			scanf("%llu", &no);
			arr[i] = no;
		}
		unsigned long long ans = arr[0];
		int i=1;
		int lim = a+b+1;
		for (;i<lim && a;i++,a--)
		{
			ans = ans & arr[i];
		}
		for (;i<lim;i++)
		{
			ans = ans | arr[i];
		}
		printf("%llu\n", ans);
	}	
}