#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string s;
	getline(cin,s);
	long long int po=0,ne=0;
	long long int n;
	bool aftern=false;
	if(s[0]!='+' &&s[0]!='-')
		s="+ "+s;
	for(int i=0;i<s.size();i+=4)
	{
		if(s[i]=='+')
		{
			if(aftern)
				ne++;
			else
				po++;
				
		}
		else if(s[i]=='-')
		{
			if(aftern)
				po++;
			else
				ne++;
				
		}
		else
		{
			n=atoi(s.substr(i+1).c_str());
			aftern=true;
			while(i<s.size() && s[i]!='+'&&s[i]!='-')
				i++;
			i-=4;
		}
	}	
	//cout<<po<<" "<<ne<<" "<<n<<endl;
	aftern=0;
	if(po*n>=(ne+n))
	{
		cout<<"Possible\n";
		long long int val=ceil(1.0*(n+ne)/po);
		long long int totalval=n+ne;
		for(int i=0;i<s.size();i+=4)
		{
			if(s[i]=='+')
			{
				if(!aftern)
				{
					if(i!=0)
						cout<<"+ ";
					if(totalval>=val)
					{
						cout<<val<<" ";
						totalval-=val;
					}
					else
					{
						cout<<totalval<<" ";
						totalval=0;
					}
				}
				else
				{
					cout<<"+ 1 ";
				}
			}
			else if(s[i]=='-')
			{
				if(!aftern)
					cout<<"- 1 ";
				else
				{
					cout<<"- ";
					if(totalval>=val)
					{
						cout<<val<<" ";
						totalval-=val;
					}
					else
					{
						cout<<totalval<<" ";
						totalval=0;
					}
				}
			}
			else
			{
				while(i<s.size() && s[i]!='+' && s[i]!='-')
				{
					cout<<s[i];
					i++;
				}
				i-=4;
				aftern=1;
			}
		}	
	}
	else
	{
		cout<<"Impossible";
	}
}