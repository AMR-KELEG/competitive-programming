//AC
#include "bits/stdc++.h"
#define INF (100*11)
using namespace std;
int dp[2048][11]={};
int cur[2048][11]={};
int testCase=1;
short val[11][11];
short solve(int mask=0,int indx=0)
{
	if(indx==11)
		return 0;
	if(cur[mask][indx]==testCase)
		return dp[mask][indx];
	cur[mask][indx]=testCase;
	int ans=-INF;
	for(int i=0;i<11;i++)
	{
		if(val[indx][i]>0 && (((mask>>i) & (1))==0))
			ans=max(ans,val[indx][i]+solve(mask | (1<<i),indx+1));
	}
	return dp[mask][indx]=ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<11;i++)
		{
			for(int j=0;j<11;j++)
				cin>>val[i][j];
		}
		cout<<solve()<<endl;
		testCase++;
	}	
}