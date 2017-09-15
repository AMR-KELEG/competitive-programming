#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int n,k;
	cin>>n>>k;
	long long int games = n/k;
	if(games%2)
		cout<<"YES";
	else
		cout<<"NO";
}