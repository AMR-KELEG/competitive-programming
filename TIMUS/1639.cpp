/* AC
- Basic Sprague Grunde 
*/
#include "bits/stdc++.h"
using namespace std;
int dp[51][51];

int solve(int n,int m)
{
	if (n<m)
		swap(n,m);
	if (m==1 && n==1)
		return 0;
	if (dp[n][m]!=-1)
		return dp[n][m];
	set<int> gr;
	for (int r=1;r<=floor(n/2.0);r++)
	{
		gr.insert(solve(r,m)^solve(n-r,m));
	}
	for (int r=1;r<=floor(m/2.0);r++)
	{
		if (m-r==0)
			continue;
		gr.insert(solve(n,r)^solve(n,m-r));
	}
	for (int i=0;i<10000;i++)
	{
		if (gr.find(i)==gr.end())
			return dp[n][m] = i;
	}

}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(dp,-1,sizeof dp);
	int n,m;
	scanf("%d %d",&n,&m);
	if(solve(n,m))
		printf("[:=[first]");
	else
		printf("[second]=:]");
}