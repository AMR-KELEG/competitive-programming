// AC
/*

https://www.quora.com/What-is-the-intuition-behind-this-SPOJ-com-Problem-HUBULLU

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
		int n,p;
		cin>>n>>p;
		if (!p)
			printf("Airborne wins.\n");
		else
			printf("Pagfloyd wins.\n");
	}	
}