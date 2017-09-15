//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int n;
  cin>>n;// n = 4^ N = 2^ (2*N)
  vector<int> nos(n); 
  for(int i=0;i<n;i++)cin>>nos[i];
  sort(nos.begin(), nos.end());
  long long int N=round(log(n)/log(4));
  N++;
  long long int ans=0;
  int limit=1;
  int taken=0;
  for(int i=n-1;i>=0 && N>0;)
  {
    while(taken<limit)
    {
      ans+=nos[i--]*N;
      taken++;
    }
    N--;
    limit*=4;
  }

  cout<<ans;
}