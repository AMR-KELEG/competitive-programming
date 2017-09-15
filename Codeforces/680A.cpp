

#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int a[5];
	map<int,int>mp;
	int sum=0;
	for(int i=0;i<5;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
		sum+=a[i];
	}
	int minsum=sum;
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it)
	{
		if((*it).second>1)
		{
			minsum=min(minsum,sum-((min(3,(*it).second))*((*it).first)));
		}
	}
	cout<<minsum;
}