//AC
#include "bits/stdc++.h"
using namespace std;
bool good[26]={};

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string g;
	cin>>g;
	for(int i=0;i<g.size();i++)
		good[g[i]-'a']=1;
	string pat;
	cin>>pat;
	bool has_ast=0;
	for(int i=0;i<pat.size();i++)
	{
		if(pat[i]=='*')
		{
			has_ast=1;
			break;
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		string s;
		cin>>s;
		if(!has_ast)
		{
			if(s.size()==pat.size())
			{
				// check
				int st = 0;
				int en = s.size()-1;
				while(st<=en)
				{
					if(s[st]==pat[st])
						st++;
					else if(pat[st]=='?' && good[s[st]-'a'])
						st++;
					else
						break;
				}
				if(st>en)
					printf("YES\n");
				else 
					printf("NO\n");

			}
			else
				printf("NO\n");
			
		}
		else
		{
			int sq=0;
			int ss=0;
			int eq=pat.size()-1;
			int es=s.size()-1;
			while(sq<=eq && ss<=es)
			{
				if(pat[sq]==s[ss])
				{
					sq++;
					ss++;
				}
				else if(pat[sq]=='?' && good[s[ss]-'a'])
				{
					sq++;
					ss++;
				}
				else
					break;
			}
			while(eq>=sq && es>=ss)
			{
				if(pat[eq]==s[es])
				{
					eq--;
					es--;
				}
				else if(pat[eq]=='?' && good[s[es]-'a'])
				{
					eq--;
					es--;
				}
				else
					break;
			}
			if(ss>es)
			{
				if(sq>eq || (sq==eq && pat[sq]=='*'))	
					printf("YES\n");
				else
					printf("NO\n");
			}
			else if(sq==eq && pat[sq]=='*')
			{
				bool ok = 1;
				for(int i=ss;i<=es;i++)
				{
					if(good[s[i]-'a'])
					{
						ok=0;
						break;
					}
				}
				if(ok)
					printf("YES\n");
				else
					printf("NO\n");
			}
			else
				printf("NO\n");
		}
	}
}