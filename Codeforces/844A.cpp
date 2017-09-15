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
	int k;
	cin>>k;
	set<char> S;
	for(auto c:s)
	{
		S.insert(c);
	}	
	if(S.size()>=k)
		cout<<0;
	else
	{
		int rem = int(s.size())-int(S.size());
		k-= int(S.size());
		if(rem>=k)
		{
			cout<<k;
		}
		else
		{
			cout<<"impossible";
		}
	}
}