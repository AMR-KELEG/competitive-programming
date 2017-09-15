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
	if(n==1)
	{
		cout<<"1 2 3";
	}
	else if(n==2)
	{
		cout<<"3 4 5";
	}
	else
	{
		cout<<-1;
	}	
}