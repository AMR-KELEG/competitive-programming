/* AC
MISERE NIM GAME
ALL <2 -> NIM_sum = !NIM_sum
ELSE -> Ordingary NIM Game
*/
#include "bits/stdc++.h"
using namespace std;

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
		int n;
		cin>>n;
		int ans = 0;
		bool all_less_than_two = 1;
		while(n--)
		{
			int no;
			cin>>no;
			all_less_than_two = all_less_than_two && (no<2);
			ans ^= no;
		}
		if (all_less_than_two)
		{
			if (ans)
				printf("Brother\n");
			else
				printf("John\n");
		}
		else
		{
			if (ans==0)
				printf("Brother\n");
			else
				printf("John\n");	
		}
	}	
}