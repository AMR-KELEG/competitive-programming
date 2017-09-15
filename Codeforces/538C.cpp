//AC
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
	int dold,hold,dnew,hnew;
	cin>>dold>>hold;
	int maxh=hold+dold-1;
	hnew=hold;
	dnew=dold;
	for(int i=1;i<m;i++)
	{
		cin>>dnew>>hnew;
		int deld=abs(dnew-dold);
		int delh=abs(hnew-hold);
		if(delh==0)
		{
			maxh=max(maxh,hnew+(deld/2));
		}
		else if(delh>deld)
		{
			cout<<"IMPOSSIBLE";
			return 0;
		}
		else
		{
			maxh=max(maxh,max(hnew,hold)+((deld-delh)/2));	
		}
		hold=hnew;
		dold=dnew;
	}
	maxh=max(maxh,hnew+n-dnew);
	cout<<maxh;
}