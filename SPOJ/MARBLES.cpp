//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int t;
  cin>>t;
  int n,k;
  while(t--)
  {
    cin>>n>>k;
    long long int ans=1;
    // We have n-k balls
    // At the end you have n-k balls and k bars
    // n C k
    int i=n-1;
    int j=2;
    while(i>max(k-1,n-k) || j<=min(n-k,k-1))
    {
      if(j<=min(n-k,k-1) && ans%j==0)
      {
        ans/=j;
        j++;
      }
      else if(i>max(k-1,n-k))
      {
        ans*=i;
        i--;
      }
    }
    cout<<ans<<"\n";
  }
}