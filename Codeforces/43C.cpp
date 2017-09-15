//AC
#include "bits/stdc++.h"
using namespace std;
int findsum(int i)
{
	int ans=0;
	while(i>0)
	{
		ans+=i%10;
		i/=10;
	}
	return ans%3;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	int a[3]={};
	int no;
	while(n--)
	{
		cin>>no;
		a[findsum(no)]++;
	}	
	int ans=a[0]/2;
	ans+=min(a[1],a[2]);
	cout<<ans;
}