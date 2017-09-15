#include "bits/stdc++.h"
#define MOD 1000000007
#define shift 210000
using namespace std;
// int dp[400000][100];
// int solve(int score,int remTurns)
// {
// 	// cout<<score<<" "<<remTurns<<endl;
// 	if(remTurns==0)
// 		return (score-shift)>0;
// 	if(dp[score][remTurns]!=-1)
// 		return dp[score][remTurns];
// 	if(score+(2*k*remTurns)<=shift)
// 		return dp[score][remTurns]=0;
// 	if(score-(2*k*remTurns)>shift)
// 		return dp[score][remTurns]=0;
// 	int ans=0;
// 	int count=1;
// 	for(int add=-2*k;add<=0;add++)
// 	{
// 		// cout<<count<<" "<<add<<endl;
// 		ans+=((count%MOD)*(solve(score+add,remTurns-1)%MOD))%MOD;
// 		ans=ans%MOD;
// 		count++;
// 		count%=MOD;
// 	}
// 	count-=2;
// 	for(int add=1;add<=2*k;add++)
// 	{
// 		// cout<<count<<" "<<add<<endl;
// 		ans+=((count%MOD)*(solve(score+add,remTurns-1)%MOD))%MOD;
// 		ans=ans%MOD;
// 		count--;
// 		count%=MOD;
// 	}
// 	return dp[score][remTurns]=ans%MOD;
// }

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int a,b,t;
	int k;
	cin>>a>>b>>k>>t;
	// memset(dp,-1,sizeof dp);
	// cout<<solve((a-b+shift),t);
	std::vector<int> count(40*k,0);
	std::vector<int> fcount(40*k,0);
	std::vector<int> ffcount(40*k,0);

	for(int f=-k;f<=k;f++)
	{
		for(int s=-k;s<=k;s++)
		{
			count[(8*k)+(f-s)]++;	
		}
	}

	for(int f=-2*k;f<=2*k;f++)
	{
		for(int s=-2*k;s<=2*k;s++)
		{
			fcount[(8*k)+(f-s)]+=count[(8*k)+f]*count[(8*k)+s];	
		}
	}

	for(int f=-4*k;f<=4*k;f++)
	{
		for(int s=-4*k;s<=4*k;s++)
		{
			ffcount[(8*k)+(f-s)]+=fcount[(8*k)+f]*fcount[(8*k)+s];	
		}
	}
	for(int i=-8*k;i<=8*k;i++)
		cout<<i<<" "<<ffcount[i+(8*k)]<<endl;
}