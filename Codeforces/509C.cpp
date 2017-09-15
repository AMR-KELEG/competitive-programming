#include "bits/stdc++.h"
using namespace std;
string convertS(int i)
{
	string ans="";
	while(i>0)
	{
		int curDigit=min(9,i);
		ans=char(curDigit+'0')+ans;
		i-=curDigit;
	}
	return ans;
}

bool islarger(string &s1,string &s2)
{
	if(s1.size()>s2.size())
		return 1;
	if(s1.size()<s2.size())
		return 0;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]<s2[i])
			return 0;
		if(s1[i]>s2[i])
			return 1;
	}
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	int minLen=1,b;
	string lasts;
	string curs;
	for(int i=0;i<n;i++)
	{
		cin>>b;
		curs=convertS(b);
		if(islarger(curs,lasts))
		{
			cout<<curs<<endl;
			minLen=curs.length()+1;
			lasts=curs;
			continue;
		}
		//reverse yourself
		// reverse(curs.begin(), curs.end());
		// if(islarger(curs,lasts))
		// {
		// 	cout<<curs<<endl;
		// 	minLen=curs.length()+1;
		// 	lasts=curs;
		// 	continue;
		// }
		else
		{
			int fir=1;
			for(;fir<b;fir++)
			{
				string s=convertS(b-fir);
				string ss=char(fir+'0')+s;
				if(islarger(ss,lasts))
				{
					cout<<ss<<endl;
					minLen=ss.length()+1;
					lasts=ss;
					break;
				}
				reverse(s.begin(), s.end());
				s=char(fir+'0')+s;
				if(islarger(s,lasts))
				{
					cout<<s<<endl;
					minLen=s.length()+1;
					lasts=s;
					break;
				}
			}
			if(fir!=b)
				continue;
		}

		// cout<<"NOT OK ";
		// reverse(curs.begin(), curs.end());
		if(curs.length()>minLen)
		{
			cout<<curs<<endl;
			minLen=curs.length()+1;
		}
		else
		{
			//will add zeros
			//first add minlen-1 zeros 
			cout<<curs<<string(minLen-curs.length(),'0')<<endl;
			minLen++;
		}
		lasts=curs;
	}
}