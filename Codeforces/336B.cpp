#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int m,R;
	cin>>m>>R;
	long double ans=sqrt(2.0)*(m-1);//Divided by m
	ans+=2;
	long long int co=0;
	for(long long int cir=1;cir<=m;cir++)
	{
		//Left = cir-1
		//Right = m-cir 
		co+=(cir-1)*(cir);
		co+=(m-cir)*(1+m-cir);
	}
	//Divide by m*m
	long double add=co;
	add/=m;
	ans+=add;
	ans*=R;
	ans/=m;
	cout<<fixed<<setprecision(10)<<ans;
}