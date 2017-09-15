//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	double x1,y1,x2,y2;
	double area=0;
	cin>>x2>>y2;
	for(int i=1;i<n;i++)
	{
		x1=x2;
		y1=y2;
		cin>>x2>>y2;
		area+=0.5*(y1-y2)*(x1+x2);
	}
	area=abs(area);
	area=round(area);
	cout<<area;
}