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
	std::vector<pair<int,int> > p(n);
	for(int i=0;i<n;i++)
	{
		cin>>p[i].first>>p[i].second;
	}
	sort(p.begin(), p.end());
	long long int count=0;
	for(int i=0;i<n;)
	{
		int j;
		for(j=i+1;j<n;j++)
		{
			if(p[i].second>p[j].second)
			{
				count++;
			}
			else
			{
				break;
			}
		}
		i=j;
	}
	cout<<count;

}