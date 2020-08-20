#include "bits/stdc++.h"
#define INF (100000000000000LL)
using namespace std;
/*
  For each case, there is first a line containing three space-separated integers, N, M, and K.
  Then, M lines follow, the ith of which contains 3 space-separated integers, Ai, Bi, and Gi.
  Then, K lines follow, the ith of which contains 2 space-separated integers, Si and Di.
  1 ≤ T ≤ 100 
  2 ≤ N ≤ 100 
  1 ≤ M ≤ 5,000 
  1 ≤ K ≤ 5,000 
  1 ≤ Ai, Bi ≤ N, Ai ≠ Bi 
  1 ≤ Si, Di ≤ N, Si ≠ Di 
  1 ≤ Gi ≤ 1,000 
*/
int n,m,k;
short src[5001];
short des[5001];
long long int dis[101][101]={};
long long int dp[5001][101][2];
short vis[5001][101][2];
short t;

long long int solve(short node_in=0,short node=1,bool alreadyTaken=0)
{
  //Go to des then to src of next
  //Go to src of next then des of alreadyTaken then src of next
  //Go to src of next then des of alreadyTaken then des of next then src of next
  if(node_in==k)
    return 0;
  if(vis[node_in][node][alreadyTaken]==t)
  {
    return dp[node_in][node][alreadyTaken]; 
  }
  vis[node_in][node][alreadyTaken]=t;
  if(node_in==k-1)
  {
    if(!alreadyTaken)
    {
      return dp[node_in][node][alreadyTaken]=dis[node][src[node_in]]+
             dis[src[node_in]][des[node_in]];  
    }
    return dp[node_in][node][alreadyTaken]=dis[node][des[node_in]];
  }
  long long int ans=INF;
  if(!alreadyTaken)
  {
    long long int curAns=dis[node][src[node_in]];
    //Either go to des and solve
    ans=min(ans,curAns+dis[src[node_in]][des[node_in]]+solve(node_in+1,des[node_in],0));
    //Go to src of next then des
    curAns+=dis[src[node_in]][src[node_in+1]];
    curAns+=dis[src[node_in+1]][des[node_in]];
    curAns+=solve(node_in+1,des[node_in],1);
    ans=min(ans,curAns);
  }
  else
  {
    //already taken
    long long int curAns=0;
    //Either go to des and solve
    ans=min(ans,curAns+dis[node][des[node_in]]+solve(node_in+1,des[node_in],0));
    //Go to src of next then des
    curAns+=dis[node][src[node_in+1]];
    curAns+=dis[src[node_in+1]][des[node_in]];
    curAns+=solve(node_in+1,des[node_in],1);
    ans=min(ans,curAns);
  }
  if(ans>=INF)
    ans=INF;
  return dp[node_in][node][alreadyTaken]=ans;
}
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("manic_moving.txt","r",stdin);
    freopen("manic_moving_ans.txt","w",stdout);
  #endif
  int T;
  cin>>T;
  int a,b;
  long long int g;
  for(t=1;t<=T;t++)
  {
    for(int i=0;i<101;i++)
    {
      for(int j=0;j<101;j++)
      {
        if(i==j)
          dis[i][j]=0;
        else
          dis[i][j]=INF;
      }
    }
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
      cin>>a>>b>>g;
      dis[b][a]=dis[a][b]=min(dis[a][b],g);
    }
    for(int i=0;i<k;i++)
    {
      cin>>src[i]>>des[i];
    }
    for(int k=1;k<=n;k++)
    {
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
        {
          if(dis[i][j]>dis[i][k]+dis[k][j])
            dis[i][j]=dis[i][k]+dis[k][j];
        }
      }
    }
    long long int ans=solve();
    cout<<"Case #"<<t<<": ";
    if(ans>=INF)
      cout<<-1;
    else
      cout<<ans;
    cout<<endl;
  } 
}