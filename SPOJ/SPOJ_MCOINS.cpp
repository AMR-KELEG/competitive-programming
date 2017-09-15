//AC
#include "bits/stdc++.h"
using namespace std;
char dp[1000001]={};
std::vector<int> rem;
char solve(int n)
{
	// cout<<n<<endl;
	if(n==0)
		return 'p';
	if(dp[n]!=0)
		return dp[n];
	for(int i=0;i<3;i++)
	{
		if(n>=rem[i])
		{
			if(solve(n-rem[i])=='p')
				return dp[n]='n';
		}
	}
	return dp[n]='p';
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int k,l,m;
	cin>>k>>l>>m;
	rem=std::vector<int> (3,1);
	rem[0]=max(k,l);
	rem[1]=min(k,l);
	string ans(m,' ');
	for(int i=0;i<m;i++)
	{
		int n;
		cin>>n;
		if(solve(n)=='n')
		{
			ans[i]='A';
		}
		else
			ans[i]='B';
	}
	cout<<ans;	
}