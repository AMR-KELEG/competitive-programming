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
	int a;
	int onein,nin;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a==1)
			onein=i;
		else if(a==n)
			nin=i;
	}
	int ans=max(n-1-nin,max(n-1-onein,max(nin,onein)));
	cout<<ans;
}