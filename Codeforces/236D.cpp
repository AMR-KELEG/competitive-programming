#include "bits/stdc++.h"
long double THR = 0.00000001;
using namespace std;

std::vector<long double> v;

long double solve(int in= 0, int len = 0, long double p = 1)
{
	if (in == v.size())
	{
		return p*len*len;
	}
	if (p<= THR)
	{
		cout<<"Cut Here "<<in<<" \n";
		return 0;
	}
	return solve(in+1,len+1,p* v[in])+ (p*(1-v[in])*len*len) + solve(in+1,0,p* (1-v[in])); 
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	v= std::vector<long double> (n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	// cout<<100000<<endl;
	// for (int i=0;i<100000;i++)
	// 	cout<<0.5<<" ";
	cout<<fixed<<setprecision(6)<<solve();
}