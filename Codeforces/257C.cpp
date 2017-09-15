//AC
//2:19 2:28
#include "bits/stdc++.h"
using namespace std;
#define PI (acos(0)*2)
#define EPS 0.00000000000001
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	long double ans;
	if(n==1)
	{
		ans=0;
	}
	else
	{
		std::vector<long double> ang(n);
		for(int i=0,x,y;i<n;i++)
		{
			cin>>x>>y;
			ang[i]=atan2(y,x)+PI;
		}
		sort(ang.begin(), ang.end());
		ang.push_back(ang[0]);
		long double minAng=ang[1]-ang[0];
		for(int i=1;i<n;i++)
		{
			long double diff=ang[i+1]-ang[i];
			if(diff<0)
				diff+=2*PI;
			minAng=max(minAng,diff);
		}
		ans=2*PI;
		ans-=minAng;
	}
	ans*=180;
	ans/=PI;
	if(abs(ans-360)<EPS)
	{
		ans=0;
	}
	cout<<fixed<<setprecision(10)<<ans;
}