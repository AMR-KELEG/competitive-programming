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
	int minEnd1=1000000001, maxStart1=0;
	for(int i=0;i<n;i++)
	{
		int s,e;
		cin>>s>>e;
		minEnd1=min(minEnd1,e);
		maxStart1=max(maxStart1,s);
	}
	int m;
	cin>>m;
	int minEnd2=1000000001, maxStart2=0;
	for(int i=0;i<m;i++)
	{
		int s,e;
		cin>>s>>e;
		minEnd2=min(minEnd2,e);
		maxStart2=max(maxStart2,s);
	}
	cout<<max(0,max(maxStart1-minEnd2,maxStart2-minEnd1));
}