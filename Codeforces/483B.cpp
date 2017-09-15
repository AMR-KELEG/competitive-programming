//AC
#include "bits/stdc++.h"
using namespace std;
long long int cnt1,cnt2,x,y;
long long int GCD,LCM;
long long int agcd(long long int a,long long int b)
{
	if(b==0)
		return a;
	return agcd(b,a%b);
}
bool valid(long long int v)
{
	long long int dx=v/x,dy=v/y,db=v/LCM;
	long long int rx=cnt1-(dy-db);
	long long int ry=cnt2-(dx-db);
	// cout<<dx<<" "<<dy<<" "<<db<<endl;
	// cout<<rx<<" "<<ry<<endl;
	// cout<<max(0,rx)+max(0,ry)<<endl;
	if(v-dx-dy+db>=max(0LL,rx)+max(0LL,ry))
		return 1;
	return 0;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>cnt1>>cnt2>>x>>y;
	GCD=agcd(x,y);
	LCM=(x*y)/GCD;
	long long int l=0,r=1000000000000000LL;
	long long int mid;
	for(long long int i=0;i<300;i++)
	{
		mid=(l+r)/2;
		// cout<<l<<" "<<r<<endl;
		if(valid(mid))
		{
			r=mid;
		}
		else
			l=mid+1;
	}
	cout<<mid;
}