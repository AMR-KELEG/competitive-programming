#include "bits/stdc++.h"
const int INF = 18*201;
const int OFF = 64*200;
using namespace std;
std::vector<int> c2,c5;
int dp[200][OFF + (25*200)];
int solve(int rem,int indx =0, int count= OFF)
{
	return 0;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(dp,-1,sizeof dp);
	int n,k;
	c2 = std::vector<int> (n,0);
	c5 = std::vector<int> (n,0);
	long long int no;
	for(int i=0;i<n;i++)
	{
		cin>>no;
		while(no%5==0)
		{
			c5[i]++;
			no/=5;
		}
		while(no%2==0)
		{
			c2[i]++;
			no/=2;
		}
	}
	cout<<solve(k);
}