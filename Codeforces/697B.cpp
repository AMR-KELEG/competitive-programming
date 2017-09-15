//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	string a,d,b;
	// char dot,ex;
	string s;
	cin>>s;
	int dot=s.find('.');
	int ex=s.find('e');
	a=s.substr(0,dot);
	d=s.substr(dot+1,ex-dot-1);
	b=s.substr(ex+1);
	// cout<<a<<endl;
	// cout<<d<<endl;
	// cout<<b<<endl;
	if(a=="0" && d=="0")
		cout<<0;
	else if(b=="0")
	{
		if(d=="0")
		{
			cout<<a;
		}
		else
			cout<<a<<"."<<d;
	}
	else
	{
		int shi=atoi(b.c_str());
		// cout<<shi<<endl;
		if(a!="0")
		{
			cout<<a;
		}
		int i;
		for(i=0;i<d.size() && shi>0;i++)
		{
			cout<<d[i];
			shi--;
		}
		if(shi>0)
			cout<<string(shi,'0');
		else if(i!=d.size())
		{
			cout<<'.';
			// i--;
			// cout<<"I "<<i<<" "<<d.size()<<endl;
			for(;i<d.size();i++)
				cout<<d[i];
		}
	}
}