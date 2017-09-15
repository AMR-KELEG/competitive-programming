#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	std::vector<int> a(n);	
	for(int i=0;i<n;i++)
		cin>>a[i];
	int t,r;
	for(int i=0;i<m;i++)
	{
		cin>>t>>r;
		if(t==1)
			sort(a.begin(),a.begin()+r);
		else
		{
			sort(a.begin(),a.begin()+r);
			reverse(a.begin(),a.begin()+r);
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
}