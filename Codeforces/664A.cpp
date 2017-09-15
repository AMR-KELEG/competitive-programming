#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string a,b;
	cin>>a>>b;
	if(a==b)
		cout<<a;
	else
		cout<<1;	
}