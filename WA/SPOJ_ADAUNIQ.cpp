#include "bits/stdc++.h"
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int N,Q;
	scanf("%d %d", &N, &Q);
	std::vector<int> a(N);
	for (int i=0,v;i<N;i++)
	{
		scanf("%d",&v);
		a[i] = v;
	}
	// For all ranges
	// Make range = N^(2/3)
	// For each query -> 
	while (Q--)
	{
		int t;
		scanf("%d", &t);
		if (t==1)
		{
			int indx, val;
			scanf("%d %d", &indx, &val);
		}
		else
		{
			int l,r;
			scanf("%d %d", &l, &r);
			
		}
	}
}