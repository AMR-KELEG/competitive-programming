//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<pair<int,int>> points; 
long long int distance(int in1,int in2)
{
  long long int ans=((long long int)(points[in1].first-points[in2].first))*(points[in1].first-points[in2].first);
  ans+=((long long int)(points[in1].second-points[in2].second))*(points[in1].second-points[in2].second);
  return ans;
}
int main()
{
  // std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int n;
  scanf("%d",&n);
  points=std::vector<pair<int,int>> (n);
  for(int i=0;i<n;i++)
  {
    scanf("%d%d",&points[i].first,&points[i].second);
  }

  int p1=0,p2=1;
  int deltax=points[p1].first-points[p2].first;
  int deltay=points[p1].second-points[p2].second;
  int GCD=__gcd(deltax,deltay);
  deltax/=GCD;
  deltay/=GCD;
  //y=mx+c
  //deltax*y=deltay*x+c*deltax
  long long int deltaxMULc=(deltax*((long long int)points[p1].second))-(deltay*((long long int)points[p1].first));
  for(int i=0;i<n;i++)
  {
    if(i==p1 || i==p2)
      continue;
    int deltax1=points[p1].first-points[i].first;
    int deltay1=points[p1].second-points[i].second;
    int GCD=__gcd(deltax1,deltay1);
    deltax1/=GCD;
    deltay1/=GCD;
    long long int deltaxMULc1=(deltax1*((long long int)points[p1].second))-(deltay1*((long long int)points[p1].first));
    
    if(deltax==deltax1 && deltay==deltay1 && deltaxMULc==deltaxMULc1)
    {
      if(distance(i,p1)<distance(p1,p2))
      {
        p2=i;
      }
    }
  }

  long long int minABSdis=deltaxMULc;
  int p3=-1;
  for(int i=0;i<n;i++)
  {
    if(i==p1 || i==p2)
      continue;
    long long int curDis=((long long int)deltax)*(points[i].second)-((long long int)deltay)*(points[i].first);
    if(curDis==deltaxMULc)
      continue;
    if(curDis>deltaxMULc)
    {
      curDis-=deltaxMULc;
    }
    else
    {
      curDis=deltaxMULc-curDis; 
    }
    curDis=abs(curDis);
    if(curDis<minABSdis || p3==-1)
    {
      minABSdis=curDis;
      p3=i;
    }
  }
  cout<<p1+1<<" "<<p2+1<<" "<<p3+1;

}