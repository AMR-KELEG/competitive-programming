/*
	AC
	ORDINARY NIM GAME
*/
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	while(n)
	{
		long long int ans = 0;
		int no;
		while(n--)
		{
			cin>>no;
			ans ^= no;
		}
		if (ans)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}

		cin>>n;
	}	
}