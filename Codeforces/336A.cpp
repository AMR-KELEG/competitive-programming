//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int x1,y1;
	cin>>x1>>y1;
	if(x1*y1>0)
	{
		//Same sign
		int x=x1+y1;
		if(0<x)
			cout<<0<<" "<<x<<" "<<x<<" 0";
		else
			cout<<x<<" 0 0 "<<x;
	}	
	else
	{
		int x=-x1+y1;
		if(0<-x)
			cout<<0<<" "<<x<<" "<<-x<<" 0";
		else
			cout<<-x<<" 0 "<<0<<" "<<x;
	}
}