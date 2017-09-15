#include "bits/stdc++.h"
using namespace std;
int main()
{
	int n,t;//n is the length
	cin>>n>>t;
	if(n==1 && t==10)cout<<"-1";
	else if (t==10)
	{
		cout<<t<<string(n-2,'0');
	}
	else
	{
		cout<<t<<string(n-1,'0');	
	}
	return 0;
}
