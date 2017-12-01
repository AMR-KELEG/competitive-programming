// AC
// 6:44 -> DONE
#include "bits/stdc++.h"
using namespace std;
string s;
int t=1;
int dp[1000][1000];
int vis[1000][1000];
int solve(int st,int en)
{
	if (st==en)
		return 0;
	if (st>en)
		return 0;
	if (vis[st][en] == t)
		return dp[st][en];
	vis[st][en] = t;
	if (s[st]==s[en])
		return dp[st][en] = solve(st+1,en-1);
	return dp[st][en] = 1 + min(solve(st+1,en),solve(st,en-1));
}
stack<char> ans;
void get_output(int st,int en)
{
	if (st==en)
	{
		printf("%c", s[st]);
		return ;
	}
	if (st>en)
		return ;
	if (s[st]==s[en])
	{
		ans.push(s[st]);
		printf("%c", s[st]);
		get_output(st+1,en-1);
		return ;
	}
	if (solve(st+1,en)< solve(st,en-1))
	{
		ans.push(s[st]);
		printf("%c",s[st]);
		get_output(st+1,en);
	}
	else
	{
		ans.push(s[en]);
		printf("%c",s[en]);
		get_output(st,en-1);
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
		printf("%d ", solve(0,s.size()-1));
		get_output(0,s.size()-1);
		while(!ans.empty())
		{
			printf("%c", ans.top());
			ans.pop();
		}
		printf("\n");
		t++;
	}	
}