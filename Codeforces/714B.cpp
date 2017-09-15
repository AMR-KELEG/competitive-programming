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
  set<int>s;
  for(int i=0;i<n;i++)
  {
    int no;
    cin>>no;
    s.insert(no);
  } 
  if(s.size()>3)
  {
    cout<<"NO";
  }
  else if(s.size()==3)
  {
    int a[3];
    int in=0;
    for(auto i:s)
    {
      a[in++]=i;
    }
    if(abs(a[1]-a[0])==abs(a[2]-a[1]))
    {
      cout<<"YES";
    }
    else
      cout<<"NO";
  }
  else
  {
    cout<<"YES";
  }
}