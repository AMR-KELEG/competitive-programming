#include "bits/stdc++.h"
#define EPS 0.0000001
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int k,q;
	cin>>k>>q;
	std::vector<long double> prob(1000000);
	long double pr= 1;
	for(int i=0;i<k;i++)
	{
		pr *= i+1;
		pr /= k;
	}
	prob[0] = pr;
	cout<<prob[0]<<endl;
	for(int i=1;i<prob.size();i++)
	{
		prob[i]= prob[i-1]*(i+k);
		prob[i]/= (i*k);
		if(i<10)
			cout<<prob[i]<<endl;
	}	
	int p;
	while(q--)
	{
		cin>>p;
		pr=p-EPS;
		pr/=2000;
		cout<<"Find "<<pr<<endl;
		// Search for lower_bound
		int indx = lower_bound(prob.rbegin(), prob.rend(),pr) - prob.rbegin();
		printf("%d\n", indx+k);
	}
}