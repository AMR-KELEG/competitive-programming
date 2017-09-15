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
	int x;
	long long int x1=0,x2=0;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		x1=x1|x;
	}	
	for(int i=0;i<n;i++)
	{
		cin>>x;
		x2=x2|x;
	}	
	cout<<x1+x2;
}