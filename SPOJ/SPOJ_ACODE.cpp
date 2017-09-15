//AC
#include "bits/stdc++.h"
using namespace std;
string s;
long long int dp[5002];
int vis[5002];
int curCase=0;
long long int solve(int i=0)
{

  if(i>s.size()-1)
    return dp[i]=1;
  if(i==s.size()-1)
    return dp[i]=(s[i]!='0');
  if(vis[i]==curCase)
  {
    return dp[i];
  }
  vis[i]=curCase;
  if(s[i]=='0')
    return dp[i]=0;
  long long int ans1=solve(i+1);
  int no=((s[i]-'0')*10)+(s[i+1]-'0');
  long long int ans2=0;
  if(no<=26)
  {
    ans2=solve(i+2);
  }
  
  if(ans1!=0 && ans2!=0)
  {
    return dp[i]=ans1+ans2;
  }

  return dp[i]=max(ans1,ans2);
}
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  // cout<<string(5000,'1')<<endl;
  cin>>s;
  while(s!="0")
  {
    curCase++;
    cout<<solve()<<endl;
    cin>>s;
  }
}