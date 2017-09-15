#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	char av[11];
	for(int i=1;i<=10;i++)
	{
		cin>>av[i];
	}
	int m;
	cin>>m;
	std::vector<int> no;
	bool done=0;
	int last;
	for(int s=1;s<=10 &&!done;s++)
	{
		int fi=0,se=0;
		if(av[s]=='0')
			continue;
		fi=s;
		last=s;
		no.push_back(s);
		if(no.size()==m)
		{
			done=1;
		}
		while(no.size()<m)
		{
			if(fi>se)
			{
				for(int j=1;j<=10;j++)
				{
					if(av[j]=='1')
					{
						if(last!=j && se+j>fi)
						{
							last=j;
							no.push_back(j);
							se+=j;
							break;
						}
					}
				}
				if(fi>se)
				{
					no.clear();
					break;
				}
			}
			else if(fi<se)
			{
				for(int j=1;j<=10;j++)
				{
					if(av[j]=='1')
					{
						if(last!=j && fi+j>se)
						{
							last=j;
							no.push_back(j);
							fi+=j;
							break;
						}
					}
				}
				if(fi<se)
				{
					no.clear();
					break;
				}
			}
			if(no.size()==m)
			{
				done=1;
			}
				
		}
	}	
	if(done)
	{
		cout<<"YES\n";
		for(int i=0;i<no.size();i++)
		{
			cout<<no[i]<<" ";
		}
	}
	else
	{
		cout<<"NO";
	}
}