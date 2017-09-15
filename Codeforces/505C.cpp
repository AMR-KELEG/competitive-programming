#include "bits/stdc++.h"
using namespace std;
short dp[30005][700];
short gem[30005]={};
int n,d;
long long int findmax(int in,int offset)
{
	if(in>30000)
	{
		return 0;
	}
	if(dp[in][300+offset]!=-1)
		return dp[in][300+offset];
	if(d+offset==1)
		return dp[in][300+offset]=gem[in]+max(findmax(in+d+1,offset),findmax(in+d+1,offset));	
	return dp[in][300+offset]=gem[in]
	+max(max(findmax(in+d+offset,offset),findmax(in+d+offset-1,offset-1)),findmax(in+d+offset+1,offset+1));
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(dp,-1,sizeof dp);
	cin>>n>>d;
	int gem_i;
	for(int i=1;i<=n;i++)
	{
		cin>>gem_i;
		gem[gem_i]++;
	}
	cout<<gem[0]+findmax(d,0);	
}