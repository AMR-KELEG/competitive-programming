//AC
#include "bits/stdc++.h"
using namespace std;
long long int dp[5002][5001];// in remsectors

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int n,m,k;
  cin>>n>>m>>k;
  long long int cs[5002]={};
  int no;
  for(int i=1;i<=n;i++)
  {
    cin>>no;
    cs[i]=cs[i-1]+no;
    // cout<<i<<" "<<no<<endl;
  }    

  for(int in=n;in>0;in--)
  {
    for(int r=k;r>0;r--)
    {
      if(in+1<=n && in+m<=n)
      {
        // cout<<"Fir\n";
        dp[in][r]=max(dp[in+m][r-1]+cs[in+m-1]-cs[in-1],dp[in+1][r]);
      }
      else if(in+m<=n)
      {
        // cout<<"Second\n";
        dp[in][r]=dp[in+m][r-1]+cs[in+m-1]-cs[in-1];
      }
      else if(in+m-1==n)
      {
        // cout<<"Third\n";
        dp[in][r]=cs[in+m-1]-cs[in-1];
      }
      else if(in+1<=n)
      {
        // cout<<"Four\n";
        dp[in][r]=dp[in+1][r];
      }
      // cout<<in<<" "<<r<<" "<<dp[in][r]<<" "<<endl;
    }
  }

  cout<<dp[1][k]; 
}