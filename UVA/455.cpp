//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	string s;
	while(n--)
	{
		cin>>s;
		for(int l=1;l<=s.size();l++)
		{
			if(s.size()%l)
				continue;
			bool valid=1;
			for(int in=0;in<l;in++)
			{
				for(int o=0;o+in<s.size();o+=l)
				{
					if(s[in]!=s[in+o])
					{
						valid=0;
						break;
					}
				}
			}
			if(valid)
			{
				cout<<l<<endl;
				if(n!=0)
				cout<<endl;
				break;
			}
		}

	}	
}