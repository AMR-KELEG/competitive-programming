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
		int a,b;
		scanf("%d %d", &a, &b);
		if (a>=b)
		{
			printf("FunkyMonkeys\n");
		}
		else
		{
			printf("WeWillEatYou\n");
		}
	}	
}