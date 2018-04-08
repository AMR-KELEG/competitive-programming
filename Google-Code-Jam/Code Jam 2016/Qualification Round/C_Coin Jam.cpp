#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("prime.txt","w",stdout);
	#endif
	std::vector<bool> prime(1000000005,1);
	for(int i=2;i<1000000000;i++)
	{
		if(prime[i])
		{
			cout<<i<<endl;
			for(int j=i+i;j<1000000000;j+=i)
			{
				prime[j]=0;
			}
		}
	}

}