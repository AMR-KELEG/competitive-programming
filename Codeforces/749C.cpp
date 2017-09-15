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
	std::vector<bool> done(n,0);
	bool change=1;
	int remD=0,remR=0;
	while(change)
	{
		change=0;
		for(int i=0;i<n;i++)
		{
			if(done[i])
			{
				continue;
			}
			else if(s[i]=='D' && remD)
			{
				remD--;
				done[i]=1;
			}
			else if(s[i]=='R' && remR)
			{
				remR--;
				done[i]=1;
			}
			else if(s[i]=='D')
			{
				remR++;
			}
			else
			{
				remD++;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(done[i])
			{
				continue;
			}
			else if(s[i]=='D' && remD)
			{
				remD--;
				done[i]=1;
			}
			else if(s[i]=='R' && remR)
			{
				remR--;
				done[i]=1;
			}
		}
		if(remR==0 && remD==0)
		{
			change=1;
		}
	}	
	if(remR)
		cout<<"D";
	else
		cout<<"R";
}