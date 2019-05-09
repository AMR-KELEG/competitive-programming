// AC
#include "bits/stdc++.h"
using namespace std;
string sa,sb;
int t=0;
int dp[10][2][2][91];
int vis[10][2][2][91];
vector<int> isprime(1000,1);

int solve(int indx, bool is_less, bool is_more, int diff){
  if (indx == 10){
    int real_diff = (diff - 45);
    if (real_diff < 0)
      return 0;
    if (isprime[real_diff])
      return 1;
    return 0;
  }

  if(vis[indx][is_less][is_more][diff] == t)
    return dp[indx][is_less][is_more][diff];

  vis[indx][is_less][is_more][diff] = t;
  
  int min_val = 0;
  if (!is_more)
    min_val = max(min_val, sa[indx]-'0');

  int max_val = 9;
  if (!is_less)
    max_val = min(max_val, sb[indx]-'0');

  int ans = 0;
  for (int val=min_val; val<=max_val; val++){
    bool cur_is_more = is_more || (val > (sa[indx]-'0'));
    bool cur_is_less = is_less || (val < (sb[indx]-'0'));
    int curdiff = diff;
    if (indx%2==0){
      curdiff += val;
    }
    else
      curdiff -= val;
    ans += solve(indx+1, cur_is_less, cur_is_more, curdiff);
  }

  return dp[indx][is_less][is_more][diff]=ans;
}

string int_to_string(int i)
{
  if(i<=0)
    return string(10, '0');
  string ans;
  while(i>0)
  {
    ans=string(1,'0'+i%10)+ans;
    i/=10;
  }
  ans = string(10 - ans.size(), '0') + ans;
  return ans;
}

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  
  isprime[0]=isprime[1]=0;
  for(int i=2;i<1000;i++)
  {
    if(isprime[i])
    {
      for(int mul=2;mul*i<1000;mul++)
        isprime[mul*i]=0;
    }
  }

  int T;
  int a,b;
  cin>>T;
  for(t=1; t<=T; t++)
  {
    cin>>a>>b;
    sa=int_to_string(a);
    sb=int_to_string(b);
    cout<<solve(0, 0, 0, 45)<<endl;
  } 
}