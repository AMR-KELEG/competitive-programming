#include "bits/stdc++.h"
#define MOD (1000000007)
using namespace std;
unordered_map<int,int>mp;
long long int fact[2001]={};
long long int modPow(int val,int p)
{
  if(p==0)return 1;
  if(p==1)return val;
  long long int ans=modPow(val,p>>1);
  ans=(ans*ans)%MOD;
  if(p%2)
    ans=(ans*val)%MOD;
  return ans;
}
long long int inv(int val)
{
  return modPow(val,MOD-2);
}
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("beachumbrellas.in","r",stdin);
    freopen("beach_umbrellas_ans.out","w",stdout);
  #endif
  fact[0]=1;
  for(int i=1;i<=2000;i++)
  {
    fact[i]=(i*fact[i-1])%MOD;
  }
  int T,n,m;
  cin>>T;
  for(int t=1;t<=T;t++)
  {
    mp.clear();
    cin>>n>>m;
    std::vector<int> R(n);
    int sR=0;
    for(int i=0;i<n;i++)
    {
      cin>>R[i];
      sR+=R[i];
    }
    long long int ans=0;
    if(n==1)
    {
      ans=m;
    }
    else
    {
      long long int nWays=fact[n-2];
      long long int invN=inv(fact[n]);
      for(int f=0;f<n;f++)
      {
        for(int s=0;s<n;s++)
        {
          if(f==s)
            continue;
          int remLen=m-R[f]-R[s];
          int midRegionReqLen=2*(sR-R[f]-R[s])+1;
          if(remLen<midRegionReqLen)
            continue;
          long long int curAns=nWays;
          int blank=remLen-midRegionReqLen;//Divide it among N portions
          curAns=(nWays*invN)%MOD;
          //(blank+n)!/(blank)!
          if(mp.find(blank+n)!=mp.end())
          {
            curAns=(curAns*mp[blank+n])%MOD;
          }
          else
          {
            long long int val=1;
            for(int mul=blank+1;mul<=blank+n;mul++)
            {
              val=(val*mul)%MOD;
            }
            curAns=(curAns*val)%MOD;
            mp[blank+n]=val;
          }
          ans=(ans+curAns)%MOD;
        }
      }
    }
    cout<<"Case #"<<t<<": "<<ans<<endl;
  }  
}