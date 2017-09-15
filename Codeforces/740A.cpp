//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int n,a,b,c;
	cin>>n>>a>>b>>c;
	if(n%4==0)
	{
		cout<<0;
	}
	else if(n%4==3)
	{
		//need 1
		cout<<min(a,min(b+c,3*c));
	}
	else if(n%4==2)
	{
		cout<<min(2*a,min(b,2*c));
	}
	else 
	{
		//need 3
		cout<<min(c,min(3*a,a+b));
	}
}