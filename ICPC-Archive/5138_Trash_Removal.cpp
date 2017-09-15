#include "bits/stdc++.h"
using namespace std;
int n;
long double mindis=1000000000;
std::vector<long double> x,y,rad,th;
void findmin(long double lth,long double rth)
{
	long double midth=0.5*(lth+rth);
	long double minx=1000000000,maxx=-1000000000;
	for(int i=0;i<n;i++)
	{
		long double v=rad[i]*cos((th[i]+midth));
		minx=min(minx,v);
		maxx=max(maxx,v);
	/*
	*/
	}
	if((mindis - maxx-minx)>0.00001)
	{
		mindis=maxx-minx;
		findmin(midth,rth);
		findmin(lth,midth);
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		
	#endif
	cin>>n;
	int casen=1;
	while(n!=0)
	{
		mindis=1000000000;
		long double minx=1000000000,maxx=-1000000000;
		x=std::vector<long double> (n);
		y=std::vector<long double> (n);
		rad=std::vector<long double> (n);
		th=std::vector<long double> (n);
		for(int i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
			rad[i]=sqrt((x[i]*x[i])+(y[i]*y[i]));
			th[i]=atan2(y[i],x[i]);
			minx=min(minx,x[i]);
			maxx=max(maxx,x[i]);
			//cout<<rad[i]<<" "<<th[i]<<endl;
		}
		mindis=min(mindis,maxx-minx);
		//findmin(0,2*atan2(-1,0));
		
		long double leftth=0,rightth=8,midth;
		for(long double the=0;the<=atan2(0,-1);the+=atan2(0,-1)/16)
		{
			minx=1000000000,maxx=-1000000000;
			for(int i=0;i<n;i++)
			{
				x[i]=rad[i]*cos(th[i]+the);
				minx=min(minx,x[i]);
				maxx=max(maxx,x[i]);
			}
			cout<<the<<" "<<maxx-minx<<endl;
			mindis=min(mindis,maxx-minx);
			
		}
		
		cout<<"Case "<<casen<<": "<<std::fixed<<setprecision(2)<<roundf(mindis * 1000) / 1000<<endl;
		casen++;
		cin>>n;
	}
	
}