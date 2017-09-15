//AC
#include "bits/stdc++.h"
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	int n,m,h;
	cin>>n>>m>>h;
	std::vector<int> s(m);
	int SegmaS=0;
	h--;
	for(int i=0;i<m;i++)
	{
		cin>>s[i];
		SegmaS+=s[i];
	}
	cout<<fixed<<setprecision(6);
	if(SegmaS<n)
	{
		cout<<-1;
	}
	else if(s[h]==1)
	{
		cout<<0.0;
	}
	else
	{
		long double ans=1;
		int divisor=SegmaS-1;//divisor>divisorLimit
		int divisorLimit=SegmaS-s[h];
		int mult=SegmaS-n;
		int multLimit=SegmaS-s[h]-n+1;//mult>multLimit
		while(mult>multLimit || divisor>divisorLimit)
		{
			if(mult>multLimit)
			{
				ans*=mult;
				mult--;
			}
			if(divisor>divisorLimit)
			{
				ans/=divisor;
				divisor--;
			}
		}
		cout<<1-ans;
	}
	return 0;
}