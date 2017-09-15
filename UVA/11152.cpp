//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	long double pi=2*acos(0);
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		long double p=(a+b+c)/2.0;
		long double area=p*(p-a)*(p-b)*(p-c);
		area=sqrt(area);
		long double r=(area)/p;
		long double R=(a*b*c)/(4*area);
		long double roses=(pi*r*r);//right
		long double violets=area-roses;
		long double sunflowers=(pi*R*R)-area;
		cout<<std::fixed<<setprecision(4)<<sunflowers<<" "<<violets<<" "<<roses<<endl;
	}

}