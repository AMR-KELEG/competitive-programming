//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int a=0,b=0,c=0;
	string s;
	cin>>s;
	int i=0;
	for(;i<s.size();i++)
	{
		if(s[i]=='+')
		{
			i++;
			break;
		}
		a++;
	}
	for(;i<s.size();i++)
	{
		if(s[i]=='=')
		{
			i++;
			break;
		}
		b++;
	}
	for(;i<s.size();i++)
	{
		c++;
	}


	// cout<<a<<" "<<b<<" "<<c<<endl;
	if(a+b==c)
		cout<<s;
	else if(a+b+1==c-1 && c-1>0)
	{
		a++;
		c--;
		cout<<string(a,'|')<<"+"<<string(b,'|')<<"="<<string(c,'|');
	}
	else if(a+b-1==c+1 && max(a,b)-1>0)
	{
		if(a>b)
			a--;
		else 
			b--;
		c++;
		cout<<string(a,'|')<<"+"<<string(b,'|')<<"="<<string(c,'|');	
	}
	else
	{
		cout<<"Impossible";
	}


}