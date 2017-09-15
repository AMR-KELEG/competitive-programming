//AC
#include "bits/stdc++.h"
using namespace std;
int ia,ib,ik;
long long int dp[2][2][2][32];
int vis[2][2][2][32];
int t=1;
string A,B,K;
void toString(int & no,string & s)
{
  s="";
  while(no>0)
  {
    s=char((no%2)+'0')+s;
    no/=2;
  }
  s=string(32-s.size(),'0')+s;
}

long long int solve(bool lessA=0,bool lessB=0,bool lessK=0,int in=0)
{
  if(in==32)
  {
    return lessA && lessB && lessK;
  }
  
  if(vis[lessA][lessB][lessK][in]==t)
    return dp[lessA][lessB][lessK][in];

  vis[lessA][lessB][lessK][in]=t;
  if(lessK)
  {
    int maxa=0;
    if(lessA)maxa=1;
    else maxa=A[in]-'0';
    
    int maxb=0;
    if(lessB)maxb=1;
    else maxb=B[in]-'0';
    long long int ans=0;
    for(int a=0;a<=maxa;a++)
    {
      for(int b=0;b<=maxb;b++)
      {
        ans+=solve(lessA ||(a+'0'<A[in]),lessB ||(b+'0'<B[in]),1,in+1);
      }
    }
    return  dp[lessA][lessB][lessK][in]=ans;
  }
  
  if(K[in]=='0')
  {
    int maxa=0;
    if(lessA)maxa=1;
    else maxa=A[in]-'0';
    
    int maxb=0;
    if(lessB)maxb=1;
    else maxb=B[in]-'0';
    long long int ans=0;
    for(int a=0;a<=maxa;a++)
    {
      for(int b=0;b<=maxb;b++)
      {
        if(a==1 && b==1)
          continue;
        ans+=solve(lessA ||(a+'0'<A[in]),lessB ||(b+'0'<B[in]),0,in+1);
      }
    }
    return  dp[lessA][lessB][lessK][in]=ans; 
  }

  int maxa=0;
  if(lessA)maxa=1;
  else maxa=A[in]-'0';
  
  int maxb=0;
  if(lessB)maxb=1;
  else maxb=B[in]-'0';
  long long int ans=0;
  for(int a=0;a<=maxa;a++)
  {
    for(int b=0;b<=maxb;b++)
    {
      ans+=solve(lessA ||(a+'0'<A[in]),lessB ||(b+'0'<B[in]),(a&&b)+'0'<K[in],in+1);
    }
  }
  return  dp[lessA][lessB][lessK][in]=ans;
}
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int T;
  cin>>T;
  for(;t<=T;t++)
  {
    cin>>ia>>ib>>ik;
    toString(ia,A);
    toString(ib,B);
    toString(ik,K);
    // cout<<A<<" "<<B<<" "<<K<<endl;
    long long int ans=solve();
    printf("Case #%d: %lld\n", t,ans);
  } 
}