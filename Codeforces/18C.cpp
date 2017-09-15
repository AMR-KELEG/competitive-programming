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
	std::vector<int> a(n);
	long long int totalsum=0,csum=0,no=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		totalsum+=a[i];
	}	
	for(int i=0;i<n-1;i++)
	{
		csum+=a[i];
		if(2*csum==totalsum)
			no++;
	}
	cout<<no;
}