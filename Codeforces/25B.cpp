#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	string s;
	cin>>s;
	int i=0;
	if(n%2)
	{
		//odd
		cout<<s[0];
		i=1;
	}	
	while(i+2<s.size())
	{
		cout<<s[i]<<s[i+1]<<"-";
		i+=2;
	}
	cout<<s[i]<<s[i+1];
}