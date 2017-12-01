// AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	long long int s;
	cin>>n>>s;
	std::vector<long long int> D(n,0);
	for (int i=0;i<n;i++)
		cin>>D[i];
	std::vector<long long int> K(n,0);
	long long int c =0;
	long long int last = s;
	for (int i=n-2;i>=0;i--)
	{
		K[i+1] = (D[i]-1-c)/D[i+1];
		c += K[i+1]*D[i+1];
		s/= (K[i+1]+1);
	}
	K[0] = s-1;
	for (int i=0;i<n;i++)
	{
		if (i)
			printf(" ");
		printf("%d", K[i]);
	}

}