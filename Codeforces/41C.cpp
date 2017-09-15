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
	bool foundat=0;
	cout<<s[0];
	for(int i=1;i<s.size();i++)
	{
		if(s.find("dot",i)==i)
		{
			if(i==s.size()-3)
			{
				cout<<"dot";
				i+=2;
				continue;
			}
			cout<<".";
			i+=2;
		}
		else if(s.find("at",i)==i && !foundat)
		{
			if(i==s.size()-2)
			{
				cout<<"at";
				i+=2;
				foundat=1;
				continue;
			}
			cout<<"@";
			i+=1;
			foundat=1;
		}
		else
		{
			cout<<s[i];
		}
	}	
}