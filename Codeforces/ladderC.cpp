#include "bits/stdc++.h"
using namespace std;
  long long int hm,am,dm;
  long long int hh,ah,dh;
bool validate(int h,int adda,int addd)
{
  if(am<=dh+addd)
    return 1;

  if(ceil(1.0*h/(am-dh-addd))>ceil(1.0*hm/(ah+adda-dm)))
  {
    return 1;
  }
  return 0;
}
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  cin>>hh>>ah>>dh;//hero
  cin>>hm>>am>>dm;//monster
  long long int ch,ca,cd; 
  cin>>ch>>ca>>cd;
  long long int minc=(1LL)<<50,reqcost=0;
  if(ah<=dm)
  {
    reqcost=ca*(1+dm-ah);
    ah=dm+1;
  }
  // cout<<"Req "<<reqcost<<endl;
  for(int adda=0;adda<=100;adda++)
  {
    for(int addd=0;addd<=100;addd++)
    {
      // how to find required health 
      //each unit t, hh-=(am-dh) 
      int l=hh,r=1<<29;
      for(int i=0;i<100;i++)
      {
        int mid=(l+r)/2;
        if(validate(mid,adda,addd))
        {
          r=mid;
        }
        else
          l=mid+1;
      }
      // cout<<"L R "<<l<<" "<<r<<endl;
      long long int curcost=(adda*ca)+(addd*cd)+((l-hh)*ch);
      if(curcost<minc)
      {
        // cout<<adda<<" "<<addd<<" "<<l-hh<<" "<<minc<<endl;
        minc=curcost;
      }
    }
  }  
  cout<<reqcost+minc;
    
}