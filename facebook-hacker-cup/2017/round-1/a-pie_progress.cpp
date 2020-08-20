#include "bits/stdc++.h"
#define INF (1000000000000000LL)
using namespace std;
int n,m;
int cost[301][301];//Day Cost
long long int dp[301][301];//Day Cur
int vis[301][301];
int t;
long long int solve(int day=0,int cur=0)
{
  if(cur<0)
    return INF;
  if(day==n)
    return 0;
  //Rem=n-day
  if(cur>=n-day)
    return 0;
  if(vis[day][cur]==t)
    return dp[day][cur];
  vis[day][cur]=t;
  long long int ans=solve(day+1,cur-1);
  long long int curCost=0;
  for(int i=0;i<m;i++)
  {
    //take cost[day][i] -- taken=i+1
    curCost+=cost[day][i];
    ans=min(ans,((i+1)*(i+1))+curCost+solve(day+1,cur+i));
  }
  return dp[day][cur]=ans;
}

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int T;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    cin>>n>>m; 
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
        cin>>cost[i][j];
      sort(cost[i],cost[i]+m);
    }
    cout<<"Case #"<<t<<": "<<solve()<<endl;
  }
}