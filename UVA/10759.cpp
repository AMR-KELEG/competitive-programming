//AC
#include "bits/stdc++.h"
using namespace std;
long long int dp[25][150];
long long int solve(int n,int x)
{
	if(x<0)
		return 0;
	if(n==0)
		if(x==0)
			return dp[n][x]=1;
		else
			return dp[n][x]=0;
	if(dp[n][x]!=-1)
		return dp[n][x];
	long long int ans=0;
	for(int rem=1;rem<7;rem++)
	{
		ans+=solve(n-1,x-rem);
	}
	return dp[n][x]=ans;
}
int main()
{
	memset(dp,-1,sizeof dp);
	long long int n,x;
	cin>>n>>x;
	while(n!=0 || x!=0)
	{
		long long int num=0;
		for(int sum=x;sum<150;sum++)
			num+=solve(n,sum);
		long long int den=ceil(pow(6LL,n));
		long long int GCD=__gcd(num,den);
		num/=GCD;
		den/=GCD;
		if(num==0)
			cout<<0<<endl;
		else if(den==1)
			cout<<1<<endl;
		else
			cout<<num<<"/"<<den<<endl;
		cin>>n>>x;
	}
}