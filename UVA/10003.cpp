//AC

#include "bits/stdc++.h"
using namespace std;

std::vector<int> cuts;
int dp[52][52][52];
int vis[52][52][52];
int curTest=0;
int solve(int s,int e,int c)
{
  if(vis[s][e][c]==curTest)
    return dp[s][e][c];

  vis[s][e][c]=curTest;
  
  if(e-s==2)
  {
    return dp[s][e][c]=cuts[e]-cuts[s];
  }
  
  if(e-s<=1)
  {
    return dp[s][e][c]=0;
  }

  if(c==e-1)
  {
    return dp[s][e][c]=cuts[e]-cuts[s]+solve(s,c,s+1)+solve(c,e,c+1);
  }

  return dp[s][e][c]=min(cuts[e]-cuts[s]+solve(s,c,s+1)+solve(c,e,c+1),solve(s,e,c+1));

}
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int l,n;
  cin>>l;
  while(l!=0)
  {
    curTest++;
    cin>>n;
    cuts=std::vector<int> (n+2);
    for(int i=1;i<=n;i++)
      cin>>cuts[i];
    cuts[0]=0;
    cuts[n+1]=l;
    printf("The minimum cutting is %d.\n", solve(0,n+1,1));
    cin>>l;
  }
}