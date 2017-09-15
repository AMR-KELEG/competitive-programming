#include "bits/stdc++.h"
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int n,m;
	string s;
	cin>>n>>m;
	std::vector<set<int>> ch(m);
	for(int i=0;i<n;i++)
	{
		cin>>s;
		for(int j=0;j<m;j++)
			ch[j].insert(s[j]);
	}	
	long long int sol=1;
	for(int i=0;i<m;i++)
	{
		sol=sol*ch[i].size();
		sol=sol%(1000000007);
	}
	cout<<sol;
}