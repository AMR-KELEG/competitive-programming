#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;//number of blocks
	std::vector<pair<long long int,char> > t(n),s(m);
	long long int val;
	char c;
	cin>>val>>c>>c;
	n--;
	t[0]=pair<long long int,char>(val,c);
	int ts=1;
	while(n--)
	{
		cin>>val;
		cin>>c>>c;
		if(t[ts-1].second==c)
		{
			t[ts-1].first+=val;
		}
		else
		{
			t[ts++]=pair<long long int,char>(val,c);
		}
	}
	cin>>val>>c>>c;
	m--;
	s[0]=pair<long long int,char>(val,c);
	int ss=1;
	while(m--)
	{
		cin>>val;
		cin>>c>>c;
		if(s[ss-1].second==c)
		{
			s[ss-1].first+=val;
		}
		else
		{
			s[ss++]=pair<long long int,char>(val,c);
		}
	}
	long long int count=0;
	if(ss==1)
	{
		for(int i=0;i<ts;i++)
		{
			if(t[i].second==s[ss-1].second)
			{
				if(t[i].first>=s[ss-1].first)
					count+=1+t[i].first-s[ss-1].first;
				i++;
			}
		}
	}
	else
	{
		int j=0,i=0;
		for(;i<ts;i++)
		{
			if(t[i].second==s[j].second)
			{
				if(j==0 || j==ss-1)
				{
					if(t[i].first>=s[j].first)
					{
						j++;
					}	
					else
					{
						j=0;
					}
				}
				else if(t[i].first==s[j].first)
				{
					j++;
				}
				else
				{
					if(j>0)
						i--;
					j=0;
				}		
			}
			else
			{
				if(j>0)
					i--;
				j=0;
			}

			if(j==ss)
			{
				i=i-j+1;
				count++;
				j=0;
			}
		}
	}
	
	cout<<count;
	
}