//AC
#include "bits/stdc++.h"
using namespace std;
short dp[2001][2001];//rem - maxToTake
// 1 is N player Wins - 0 is P player Wins

short solve(int rem,int lastPlay)
{
	if(rem==0)
		return 0;
	if(rem==1)
		return 1;
	if(dp[rem][lastPlay]!=-1)
		return dp[rem][lastPlay];
	for(int take=1;take<=min(2*lastPlay,rem);take++)
	{
		if(!solve(rem-take,min(rem-take,take)))
		{
			return dp[rem][lastPlay]=1;
		}
	}
	return dp[rem][lastPlay]=0;
}
int main()
{	
	memset(dp,-1,sizeof dp);

	for(int n=2;n<=2000;n++)
	{
		bool allwin=1;
		for(int fs=1;fs<=n-1;fs++)
		{
			//All these position should be winning
			if(!solve(n-fs,min(fs,n-fs)))
			{
				allwin=0;
				break;
			}
		}
		if(allwin)
			cout<<n<<endl;
	}
	return 0;
}