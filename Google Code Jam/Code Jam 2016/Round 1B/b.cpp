#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int te;cin>>te;
	string fir,sec;
	int greater;
	for(int t=1;t<=te;t++)
	{
		greater=0;
		cin>>fir>>sec;
		for(int i=0;i<fir.size();i++)
		{
			if(fir[i]>sec[i])
				greater=1;
			else if(fir[i]<sec[i])
				greater=-1;
		}
		for(int i=0;i<fir.size();i++)
		{
			if(greater==0)
			{
				if(fir[i]=='?' && sec[i]=='?')
					fir[i]=sec[i]='0';
				else if(fir[i]=='?')
					fir[i]=sec[i];
				else if(sec[i]=='?')
					sec[i]=fir[i];
				else if(fir[i]>sec[i])
					greater=1;
				else if(fir[i]<sec[i])
					greater=-1;
			}
			else if(greater==1)
			{
				if(fir[i]=='?' && sec[i]=='?')
				{
					fir[i]='0';
					sec[i]='9';
				}
				else if(fir[i]=='?')
					fir[i]='0';
				else if(sec[i]=='?')
					sec[i]='9';
			}
			else
			{
				if(fir[i]=='?' && sec[i]=='?')
				{
					fir[i]='9';
					sec[i]='0';
				}
				else if(fir[i]=='?')
					fir[i]='9';
				else if(sec[i]=='?')
					sec[i]='1';
			}
		}
		cout<<"Case #"<<t<<": "<<fir<<" "<<sec<<endl;
	}
}