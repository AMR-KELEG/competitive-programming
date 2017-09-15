//AC
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
	int m=0,l;
	long long int s=0;
	for(int i=0;i<n;i++)
	{
		cin>>l;
		s+=l;
		m=max(m,l);
	}
	// s-m should be > m
	// m-(s-m)
	long long int ans=(2*m+1)-s;
	cout<<ans;
}