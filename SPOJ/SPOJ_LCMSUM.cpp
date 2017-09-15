#include "bits/stdc++.h"
using namespace std;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int t;
  scanf("%d",&t);
  int n;
  while(t--)
  {
    scanf("%d",&n);
    long long int ans=n;
    ans*=n-1;
    ans*=n;
    ans/=2;
    ans+=n;
    long long int d;
    for(d=2;d*d<n;d++)
    {
      if(n%d==0)
      {
        //We have added (d*i) wrongly
        ans-=(d*n);
        ans-=((n/d)*n);
        ans+=(d*n)/__gcd((long long int)n,d);
        ans+=((n/d)*n)/__gcd((long long int)n,n/d);
      }
    }
    if(ans%(d*d)==0 && d!=n)
    {
      ans-=(d*n);
      ans+=(d*n)/__gcd((long long int)n,d);
    }
    printf("%lld\n", ans);

  }

}