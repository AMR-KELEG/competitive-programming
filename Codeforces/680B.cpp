#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int n,a;
	cin>>n>>a;
	std::vector<int> v(n);
	a--;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	int count=0;
	int lp=a,rp=a;
	for(;lp>=0 && rp<n;lp--, rp++)
	{
		if(v[lp]==v[rp] && v[lp]==1)
			count+=2;
		if(lp==rp && v[lp]==1)
			count--;
	}
	for(int p=lp;p>=0;p--)
	{
		if(v[p]==1)
			count++;
	}
	for(int p=rp;p<n;p++)
	{
		if(v[p]==1)
			count++;
	}
	cout<<count;
}
