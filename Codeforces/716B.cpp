#include "bits/stdc++.h"
using namespace std;
int dic[26]={};
int findCount()
{
	int ans=0;
	for(int i=0;i<26;i++)
		ans+=(dic[i]!=0);
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string s;
	cin>>s;
	if(s.size()<26)
	{
		cout<<-1;
		return 0;
	}
	int canreplace=0;

	for(int i=0;i<26;i++)
	{
		if(s[i]=='?')
			canreplace++;
		else
			dic[s[i]-'A']++;
	}

	if(findCount()+canreplace==26)
	{
		//Done
		for(int i=0;i<26;i++)
		{
			if(s[i]=='?')
			{
				for(int j=0;j<26;j++)
				{
					if(dic[j]==0)
					{
						dic[j]++;
						cout<<char('A'+j);
						break;
					}
				}
			}
			else
				cout<<s[i];
		}
		for(int i=26;i<s.size();i++)
		{
			if(s[i]=='?')
				cout<<'A';
			else
				cout<<s[i];
		}
		return 0;
	}

	for(int start=1;start<=s.size()-26;start++)
	{	
		// cout<<start<<endl;
		//remove s[start-1]
		if(s[start-1]=='?')
			canreplace--;
		else
			dic[s[start-1]-'A']--;
		//add s[start+26]
		if(s[start+25]=='?')
			canreplace++;
		else
			dic[s[start+25]-'A']++;

		if(findCount()+canreplace==26)
		{
			//Done
			for(int i=0;i<start;i++)
			{
				if(s[i]=='?')
					cout<<'A';
				else
					cout<<s[i];
			}
			for(int i=start;i<start+26;i++)
			{
				if(s[i]=='?')
				{
					for(int j=0;j<26;j++)
					{
						if(dic[j]==0)
						{
							dic[j]++;
							cout<<char('A'+j);
							break;
						}
					}
				}
				else
					cout<<s[i];
			}
			for(int i=start+26;i<s.size();i++)
			{
				if(s[i]=='?')
					cout<<'A';
				else
					cout<<s[i];
			}
			return 0;
		}

	}
	cout<<-1;
}