//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  long long int n;
  cin>>n;
  if(n<3)
    cout<<-1;
  else if(n%2)
  {
    cout<<fixed<<setprecision(0)<<((n*n)-1)/2<<
            " "<<((n*n)+1)/2;
  } 
  else
  {
    cout<<fixed<<setprecision(0)<<((n*n)/4)-1<<" "<<((n*n)/4)+1;
  }
}