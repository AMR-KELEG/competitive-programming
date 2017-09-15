#include "bits/stdc++.h"
using namespace std;
int par[300001]={};
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int k;
	cin>>k;
	int ans=3;
	int count = 1;
	int curCount=2;
	while(k--)
	{
		count--;
		if(count==0)
			count = curCount++;
		if(k==1)
			break;
		ans+=2;
	}
	cout<<ans;
}