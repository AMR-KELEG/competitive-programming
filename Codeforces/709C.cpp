#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  string s;
  cin>>s;
  bool start=0;

  for(int i=0;i<s.size();i++)
  {
    if(s[i]!='a')
    {
      s[i]--;
      start=1;
    }
    else if(start && s[i]=='a')
      break;
    else if(start)
    {
      s[i]--;
    }
  }
  if(!start)
    s[s.size()-1]='z';

  cout<<s;
}