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
		std::vector<int> h(n);
		for (int i=0, v;i<n;i++)
		{
			scanf("%d", &v);
			h[i] = v;
		}
		sort(h.begin(), h.end());
		bool all_even_diff = 1;
		for (int i=1;i<n;i++)
		{
			if ((h[i]-h[i-1])%2)
			{
				all_even_diff = 0;
				break;
			}
		}
		if (all_even_diff)
			printf("yes\n");
		else
			printf("no\n");
	}
}