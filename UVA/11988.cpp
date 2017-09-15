#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string s;
	list<char>l;
	list<char>::iterator it;
	while(cin>>s)
	{
		l.clear();
		it=l.begin();
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='[')
			{
				it=l.begin();
			}
			else if(s[i]==']')
			{
				it=l.end();
			}
			else
			{
				l.insert(it,s[i]);
			}
		}
		for(it=l.begin();it!=l.end();it++)
		{
			cout<<*it;
		}
		cout<<endl;
	}	
}