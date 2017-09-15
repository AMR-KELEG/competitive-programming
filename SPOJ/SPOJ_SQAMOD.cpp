//AC - Problem is hidden
#include "bits/stdc++.h"
using namespace std;
string n;
int start;
int dp[10005][2][3];
int solve(int in,bool takeall=0,int s=0)
{
	// cout<<in<<endl;
	if(in==10001)
		return s==0 && takeall;
	if(dp[in][takeall][s]!=-1)
		return dp[in][takeall][s];
	int ans=0;
	if(takeall)
	{
		for(int i=0;i<10;i++)
		{
			ans+=solve(in+1,takeall,((i*i)+s)%3);
		}
		return dp[in][takeall][s]=ans;
	}
	for(int i=0;i<n[in]-'0';i++)
	{
		ans+=solve(in+1,1,((i*i)+s)%3);
	}
	int i=n[in]-'0';
	ans+=solve(in+1,0,((i*i)+s)%3);
	return dp[in][takeall][s]=ans;
}
int main()
{
	#ifndef DONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;cin>>t;
	while(t--)
	{
		cin>>n;
		start=10000-(n.size()-1);
		// cout<<n<<" "<<start<<endl;
		n=string(10001-(n.size()),'0')+n;
		memset(dp,-1,sizeof dp);
		cout<<solve(start)<<endl;
	}
}