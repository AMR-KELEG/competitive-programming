#include "bits/stdc++.h"
using namespace std;
int main()
{
	int n,tem;
	cin>>n;
	int evens=0,odds=0;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>tem;
		if(tem&1)odds++;
		else
			evens++;
		sum+=tem;
	}
	if(sum%2==0)cout<<evens;
	else
		cout<<odds;
	return 0;
}