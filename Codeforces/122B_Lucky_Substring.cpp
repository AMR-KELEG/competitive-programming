#include "bits/stdc++.h"
using namespace std;
int main()
{
	string s;
	int c7=0,c4=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='4')c4++;
		else if(s[i]=='7')c7++;
	}
	if(c4>=c7 && c4>0)cout<<"4";
	else if(c7>=c4 && c7>0)cout<<"7";
	else cout<<"-1";
}