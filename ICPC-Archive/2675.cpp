//AC
#include "bits/stdc++.h"
using namespace std;
int dp[101][100001]={};
int vis[101][100001]={};

int curTest=0;
std::vector<pair<int,int> > pearls;
int n;
int solve(int in=0,int q=pearls[0].first)
{
  // cout<<in<<" "<<q<<endl;
  if(vis[in][q]==curTest)
  {
    return dp[in][q];
  }
  vis[in][q]=curTest;
  if(in==n-1)
  {
    //must pay here
    return dp[in][q]=(q+10)*pearls[in].second;
  }
  return dp[in][q]=min(solve(in+1,q+pearls[in+1].first),
            ((q+10)*pearls[in].second)+solve(in+1,pearls[in+1].first));
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
    cin>>n;
    curTest++;
    pearls=std::vector<pair<int,int> > (n);
    for(int i=0;i<n;i++)
    {
      cin>>pearls[i].first>>pearls[i].second;
      // cout<<pearls[i].first<<" "?<<pearls[i].second<<endl;
    }
    printf("%d\n",solve());
  } 
}