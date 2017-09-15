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
	int x=0,y=0;
	if(s.size()%2)
		cout<<-1;
	else
	{
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='R')x++;
			if(s[i]=='L')x--;
			if(s[i]=='U')y++;
			if(s[i]=='D')y--;
		}
		cout<<(abs(x)+abs(y))*0.5;
	}

}