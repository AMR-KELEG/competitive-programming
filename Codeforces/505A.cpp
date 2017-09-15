//AC
#include "bits/stdc++.h"
using namespace std;
bool ispalindrome(string & s)
{
  for(int i=0;i<s.size()/2;i++)
    if(s[i]!=s[s.size()-1-i])
      return 0;
  return 1;
}

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  string s;
  cin>>s;
  string ans;
  for(int startin=0;startin<=s.size();startin++)
  {
    ans=s.substr(0,startin)+string(1,'a')+s.substr(startin);
    for(char c='a';c<='z';c++)
    {
      ans[startin]=c;
      if(ispalindrome(ans))
      {
        cout<<ans;
        return 0;
      }
    }
  }
  cout<<"NA";
  return 0;
}