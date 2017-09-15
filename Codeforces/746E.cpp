//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	std::vector<int> a(n);
	set<int>s;
	std::vector<bool> isGood(n,0);
	int countEven=0,countOdd=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(s.find(a[i])==s.end())
		{
			isGood[i]=1;
			s.insert(a[i]);	
			(a[i]%2==1)?countOdd++:countEven++;
		}
	}
	int nextEven=2;
	int nextOdd=1;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(!isGood[i])
		{
			if(countEven<countOdd)
			{
				while(s.find(nextEven)!=s.end())
				{
					nextEven+=2;
				}
				if(nextEven>m)
				{
					cout<<-1;
					return 0;
				}
				ans++;
				countEven++;
				a[i]=nextEven;
				nextEven+=2;
			}
			else
			{
				while(s.find(nextOdd)!=s.end())
				{
					nextOdd+=2;
				}
				if(nextOdd>m)
				{
					cout<<-1;
					return 0;
				}
				ans++;
				countOdd++;
				a[i]=nextOdd;
				nextOdd+=2;	
			}
		}
	}
	if(countEven>countOdd)
	{
		for(int i=0;i<n && countEven>countOdd;i++)
		{
			if(a[i]%2==0)
			{
				while(s.find(nextOdd)!=s.end())
				{
					nextOdd+=2;
				}
				if(nextOdd>m)
				{
					cout<<-1;
					return 0;
				}
				ans++;
				countOdd++;
				countEven--;
				a[i]=nextOdd;
				nextOdd+=2;	
			}
		}
	}
	else if(countEven<countOdd)
	{
		for(int i=0;i<n && countEven<countOdd;i++)
		{
			if(a[i]%2==1)
			{
				while(s.find(nextEven)!=s.end())
				{
					nextEven+=2;
				}
				if(nextEven>m)
				{
					cout<<-1;
					return 0;
				}
				ans++;
				countEven++;
				countOdd--;
				a[i]=nextEven;
				nextEven+=2;
			}
		}
	}

	printf("%d\n", ans);
	for(int i=0;i<n;i++)
		printf("%d ", a[i]);
}