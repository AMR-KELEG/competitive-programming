//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int a,b,c;
	cin>>a>>b>>c;
	int maxv=a;
	maxv=min(maxv,min(b/2,c/4));
	cout<<(maxv*4)+(maxv*2)+maxv;
}