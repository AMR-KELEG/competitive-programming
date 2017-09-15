//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	// std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string s;
	cin>>s;
	std::vector<int> curVal(s.size()),prefix(s.size(),0);
	int indxOfLast=-1;
	for(int i=0;i<s.size();i++)
	{
		if(i>0)
			prefix[i]=prefix[i-1];
		if(s[i]=='(')
		{
			curVal[i]=1;
		}
		else 
		{
			curVal[i]=-1;
		}
		if(s[i]=='#')
			indxOfLast=i;
		prefix[i]+=curVal[i];
	}	
	//First check 
	for(int i=0;i<s.size();i++)
	{
		if(prefix[i]<0)
		{
			cout<<-1;
			return 0;
		}
	}
	if(prefix[s.size()-1]==0)
	{
		//DONE
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='#')
				printf("%d\n",-curVal[i]);
		}
	}
	else
	{
		curVal[indxOfLast]-=prefix[s.size()-1];
		for(int i=0;i<s.size();i++)
		{
			if(i>0)
				prefix[i]=prefix[i-1];
			else
				prefix[i]=0;
			prefix[i]+=curVal[i];
			if(prefix[i]<0)
			{
				cout<<-1;
				return 0;
			}
		}
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='#')
				printf("%d\n",-curVal[i]);
		}
	}
}