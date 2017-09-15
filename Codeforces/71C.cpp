#include "bits/stdc++.h"
using namespace std;
int n;
std::vector<bool> v;
bool check(int s,int step)
{
	for(int i=s;i<n;i+=step)
	{
		if(!v[i])
			return 0;
	}
	return 1;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	v=std::vector<bool> (n);
	int t;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		v[i]=t;
	}
	for(int di=1;di*di<=n;di++)
	{
		if(n%di==0)
		{
			//di is a divisor n/di is a divisor
			if(n/di>=3)
			{
				//search for start
				for(int start=0;start<di;start++)
				{
					if(check(start,di))
					{
						// cout<<start<<" "<<di<<endl;
						cout<<"YES";
						return 0;
					}	
				}
			}
			if(di>=3)
			{
				//search for start
				//search for start
				for(int start=0;start<n/di;start++)
				{
					if(check(start,n/di))
					{
						// cout<<start<<" "<<n/di<<endl;
						cout<<"YES";
						return 0;
					}	
				}
			}
		}
	}
	cout<<"NO";
	return 0;	
}