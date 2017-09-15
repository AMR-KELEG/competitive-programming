#include "bits/stdc++.h"
using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,k;
	cin>>n>>k;
	vector<int>power(k,0);
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		power[i%k]+=a;
	}
	int mini=0;
	for(int i=1;i<k;i++)
	{
		if(power[i]<power[mini])
			mini=i;
	}
	cout<<mini+1;
	return 0;
}