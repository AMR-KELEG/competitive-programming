//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  long long int l1,r1,l2,r2,k;
  cin>>l1>>r1>>l2>>r2>>k; 
  long long int l=max(l1,l2);
  long long int r=min(r1,r2);
  if(l>r)
  {
    cout<<0;
  }
  else if(k>=l && k<=r)
  {
    cout<<r-l;
  }
  else
  {
    cout<<r+1-l;
  }
}