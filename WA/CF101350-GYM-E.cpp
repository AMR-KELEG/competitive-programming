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
		if (n==2)
			printf("second\n");
		else
			printf("first\n");
	}
}