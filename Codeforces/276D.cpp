//AC
#include "bits/stdc++.h"
using namespace std;
string L,R;
long long dp[64][2][2][2][2];

void tobin(long long int i,string & s)
{
  while(i>0)
  {
    s=char('0'+(i%2))+s;
    i/=2;
  }
  s=string(64-s.size(),'0')+s;
}


long long int solve(int in=0,bool l1=0,bool l2=0,bool r1=0,bool r2=0)
{
  if(in==64)
    return 0;

  if(dp[in][l1][l2][r1][r2]!=-1)
    return dp[in][l1][l2][r1][r2];

  int min1=0,max1=1,min2=0,max2=1;
  if(l1)
  {
    min1=0;
  }
  else
  {
    min1=L[in]-'0';
  }
  if(l2)
  {
    max1=1;
  }
  else
  {
    max1=R[in]-'0';
  }

  if(l2)
  {
    min2=0;
  }
  else
  {
    min2=L[in]-'0';
  }
  if(l2)
  {
    max2=1;
  }
  else
  {
    max2=R[in]-'0';
  }

  long long ans=0;
  for(long long a=min1;a<=max1;a++)
  {
    for(long long b=min2;b<=max2;b++)
    {
      ans=max(ans,(a^b)<<(63-in) | solve(in+1,l1|| L[in]-'0'!=a,l2|| R[in]-'0'>a,r1|| L[in]-'0'!=b,r2|| R[in]-'0'>b));
    }
  }

  return dp[in][l1][l2][r1][r2]=ans;
}

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  long long int l,r;
  cin>>l>>r;
  tobin(l,L);
  tobin(r,R);
  memset(dp,-1,sizeof dp);
  cout<<solve();
}