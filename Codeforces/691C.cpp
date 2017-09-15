//AC
#include "bits/stdc++.h"
using namespace std;
void removeprec(string & s)
{
	int i;
	for(i=0;i<s.size();i++)
	{
		if(s[i]!='0')
			break;
	}
	if(i<s.size())
		s=s.substr(i);
	else
		s="";
}
void removetrail(string & s)
{
	int i;
	for(i=s.size()-1;i>=0;i--)
	{
		if(s[i]!='0')
			break;
	}
	if(i!=-1)
		s=s.substr(0,i+1);
	else
		s="";
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	string s ;
	cin>>s;
	string bef,aft;
	if(s.find('.')!=-1)
	{
		int dotin=s.find('.');
		bef=s.substr(0,dotin);
		aft=s.substr(dotin+1);
		removeprec(bef);
		removetrail(aft);
		if(aft.size()==0)
		{
			if(bef.size()==0)
				cout<<0;
			else if(bef.size()==1)
			cout<<bef;
			else
			{
				aft=bef.substr(1);
				removetrail(aft);
				cout<<bef[0];
				if(aft.size())
					cout<<"."<<aft;
				cout<<"E"<<bef.size()-1;
			}
		}
		else if(bef.size()==0)
		{
			int ind=0;
			for(int i=0;i<aft.size();i++)
				if(aft[i]!='0')
				{
					ind=i;break;
				}
			// cout<<ind<<endl;
			int power=-(ind+1);
			removeprec(aft);
			cout<<aft[0];
			if(aft.size()>1)
				cout<<'.'<<aft.substr(1);
			cout<<"E"<<power;
		}
		else if(bef.size()==1)
		{
			cout<<bef<<"."<<aft;
		}
		else
		{
			cout<<bef[0]<<'.'<<bef.substr(1)<<aft<<"E"<<bef.size()-1;
		}
	}
	else
	{
		bef=s;
		removeprec(bef);
		if(bef.size()==0)
			cout<<0;
		else if(bef.size()==1)
			cout<<bef;
		else
		{
			aft=bef.substr(1);
			removetrail(aft);
			cout<<bef[0];
			if(aft.size())
				cout<<"."<<aft;
			cout<<"E"<<bef.size()-1;
		}
	}


}