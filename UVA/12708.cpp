//AC
#include "bits/stdc++.h"
using namespace std;
#define findgcd(n) (n)/2
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	long long int n;
	while(t--)
	{
		cin>>n;
		cout<<findgcd(n)<<endl;
	}	
}