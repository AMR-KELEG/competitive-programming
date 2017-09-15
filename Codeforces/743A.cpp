//AC
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
	int a,b;
	cin>>a>>b;
	a--;
	b--;
	string s;
	cin>>s;
	if(s[a]==s[b])
		cout<<0;
	else
		cout<<1;	
}