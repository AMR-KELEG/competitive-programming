#include "bits/stdc++.h"
using namespace std;
string s;
bool valid(int i)
{
	for(int in=0;in<s.size();in++)
	{
		if(in==i)
			continue;
		if(s[i]==s[in])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	if(n>26)
	{
		cout<<-1;
	}
	else
	{
		cin>>s;
		set<char>se;
		for(int i=0;i<s.size();i++)
		{
			se.insert(s[i]);
		}
		cout<<s.size()-se.size();
	}
}