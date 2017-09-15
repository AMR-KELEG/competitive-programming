//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> counter(5000005,0);
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int a,b,t,no;
	cin>>t;
	for(int i=2;i<=5000000;i++)
	{
		if(counter[i]==0)
		{
			for(int j=1;i*j<=5000000;j++)
			{
				no=i*j;
				while((no)%i==0)
				{
					counter[i*j]++;
					no/=i;
				}
			}
		}
	}
	for(int i=2;i<=5000000;i++)
	{
		counter[i]+=counter[i-1];
	}
	cout<<counter[5000000]<<endl;
	for(int i=0;i<t;i++)
	{
		cin>>a>>b;
		printf("%d\n", counter[a]-counter[b]);
	}
}