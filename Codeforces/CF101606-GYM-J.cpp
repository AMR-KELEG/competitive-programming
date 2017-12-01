// AC
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
	map<int,int> mp;
	for (int i=0,c;i<n;i++)
	{
		cin>>c;
		mp[c]++;
	}	
	long double val = 0;
	for (auto it:mp)
	{
		if (it.first == 0)
		{
			val += 2*it.second;
		}
		else
		{
			val += (((long double)1.0)/it.first) * it.second;
		}
	}
	cout<<setprecision(9)<<fixed<<val;
	return 0;
}