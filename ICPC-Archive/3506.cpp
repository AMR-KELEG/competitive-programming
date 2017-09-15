//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int t;
  scanf("%d",&t);
  std::vector<int> a(4000),b(4000),c(4000),d(4000);
  while(t--)
  {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
      scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }
    unordered_map<int,int>mp1;
    mp1.reserve(n*n);
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        mp1[a[i]+b[j]]++;
      }
    }
    long long int ans=0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(mp1.find(-c[i]-d[j])!=mp1.end())
          ans+=mp1[-c[i]-d[j]];
      }
    }
    printf("%lld\n", ans);
    if(t)
      printf("\n");
  } 
}