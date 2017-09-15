#include "bits/stdc++.h"
#define MOD 1000000007
using namespace std;
map<pair<int,int>, int> dp;
int n;
int solve(int indx =0, int gcd = -1)
{
	if(indx == n)
		return 1;
	if(gcd == -1)
		return  
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	std::vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	solve();	
}