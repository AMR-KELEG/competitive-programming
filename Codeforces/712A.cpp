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
	std::vector<int> a(n),b(n);
	for(int i=0;i<n;i++)
		cin>>b[i];
	for(int i=0;i<n-1;i++)
		a[i]=b[i]+b[i+1];
	a[n-1]=b[n-1];
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}

