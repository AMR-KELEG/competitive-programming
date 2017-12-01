// 80% AC - A2OJ is Down
#include "bits/stdc++.h"
using namespace std;
int x;
string h,s;
long long int dp[5000][2];
int vis[5000][2];
int t=1;
long long int solve(int indx = 0, bool s_done = 0)
{
	if (indx > h.size())
		return 0;
	if (indx == h.size())
	{
		return s_done;
	}
	if (vis[indx][s_done] == t)
		return dp[indx][s_done];
	vis[indx][s_done] = t;
	if (s_done)
		return dp[indx][s_done]=1;
	if (indx + x + s.size() > h.size())
		return dp[indx][s_done] = 0;
	long long int ans = solve(indx+1, 0);
	bool valid = 1;
	for (int i=indx+x,j=0;i<indx+x+s.size();i++,j++)
	{
		if (h[i] != s[j])
		{
			valid = 0;
			break;
		}
	}
	if (valid)	
		ans++;
	
	for (int j=0;j<s.size();j++)
	{
		// skip j then put x then compare
		if (s[j] != h[indx+j])
		{
			break;
		}
		valid = 1;
		// rem is from j+1 -> s.size()
		// h from j+1+indx+x 
		for (int i=j+1,k = j+1+indx+x;i<s.size();i++,k++)
		{
			if (s[i] != h[k])
			{
				valid=0;
				break;
			}
		}
		if (valid)
			ans++;
	}
	return dp[indx][s_done] = ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while(T--)
	{
		cin>>x;
		cin>>h>>s;
		if (x+s.size()>h.size())
			cout<<0<<"\n";
		else
		{
			cout<<solve()<<"\n";
		}
		t++;
	}
}