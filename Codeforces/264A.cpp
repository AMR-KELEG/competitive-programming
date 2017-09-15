//llrlr
//  3 . . 2 1
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
	list<int>li;
	list<int>::iterator it=li.begin();
	for(int i=0;i<s.size();i++)	
	{
		// 3 5 4 2 1 
		li.insert(it,i+1);
		if(s[i]=='l')
		{
			it--;
		}

	}

	for(it=li.begin();it!=li.end();it++)
	{
		printf("%d\n",*it);
	}
}