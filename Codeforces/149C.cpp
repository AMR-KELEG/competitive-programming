//AC
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
	std::vector<pair<int,int> > a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i].first;
		a[i].second=i+1;
	}
	sort(a.begin(), a.end());
	long long int fts=0,sts=0;
	std::vector<int> f,s;
	for(int i=0;i<(n/2)*2;i+=2)
	{
		if(fts>sts)
		{
			fts+=a[i].first;
			sts+=a[i+1].first;
			f.push_back(a[i].second);
			s.push_back(a[i+1].second);
		}
		else
		{
			fts+=a[i+1].first;
			sts+=a[i].first;
			f.push_back(a[i+1].second);
			s.push_back(a[i].second);
		}
		}
	if(n%2)
	{
		//odd
		if(fts<sts)
		{
			fts+=a[n-1].first;
			
			f.push_back(a[n-1].second);
			
		}
		else
		{
			sts+=a[n-1].first;
			
			s.push_back(a[n-1].second);	
		}
	}
	cout<<f.size()<<endl;
	for(int i=0;i<f.size();i++)
		cout<<f[i]<<" ";
	cout<<endl<<s.size()<<endl;
	for(int i=0;i<s.size();i++)
		cout<<s[i]<<" ";
}