//AC
#include "bits/stdc++.h"
using namespace std;
string toStr(long long int val)
{
  string ans;
  while(val>0)
  {
    ans=char('0'+((val%10)%2))+ans;
    val/=10;
  }
  ans=string(19-ans.size(),'0')+ans;
  return ans;
}
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int t;
  cin>>t;
  char op;
  long long int no;
  map<string,int>mp;
  string pat;
  while(t--)
  {
    cin>>op;
    if(op=='+')
    {
      cin>>no;
      // cout<<toStr(no)<<endl;
      mp[toStr(no)]++;
    }
    else if(op=='-')
    {
      cin>>no;
      mp[toStr(no)]--; 
    }
    else
    {
      cin>>pat;
      pat=string(19-pat.size(),'0')+pat;
      cout<<mp[pat]<<endl;
    }
  } 
}