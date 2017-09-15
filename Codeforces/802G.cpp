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
	string s2 = "heidi";
	int indx =0; // limit is 5
	for (int i=0;i<s.size();i++)
	{
		if (s[i]== s2[indx])
		{
			indx++;
			if (indx==5)
			{
				cout<<"YES";
				return 0;
			}
		}
	}	
	cout<<"NO";
}