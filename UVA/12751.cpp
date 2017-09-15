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
	for(int t=1;t<=T;t++)
	{
		int n,k,x;
		cin>>n>>k>>x;
		int total=(n*(n+1))/2;
		total-=(k*(k+1))/2;
		total-=(k*(x-1));
		cout<<"Case "<<t<<": "<<total<<endl;
	}
}