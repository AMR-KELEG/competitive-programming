#include "bits/stdc++.h"
using namespace std;
struct point 
{
	long double x,y;
};

long double eucdis(point & p1,point & p2)
{
	long double dx=p1.x-p2.x;
	long double dy=p1.y-p2.y;
	long double ans=(dx*dx)+(dy*dy);
	ans=sqrt(ans);
	return ans;
}

long double mindis(point & p,point & p1,point & p2)
{
	long double v1=eucdis(p1,p2);
	long double v2=eucdis(p,p1);
	//find v1 X v2
	long double cro=((p1.x-p2.x)*(p1.y-p.y)) - ((p1.y-p2.y)*(p1.x-p.x));
	long double ans=abs(cro)/v1;
	ans=(v2*v2)-(ans*ans);
	ans=sqrt(ans);
	ans=min(ans,v2);
	v2=eucdis(p,p2);
	ans=min(ans,v2);
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	
	int n;
	while(!cin.eof())
	{
		point p;
		// long double x,y;
		// cin>>x>>y;
		cin>>p.x>>p.y;
		// cout<<x<<" "<<y<<endl;
		cin>>n;
		point p1,p2;
		long double ans=1<<30;
		cin>>p1.x>>p1.y;
		for(int i=0;i<n;i++)
		{
			cin>>p2.x>>p2.y;
			ans=min(ans,mindis(p,p1,p2));
			p1=p2;
		}
		if(ans!=(1<<30))
			cout<<std::fixed<<setprecision(10)<<ans<<endl;
		else
			cout<<std::fixed<<setprecision(10)<<0<<endl;
		// p=point();
	}	
}