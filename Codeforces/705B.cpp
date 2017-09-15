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
  cin>>n;
  long long int t=0;
  int no;
  while(n--)
  {
    cin>>no;
    t+=(no-1);
    printf("%d\n", 1+int(t%2==0));
  } 
}