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
	unordered_map<string,int> mp;
	mp["red"] = 1;
	mp["yellow"] = 2;	
	mp["green"] = 3;
	mp["brown"] = 4;
	mp["blue"] = 5;
	mp["pink"] = 6;
	mp["black"] = 7;
	int total = 0;
	int max_v = 0;
	int nr = 0;
	while(n--)
	{
		string s;
		cin>>s;
		total += mp[s];
		max_v = max(max_v, mp[s]);
		if (s=="red")
			nr++;
	}
	if (max_v ==1)
	{
		cout<<1;
	}
	else
	{
		cout<<total + max_v*nr;
	}
}