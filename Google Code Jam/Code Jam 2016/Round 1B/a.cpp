#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("A-large.in","r",stdin);
		freopen("A-large-out.in","w",stdout);
	#endif
	int t;
	cin>>t;
	string s;
	int countalp[226]={};
	int countno[10]={};
	for(int te=1;te<=t;te++)
	{
		cin>>s;
		memset(countalp,0,sizeof countalp);
		memset(countno,0,sizeof countno);
		for(int i=0;i<s.size();i++)
		{
			countalp[s[i]]++;
		}

		while(countalp['Z']>0 && countalp['R']>0 &&countalp['E']>0 &&countalp['O']>0)
		{
			countno[0]++;
			countalp['Z']--;
			countalp['R']--;
			countalp['E']--;
			countalp['O']--;
		}
		while(countalp['S']>0 && countalp['I']>0 &&countalp['X']>0)
		{
			countno[6]++;
			countalp['S']--;
			countalp['I']--;
			countalp['X']--;
		}
		while(countalp['F']>0 && countalp['R']>0 &&countalp['U']>0 &&countalp['O']>0)
		{
			countno[4]++;
			countalp['F']--;
			countalp['R']--;
			countalp['U']--;
			countalp['O']--;
		}
		while(countalp['F']>0 && countalp['I']>0 &&countalp['E']>0 &&countalp['V']>0)
		{
			countno[5]++;
			countalp['F']--;
			countalp['I']--;
			countalp['E']--;
			countalp['V']--;
		}
		while(countalp['E']>0 && countalp['I']>0 &&countalp['G']>0 &&countalp['H']>0&&countalp['T']>0)
		{
			countno[8]++;
			countalp['I']--;
			countalp['G']--;
			countalp['E']--;
			countalp['H']--;
			countalp['T']--;
		}
		while(countalp['S']>0 && countalp['E']>1 &&countalp['V']>0 &&countalp['N']>0)
		{
			countno[7]++;
			countalp['S']--;
			countalp['E']--;
			countalp['E']--;
			countalp['V']--;
			countalp['N']--;
		}
		while(countalp['T']>0 && countalp['W']>0 &&countalp['O']>0)
		{
			countno[2]++;
			countalp['T']--;
			countalp['W']--;
			countalp['O']--;
		}
		while(countalp['T']>0 && countalp['R']>0 &&countalp['E']>1 &&countalp['H']>0)
		{
			countno[3]++;
			countalp['T']--;
			countalp['R']--;
			countalp['E']--;
			countalp['E']--;
			countalp['H']--;
		}
		while(countalp['N']>0 &&countalp['E']>0 &&countalp['O']>0)
		{
			countno[1]++;
			countalp['N']--;
			countalp['E']--;
			countalp['O']--;
		}
		while(countalp['N']>1 && countalp['I']>0 &&countalp['E']>0 )
		{
			countno[9]++;
			countalp['N']--;
			countalp['N']--;
			countalp['E']--;
			countalp['I']--;
		}
		cout<<"Case #"<<te<<": ";
		for(int i=0;i<10;i++)
			cout<<string(countno[i],'0'+i);
		cout<<endl;

	}	
}