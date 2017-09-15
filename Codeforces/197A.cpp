//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int a,b,r;
	cin>>a>>b>>r;
	cout<<((2*r<=min(a,b))?"First":"Second");
}