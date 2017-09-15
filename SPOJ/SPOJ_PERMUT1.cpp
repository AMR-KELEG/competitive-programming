#include "bits/stdc++.h"
using namespace std;
int n,k;
long long int dp[5000][50];//2^12 - inv
long long int solve(int taken,int inv)
{
	// cout<<taken<<" "<<inv<<endl;
	if(dp[taken][inv]!=-1)
		return dp[taken][inv];
	long long ans=0;
	if(taken+1==(ceil(pow(2LL,n))) )
	{
		if(inv==k)
			return 1LL;
		return 0;
	}
	// loop on taken bits 
	int incinv=0;
	for(int sh=0;sh<n;sh++)
	{
		if(( (taken>>sh) & 1 )==0)
		{
			//sh not taken
			ans+=solve(taken | (1<<sh),inv+incinv);
			incinv++;
		}
	}
	return dp[taken][inv]=ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int d;
	cin>>d;
	while(d--)
	{
		memset(dp,-1,sizeof dp);
		cin>>n>>k;
		cout<<solve(0,0)<<endl;
	}	
}