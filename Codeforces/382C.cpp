#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	std::vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(), a.end());
	map<int,int>diff;
	for(int i=1;i<n;i++)
	{
		diff[a[i]-a[i-1]]++;
	}	
	if(diff.size()==0)
	{
		cout<<"-1";
	}
	else if(diff.size()==1)
	{
		if(a[0]==a[n-1])
		{
			cout<<1<<endl<<a[0];
		}
		else if(n==2 && (a[n-1]-a[0])%2==0)
		{
			cout<<3<<endl<<a[0]-(a[1]-a[0])<<" "<<a[0]+((a[1]-a[0])/2) <<" "<<a[n-1]+(a[1]-a[0]);
		}
		else
		{
			cout<<2<<endl<<a[0]-(a[1]-a[0])<<" "<<a[n-1]+(a[1]-a[0]);	
		}
	}
	else if(diff.size()==2)
	{
		map<int,int>::iterator it=diff.begin();
		int smdiff=(*it).first;
		it++;
		int bigdiff=(*it).first,bigc=(*it).second;
		if(bigdiff==(2*smdiff) && bigc==1)
		{
			cout<<1<<endl;
			for(int i=1;i<n;i++)
			{
				if(a[i]-a[i-1]==bigdiff)
				{
					cout<<a[i-1]+smdiff;
					break;
				}
			}
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
}