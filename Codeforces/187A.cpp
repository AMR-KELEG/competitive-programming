//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,a,a_1;
	cin>>n;
	map<int,int> mp;
	std::vector<int> b(n+5);
	for(int i=1;i<=n;i++)	
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		mp[a]=i;
	}
	int op=0;
	for(int i=2;i<=n;i++)	
	{
		if(mp[b[i]]<mp[b[i-1]])
		{
			op=n-i+1;
			break;
		}	
	}
	cout<<op;
}