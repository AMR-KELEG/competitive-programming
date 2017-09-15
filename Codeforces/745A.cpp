//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string s;
	cin>>s;
	//abcd
	//  ^
	//dabc
	//cdab
	set<string>strs;
	for(int i=0;i<s.size();i++)
	{
		strs.insert(s.substr(i)+s.substr(0,i));
	}
	cout<<strs.size();
}