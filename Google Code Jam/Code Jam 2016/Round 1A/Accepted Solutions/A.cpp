#include "bits/stdc++.h"
using namespace std;
string s;
string findper(string cs,int i)
{
	if(i==s.size())
		return cs;
	string ns=string(1,s[i])+cs;
	if(ns>cs)
	{
		return findper(ns,i+1);
	}
	else
	{
		return findper(cs+string(1,s[i]),i+1);
	}

}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("A-large.in","r",stdin);
		freopen("a.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	for(int te=1;te<=t;te++)
	{
		cin>>s;
		cout<<"Case #"<<te<<": "<<findper("",0)<<endl;
	}
}