//AC
#include "bits/stdc++.h"
#define INF 1000000007
using namespace std;
string s;
int dp[1000][1000];
int vis[1000][1000];
int t=1;
int solve(int st,int en)
{
	if (st>en)
		return 0;
	if (st==en)
		return 0;
	if (vis[st][en] == t)
		return dp[st][en];
	vis[st][en] = t;
	
	if (s[st]==s[en])
		return dp[st][en]= solve(st+1,en-1);
	return dp[st][en]= 1+min(min(solve(st,en-1),solve(st+1,en-1)),solve(st+1,en));
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while(t<=T)
	{
		cin>>s;
		int ans =0;
		if (s.size()==0)
		{
			ans = 0;
		}
		else
		{
			ans = solve(0,s.size()-1);
		}

		cout<<"Case "<<t<<": "<<ans<<endl;
		t++;
	}
}