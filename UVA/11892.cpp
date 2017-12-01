/* AC
- Player 1 controls the game unless all the piles has only 1 stone.
*/
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
		bool all_one = 1;
		for (int i=0,v;i<n;i++)
		{
			scanf("%d", &v);
			if (v>1)
				all_one = 0;
		}
		if (all_one)
		{
			if (n%2)
				printf("poopi\n");
			else
				printf("piloop\n");
		}
		else
		{
			printf("poopi\n");
		}
	}	
}