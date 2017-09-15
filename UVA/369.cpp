//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int n,m;
  cin>>n>>m;
  while(n!=0 && m!=0)
  {
    long long int ans=1;
    // We have n-k balls
    // At the end you have n-k balls and k bars
    // n C k
    int i=n;
    int j=2;
    while(i>max(m,n-m) || j<=min(m,n-m))
    {
      if(j<=min(m,n-m) && ans%j==0)
      {
        ans/=j;
        j++;
      }
      else if(i>max(m,n-m))
      {
        ans*=i;
        i--;
      }
    }
    cout<<n<<" things taken "<<m<<" at a time is "<<ans<<" exactly.\n";
    cin>>n>>m;
  }
}