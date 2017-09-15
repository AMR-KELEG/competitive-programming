//AC
//Submitted on CodeChef
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int moves=0;
		for(int i=1;i<=n;i++)
		{
			int p;cin>>p;
			moves+=(p/i);
		}
		if(moves%2)
		{
			cout<<"ALICE\n";
		}
		else
		{
			cout<<"BOB\n";
		}
	}	
}