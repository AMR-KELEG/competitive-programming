//AC
#include "bits/stdc++.h"
#define MOD 1000000007LL
using namespace std;
int k;
int ways[100007]={};
int dp[100007];

int solve(int i)
{
  if(i<0)
    return 0;
  if(i==0)
    return 1;
  if(i==1)
  {
    if(k==1)
      return dp[i]=2;
    return dp[i]=1;
  }
  if(dp[i]!=-1)
    return dp[i];
  int ans=0;
  ans=solve(i-1);
  if(i>=k)
  {
    ans+=solve(i-k);
  }
  ans=ans%MOD;
  return dp[i]=ans;
}

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  memset(dp,-1,sizeof dp);  
  int t;
  cin>>t>>k;

  for(int i=1;i<100007;i++)
  {
    if(dp[i]==-1)
      solve(i);
  }
  for(int i=1;i<100007;i++)
  {
    ways[i]=ways[i-1]+dp[i];
    ways[i]%=MOD;
  }

  int a,b;
  for(int i=0;i<t;i++)
  {
    cin>>a>>b;
    if(ways[b]<ways[a-1])
    {
      printf("%d\n",int((ways[b]+MOD)-ways[a-1]));
    }
    else
    {
      printf("%d\n",ways[b]-ways[a-1]); 
    }
  }
}