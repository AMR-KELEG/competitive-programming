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
	getline(cin,s);
	while(s!="#")
	{
		int ans = 0;
		for (int i=1;i<=s.size();i++)
		{
			if (s[i-1]==' ')
				continue;
			ans += (s[i-1]-'A'+1) * i;
		}
		cout<<ans<<endl;
		getline(cin, s);
	}	
}