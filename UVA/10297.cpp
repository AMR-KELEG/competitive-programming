//AC
#include "bits/stdc++.h"
using namespace std;
long double D,V;
long double pi=acos(0)*2;
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>D>>V;
	while(D!=0 && V!=0)
	{
		long double d=(D*D*D)-((6*V)/pi);
		d=pow(abs(d),1/3.0);
		cout<<std::fixed<<setprecision(3)<<d<<endl;
		cin>>D>>V;
	}
}