// AC
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
	if (s.size() % 2)
	{
		cout<<"NO";
	}	
	else
	{
		std::vector<int> c(26,0);
		for (int i=0;i<s.size();i++)
		{
			c[s[i]-'a']++;
			if (c[s[i]-'a'] > (s.size()/2))
			{
				cout<<"NO";
				return 0;
			}
		}
		cout<<"YES";
	}
}