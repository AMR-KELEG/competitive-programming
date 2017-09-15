//AC
#include "bits/stdc++.h"
using namespace std;

string s;
string dp[1001][1001];
int vis[1001][1001];
int t=0;

string solve(int l,int r)
{
	if(l>r)
	{
		return "";
	}
	if(l==r)
	{
		return dp[l][r]=s[l];
	}
	if(vis[l][r]==t)
	{
		return dp[l][r];
	}
	vis[l][r]=t;
	if(s[l]==s[r])
	{
		return dp[l][r]=s[l]+solve(l+1,r-1)+s[r];
	}

	string ans1=solve(l+1,r);
	string ans2=solve(l,r-1);
	if(ans1.size()>ans2.size())
	{
		return dp[l][r]=ans1;
	}
	else if(ans1.size()<ans2.size())
	{
		return dp[l][r]=ans2;
	}
	else
	{
		return dp[l][r]=min(ans2,ans1);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	while(cin>>s)
	{
		t++;
		cout<<solve(0,s.size()-1)<<endl;
	}
}