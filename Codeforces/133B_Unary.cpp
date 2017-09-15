#include "bits/stdc++.h"
using namespace std;
long long int modadd(int n)
{
	long long int r=1;
	for(int i=0;i<n;i++)
	{
		r*=2;
		r%=1000003;
	}
	return r;
}
int main()
{
	string s,p;
	cin>>p;
	long long int res=0;
	for(int i=0;i<p.size();i++)
	{
		if(p[i]=='>')
			s+="1000";
		else if(p[i]=='<')
			s+="1001";
		else if(p[i]=='+')
			s+="1010";
		else if(p[i]=='-')
			s+="1011";
		else if(p[i]=='.')
			s+="1100";
		else if(p[i]==',')
			s+="1101";
		else if(p[i]=='[')
			s+="1110";
		else if(p[i]==']')
			s+="1111";
	}
	for(int j=0;j<s.size();j++)
	{
		if(s[j]=='1')
		{
			res+=modadd(s.size()-j-1);
			res%=1000003;
		}
	}
	cout<<res;
	return 0;
}