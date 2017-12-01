#include "bits/stdc++.h"
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m,k;
	scanf("%d %d %d", &n,&m,&k);	
	int min_steps = 100000000;
	for (int i=0,x,y;i<k;i++)
	{
		scanf("%d %d",&x,&y);
		min_steps = min(min_steps, min(x-1,n-x));
		min_steps = min(min_steps, min(y-1,m-y));
	}
	if (min_steps<5)
		cout<<"YES";
	else
		cout<<"NO";
}