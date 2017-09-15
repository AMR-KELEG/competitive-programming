//AC
#include "bits/stdc++.h"
using namespace std;
int n;
std::vector<int> v;
int check(int s,int step)
{
	int ans=0;
	for(int i=s;i<n;i+=step)
	{
		ans+=v[i];
	}
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	v=std::vector<int> (n);
	int t;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	int ans=-1000*20001LL;
	for(int di=1;di*di<=n;di++)
	{
		if(n%di==0)
		{
			//di is a divisor n/di is a divisor
			if(n/di>=3)
			{
				//search for start
				for(int start=0;start<di;start++)
				{
					ans=max(ans,check(start,di));	
					// cout<<start<<" "<<di<<" "<<ans<<endl;
				}
			}
			if(di>=3)
			{
				//search for start
				//search for start
				for(int start=0;start<n/di;start++)
				{
					ans=max(ans,check(start,n/di));
					// cout<<start<<" "<<di<<" "<<ans<<endl;
				}
			}
		}
	}
	cout<<ans;
	return 0;	
}