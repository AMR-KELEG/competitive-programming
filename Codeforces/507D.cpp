//AC
#include <bits/stdc++.h>
using namespace std;
int n,k,m;
long long int dp[1001][2][101]={};
long long int powMod(int p,int mod)
{
	if(p==0)
		return 1;
	if(p==1)
		return 10;
	long long int ans=powMod(p>>1,mod);
	ans=(ans*ans)%mod;
	if(p%2)
		ans=(ans*10)%mod;
	return ans;
}

long long int solve(int indx,bool allZ,int curMod,int curMul)
{
	if(indx==n)
		return 0;
	if(dp[indx][allZ][curMod]!=-1)
		return dp[indx][allZ][curMod];
	long long int ans=0;
	for (int i=0;i<10;i++)
	{
		int mod=((curMod)+(curMul*i))%k;
		if(mod==0 && (!allZ || i>0))
		{
			// Add answer
			if(indx==n-1)
				ans=(ans+1)%m;
			else
				ans=(ans+9*powMod(n-indx-2,m))%m;
		}
		else
			ans=(ans+solve(indx+1,allZ && i==0,mod,(curMul*10)%k))%m;
	}
	return dp[indx][allZ][curMod]=ans;
}
int main()
{
	memset(dp,-1,sizeof dp);
	cin>>n>>k>>m;
	cout<<solve(0,1,0,1);
}
