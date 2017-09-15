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
	cin>>s;
	bool foundOGO=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='o' && i+2<s.size() && s[i+1]=='g' && s[i+2]=='o')
		{
			foundOGO=1;
			cout<<"***";
			i+=2;
		}
		else if(foundOGO)
		{
			if(s[i]=='g' && i+1<s.size() && s[i+1]=='o')
			{
				i++;
			}
			else
			{
				foundOGO=0;
				i--;
			}
		}
		else
		{
			foundOGO=0;
			cout<<s[i];
		}
	}
}