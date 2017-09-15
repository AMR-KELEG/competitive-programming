//AC
#include "bits/stdc++.h"
using namespace std;
unsigned long long int dp[100][70];
unsigned long long int solve(int n,int b)
{
	if(n==1)
		return 1;
	if(n<=0)
		return 1;
	if(dp[n][b]!=0)
		return dp[n][b];
	unsigned long long int c=1;
	for(int i=1;i<=b;i++)
		c+=solve(n-i,b);
	return dp[n][b]=c;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(dp,0,sizeof dp);
	int n,b;
	cin>>n>>b;
	int t=0;
	while(n<=60)
	{
		t++;
		cout<<"Case "<<t<<": "<<solve(n,b)<<endl;
		cin>>n>>b;
	}
}