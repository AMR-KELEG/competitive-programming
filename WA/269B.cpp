#include <bits/stdc++.h>
using namespace std;
int n,m;
int dp[5001][5001]; // ValidPos-indxOfBar
int dead[5001][5001]={}; // CurPos- type
int type[5001];

int solve(int pos,int indx)
{
	if(indx==m)
	{
		return 0;
	}

	if(pos==n)
	{
		return 0;
	}

	if(dp[pos][indx]!=-1)
		return dp[pos][indx];

	return dp[pos][indx]=min(
	min(solve(pos,indx+1)+dead[pos][indx]+(type[pos]==indx)
	,solve(pos+1,indx)+(type[pos]>indx))
	,
	solve(pos+1,indx+1)+dead[pos][indx]+(type[pos]>indx)
	);
}
int main()
{
	cin>>n>>m;
	float x;
	for(int i=0;i<n;i++)
	{
		cin>>type[i]>>x;
		type[i]--;
	}
	for(int i=n-1;i>0;i--)
	{
		for(int t=0;t<m;t++)
		{
			dead[i-1][t]=dead[i][t];
		}
		dead[i-1][type[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		for(int t=0;t<m;t++)
		{
			//cout<<"Dead after "<<i<<" of color "<<t+1<<
			//" are "<<dead[i][t]<<endl;
		}
	}
	memset(dp,-1,sizeof dp);
	cout<<solve(0,0);
}
