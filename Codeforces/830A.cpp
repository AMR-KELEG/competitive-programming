//AC
#include "bits/stdc++.h"
#define INF 1000000000000000000LL
using namespace std;
int n,k,p;
std::vector<int> per;
std::vector<int> key;
long long int dp[1000][2000];//per key

long long int solve(int pe=0,int ke=0)
{
	if(pe==n)
		return 0;
	if(ke==k)
		return INF;
	if(dp[pe][ke]!=-1)
		return dp[pe][ke];
	long long int sol = abs(per[pe]-key[ke])+abs(p-key[ke]);
	sol = max(sol,solve(pe+1,ke+1));
	long long int sol2=solve(pe,ke+1);
	sol=min(sol,INF);
	sol2=min(sol2,INF);
	if(sol==sol2 && sol2==INF)
		return dp[pe][ke]=INF;
	if(sol<sol2)
		return dp[pe][ke]=sol;
	return dp[pe][ke]=sol2;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>k>>p;
	per=std::vector<int> (n);
	key=std::vector<int> (k);
	memset(dp,-1,sizeof dp);
	for(int i=0;i<n;i++)cin>>per[i];
	for(int i=0;i<k;i++)cin>>key[i];
	sort(key.begin(), key.end());
	sort(per.begin(), per.end());
	cout<<solve();
}