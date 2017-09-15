//AC
#include "bits/stdc++.h"
using namespace std;

long long int dp[61][61];
int vis[61][61];
int curTest=0;
string st;

long long int solve(int s,int e)
{
  if(s>e)
  {
    vis[s][e]=curTest;
    return dp[s][e]=0;
  }
  if(s==e)
  {
    vis[s][e]=curTest;
    return dp[s][e]=1;
  }
  if(vis[s][e]==curTest)
  {
    return dp[s][e];
  }
  vis[s][e]=curTest;

  long long int ans=1;
  for(int en=s+1;en<=e;en++)
  {
    if(st[s]==st[en])
    {
      ans+=1+solve(s+1,en-1);
    }
  }
  return dp[s][e]=ans+solve(s+1,e);
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
    curTest++;
    cin>>st;
    cout<<solve(0,st.size()-1)<<endl;
  }
}