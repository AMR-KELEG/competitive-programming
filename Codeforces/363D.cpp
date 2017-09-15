//AC
#include "bits/stdc++.h"
using namespace std;
int n,m,a;
std::vector<int> money;
std::vector<int> bike;
bool valid(int s)
{
	if(s>m)
		return 0;
	int rem=a;
	for(int bi=s-1,si=n-1;si>=0 && bi>=0;si--,bi--)
	{
		if(money[si]>=bike[bi])
			continue;
		else if(bike[bi]-money[si]<=rem)
		{
			rem-=bike[bi]-money[si];
		}
		else
			return 0;
	}
	return 1;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>m>>a;
	money=std::vector<int> (n);
	bike=std::vector<int> (m);
	for(int i=0;i<n;i++)
		cin>>money[i];
	for(int i=0;i<m;i++)
		cin>>bike[i];	
	sort(bike.begin(), bike.end());
	sort(money.begin(), money.end());
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(valid(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	int s=(l+r+1)>>1;
	long long int totalspent=0;
	for(int bi=s-1,si=n-1;si>=0 && bi>=0;si--,bi--)
	{
		if(money[si]>=bike[bi])
		{
			totalspent+=bike[bi];
		}
		else
		{
			totalspent+=money[si];
			a-=bike[bi]-money[si];
		}
	}
	totalspent=max((long long)0,totalspent-a);
	cout<<s<<" "<<totalspent;
}