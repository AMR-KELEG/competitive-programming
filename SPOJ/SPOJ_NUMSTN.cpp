#include "bits/stdc++.h"
#define MOD 1000000007
using namespace std;

string s1,s2;

long long int dp[51][2][2][17][17][17];// in 
int vis[51][2][2][17][17][17];
int curTest=0;
long long int solve(int in=0,bool l=0,bool r=0,short c3=0,short c6=0,short c9=0)
{
  if(c3>16 || c6>16 || c9>16)
    return 0;
  if(in==51)
  {
    if(c3>0 && c3==c6 && c6==c9)
    {
      return 1;
    }
    return 0;
  }
  if(vis[in][l][r][c3][c6][c9]==curTest)
  {
    return dp[in][l][r][c3][c6][c9];
  } 

  vis[in][l][r][c3][c6][c9]=curTest;
  int minv=s1[in]-'0';
  int maxv=s2[in]-'0';
  if(l)
  {
    minv=0;
  }
  if(r)
  {
    maxv=9;
  }
  
  long long int ans=0;
  for(int i=minv;i<=maxv;i++)
  {
    ans+=(solve(in+1,l || i>(s1[in]-'0'),r || i<(s2[in]-'0'),c3+(i==3),c6+(i==6),c9+(i==9))%MOD);
    ans%=MOD;
  }

  return dp[in][l][r][c3][c6][c9]=(ans%MOD);
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
    cin>>s1>>s2;
    s1=string(51-(s1.size()),'0')+s1;
    s2=string(51-(s2.size()),'0')+s2;
    cout<<solve()<<endl;
  } 
}