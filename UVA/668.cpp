//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int m;
	cin>>m;
	int ans[200];
	// cout<<500<<endl;
	// for(int i=5;i<505;i++)
	// 	cout<<i<<endl;
	while(m--)
	{
		int n;
		int in=0;
		cin>>n;
		int total=0;
		while(total+(in+2)<=n)
		{
			ans[in]=in+2;
			total+=(in+2);
			in++;
		}
		for(int i=in-1;n-total>0;i--)
		{
			ans[i]++;
			total++;
			if(i==0)
				i=in;
		}
		// int tot=0;
		for(int i=0;i<in;i++)
		{
			// tot+=ans[i];
			if(i==in-1)
				printf("%d", ans[i]);
			else
				printf("%d ", ans[i]);
		}
		printf("\n");
		if(m)
			printf("\n");
	}	
}