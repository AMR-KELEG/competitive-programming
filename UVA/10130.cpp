//AC
#include "bits/stdc++.h"
using namespace std;
int dp[1005][35]; // n w
std::vector<int> pr,we;
long long int findans(int n,int w)
{
	if(n==0 || w<=0)
		return 0;
	if(dp[n][w]!=-1)
		return dp[n][w];
	if(w>=we[n])
		return dp[n][w]=max(pr[n]+findans(n-1,w-we[n]),findans(n-1,w));
	return dp[n][w]=findans(n-1,w);
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t,n,g,mw;
	long long int ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		pr.resize(n+5);
		we.resize(n+5);
		memset(dp,-1,sizeof dp);
		for(int i=1;i<=n;i++)
		{
			cin>>pr[i]>>we[i];
		}
		cin>>g;
		ans=0;
		while(g--)
		{
			cin>>mw;
			ans+=findans(n,mw);
		}
		cout<<ans<<endl;
	}	
}