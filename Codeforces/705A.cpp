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
  cout<<"I hate ";
  bool love=1;
  n--;
  while(n--)
  {
    cout<<"that ";
    if(love)
      cout<<"I love ";
    else
      cout<<"I hate ";
    love=!love;
  } 
  cout<<"it";
}