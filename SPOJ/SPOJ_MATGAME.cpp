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
		int n,m;
		cin>>n>>m;
		int no;
		int ans=0;
		for(int i=0;i<n*m;i++)
		{
			cin>>no;
			ans^=no;
		}
		
	}	
}