#include "bits/stdc++.h"
using namespace std;
int MOD=1000000007;

long long int modPow(long long int v,long long int p)
{
  if(p==0)
    return 1;
  if(p==1)
    return v%MOD;
  long long int val=modPow(v,p/2)%MOD;
  val*=val;
  val%=MOD;
  if(p%2)
  {
    val*=v;
    val%=MOD;
    return  val%MOD; 
  }
  return val%MOD;
}

int main()
{
  int t;
  scanf("%d",&t); 
  int k,n;//nth term
  while(t--)
  {
    scanf("%d %d",&k,&n);
    if(n==1)
    {
      printf("1\n");
    }
    else if(n==2)
    {
      printf("%d\n", k);
    }
    else
    {
      //Val=k^(power)
      //power=2^(n-3)
      MOD--;
      long long int power=modPow(2,n-3);
      MOD++;
      long long int ans=modPow(k,power);
      printf("%lld\n", ans%MOD);
    }
  }
}