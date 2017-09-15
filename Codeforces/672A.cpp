#include "bits/stdc++.h"
using namespace std;
string tostr(int a)
{
	string s="";
	while(a>0)
	{
		s=string(1,(a%10)+'0')+s;
		a=a/10;
	}
	return s;
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int i;
	i=1;
	string s;
	for(;s.size()<1000;i++)
	{
		s+=tostr(i);
	}
	int n;
	cin>>n;
	cout<<s[n-1];
}