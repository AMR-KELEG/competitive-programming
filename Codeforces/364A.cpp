//AC 3 sub -- be aware of the no%0
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	string s;
	int a;
	cin>>a;
	cin>>s;
	map<long long int,long long int>mp;//sum and 
	// s='0'+s;
	long long int sum=0;
	for(int i=0;i<s.size();i++)
	{
		sum=(s[i]-'0');
		mp[sum]++;
		for(int j=i+1;j<s.size();j++)
		{
			sum+=(s[j]-'0');
			mp[sum]++;
		}
	}
	long long int ans=0;
	if(a==0)
	{
		ans=2*mp[0]*((0.5*s.size()*(s.size()+1))-mp[0]);
		ans+=mp[0]*mp[0];
	}
	else
	{
		long long int v,count;

		map<long long int,long long int>::iterator it=mp.begin();
		while(it!=mp.end())
		{
			v=(*it).first;
			count=(*it).second;
			// cout<<"V "<<v<<endl;
			if(v==0)
			{
				it++;
				continue;
			}
			if(a%v==0)
			{
				// cout<<v<<" "<<a/v<<endl;
				if(a==v*v)
				{
					ans+=count*count;// ???
				}
				else
				{
					ans+=count*mp[a/v];
				}
			}
			it++;
		}
	}
	cout<<ans<<endl;
	// cout<<s;
}