//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int N,M;
  bool first=1;
  while(cin>>N>>M)
  {
    long long int ans=0;
    int B;
    std::vector<int> pay(N);
    for(int r=0;r<M;r++)
    {
      cin>>B;
      int roundTotal=0;
      for(int j=0;j<N;j++)
      {
        cin>>pay[j];
        roundTotal+=pay[j];
      }
      int curTotal=roundTotal-pay[0];
      if(roundTotal>B)
      {
        roundTotal=curTotal;
      }
      int i;
      for(i=1;i<=10000;i*=10)
      {
        if(curTotal+i>B)
        {
          break;
        }
      }
      curTotal=curTotal+(i/10);
      ans=ans+curTotal-roundTotal;
    } 
    cout<<ans<<endl;
  } 
}