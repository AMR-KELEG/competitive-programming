#include "bits/stdc++.h"
using namespace std;
#define MOD (1000000007)
string s;
unordered_map<int,int>mp_last_open[2000001];
unordered_map<int,int>mp_last_closed[2000001];

int solve(int in=0,int noOfOpen=0,bool lastIsOpen=1)
{
	if(in==s.size())
		return 0;
	if(noOfOpen>s.size()-in)
	{
		return 0;
	}
	if(lastIsOpen)
	{
		if(mp_last_open[in].find(noOfOpen)!=mp_last_open[in].end())
		{
			return mp_last_open[in][noOfOpen];
		}
		long long ans=0;
		if(s[in]=='(')
		{
			ans=solve(in+1,noOfOpen+1,1);
			ans+=solve(in+1,noOfOpen,lastIsOpen);
			return mp_last_open[in][noOfOpen]=ans%MOD;
		}
		else if(noOfOpen==0)
		{
			ans=solve(in+1,noOfOpen,lastIsOpen);
			return mp_last_open[in][noOfOpen]=ans;
		}
		else if(noOfOpen==1)
		{
			ans=1+solve(in+1,noOfOpen,lastIsOpen);
			return mp_last_closed[in][noOfOpen]=ans%MOD;
		}
		else
		{
			ans=solve(in+1,noOfOpen-1,0);
			ans+=solve(in+1,noOfOpen,lastIsOpen);
			return mp_last_open[in][noOfOpen]=ans%MOD;
		}
	}
	else
	{
		if(mp_last_closed[in].find(noOfOpen)!=mp_last_closed[in].end())
		{
			return mp_last_closed[in][noOfOpen];
		}
		long long ans=0;
		if(s[in]=='(')
		{
			if(noOfOpen==0)
				return 0;
			ans=solve(in+1,noOfOpen,lastIsOpen);
			return mp_last_closed[in][noOfOpen]=ans%MOD;
		}
		else if(noOfOpen==1)
		{
			ans=1+solve(in+1,noOfOpen,lastIsOpen);
			return mp_last_closed[in][noOfOpen]=ans%MOD;
		}
		else
		{
			ans=solve(in+1,noOfOpen-1,0);
			ans+=solve(in+1,noOfOpen,lastIsOpen);
			return mp_last_closed[in][noOfOpen]=ans%MOD;
		}
	}

}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>s;
	int start=0;
	while(start<s.size() && s[start]==')')
		start++;
	s.erase(0,start);
	int en=s.size()-1;
	while(en>=0 && s[en]=='(')
		en--;
	if(en>=0)
	{
		s=s.substr(0,en+1);
		//Solve
		for(int i=0;i<s.size();i++)
		{
			mp_last_open[i].reserve(100);
			mp_last_closed[i].reserve(100);
		}
		cout<<solve();
	}	
	else
	{
		cout<<0;
	}
}