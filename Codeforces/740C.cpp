//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	// std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	std::vector<pair<int,int>> ranges(m);
	int minLen=n;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&ranges[i].first,&ranges[i].second);
		minLen=min(minLen,1+ranges[i].second-ranges[i].first);
	}
	printf("%d\n", minLen);
	int curVal=0;
	for(int i=0;i<n;i++)
	{
		printf("%d ", curVal);
		curVal++;
		curVal%=minLen;
	}
}