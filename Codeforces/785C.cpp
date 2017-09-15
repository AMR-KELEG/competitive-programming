//AC
#include "bits/stdc++.h"
using namespace std;
void brute(long long int n,long long int m)
{
	long long int cur=n;
	long long int day=1;
	for(;cur>0;day++)
	{
		cur+=m;
		cur=min(cur,n);
		// cout<<"Before "<<cur<<" ";
		cur-=day;
		// cout<<day<<" "<<cur<<endl;
	}
	cout<<"Day: "<<day-1<<endl;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int n,m;
	cin>>n>>m;
	if(n<=m)
		cout<<n;
	else
	{
		// brute(n,m);
		long long int ans=m;
		long long int l=0,r=2000000000;
		while(l<r)
		{
			long long int mid=(l+r)/2;
			if(mid*(mid+1)<2*(n-m))
			{
				l=mid+1;
			}
			else
			{
				r=mid;
			}
		}
		ans+=floor((l+r)/2);
		cout<<ans;
	}	
}