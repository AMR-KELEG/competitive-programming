//AC
#include "bits/stdc++.h"
using namespace std;
long double dp[9000001]={};
bool vis[9000001]={};
long double solve(int inv)
{
	if(inv==0)
		return 0;
	if(inv==1)
		return 1;
	if(vis[inv])
		return dp[inv];
	vis[inv]=1;
	return dp[inv]=4+solve(inv-2);
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	std::vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	int inv=0;	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
			if(v[j]<v[i])
				inv++;
	}
	cout<<fixed<<setprecision(9)<<solve(inv);
}