//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	for	(int t=1;t<=T;t++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		cout<<"Case "<<t<<": "<< x+y+z- max(max(x,y),z)- min(min(x,y),z)<<endl;
	}
}