//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif

	int a[3];
	// for(int i=0;i<3;i++)
	// 	cin>>a[i];
	for(int f=1;f<=100;f++)
	{
		for(int s=f+1;s<=100;s++)
		{
			for(int t=s+1;t<=100;t++)
			{
				a[0]=f;
				a[1]=s;
				a[2]=t;
				int mindis=1000;
				for(int s=1;s<=100;s++)
				{
					int curdis=0;
					for(int i=0;i<3;i++)
						curdis+=abs(a[i]-s);
					mindis=min(mindis,curdis);
				}
				// assert(0);
				assert(t-f==mindis);
			}
		}
	}
	// assert(mindis,mindis2);
}