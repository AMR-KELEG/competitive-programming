#include "bits/stdc++.h"
using namespace std;
string a,b;
int len;
int dp[20][1][500];//curin - addmax - curdiff (even-odd) - iseven
vector<int> isprime(1000,1);

bool check(int i)
{
  int ans=0;
  bool ise=0;
  while(i>0)
  {
    ans+=ise?(i%10):-(i%10);
    i/=10;
    ise=!ise;
  }
  if(ans<=0)
    return 0;
  return isprime[ans];
}

int dummysolve(int n)
{
  int ans=0;
  for(int i=0;i<=n;i++)
    if(check(i))
      ans++;
  return ans;
}

int solve(string & s,bool iseven,int curin=0,bool addmax=0,int curdiff=100)
{
  cout<<"CASE "<<curin<<" "<<curdiff<<" "<<int(addmax)
    <<" "<<dp[curin][addmax][curdiff]<<endl;
  if(dp[curin][addmax][curdiff]!=-1)
  {
    cout<<"CAME HERE "<<curin<<" "<<curdiff<<" "<<int(addmax)
    <<" "<<dp[curin][addmax][curdiff]<<endl;
    return dp[curin][addmax][curdiff];
  }

  if(curin==len)
  {
    if(curdiff<100)
      return dp[curin][addmax][curdiff]=0;
    if(isprime[curdiff-100])
    {
      return dp[curin][addmax][curdiff]=1;
    }
    return dp[curin][addmax][curdiff]=0;
  }


  int ans=0;
  if(addmax)
  {
    for(int i=0;i<=9;i++)
    {
      ans+=solve(s,!iseven,curin+1,addmax,curdiff+((iseven)?i:-i));    
    }
  }

  else
  {
    for(int i=0;i<s[curin]-'0';i++)
    {
      ans+=solve(s,!iseven,curin+1,1,curdiff+((iseven)?i:-i));
    }
    ans+=solve(s,!iseven,curin+1,0,curdiff+((iseven)?(s[curin]-'0'):-(s[curin]-'0')));
  }

  return dp[curin][addmax][curdiff]=ans; 
}

string int_to_string(int i)
{
  if(i<=0)
    return "0";
  string ans;
  while(i>0)
  {
    ans=string(1,'0'+i%10)+ans;
    i/=10;
  }
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
  int t;
  int a,b;
  string sa,sb;
  cin>>t;
  while(t--)
  {
    cin>>a>>b;
    a--;
    sa=int_to_string(a);
    sb=int_to_string(b);
    
    memset(dp,-1,sizeof dp);
    len=sb.size();
    int ans=solve(sb,((len%2)==0));
    memset(dp,-1,sizeof dp);
    len=sa.size();
    cout<<dummysolve(b)-dummysolve(a-1)<<" ";
    if(a>0) ans-=solve(sa,((len%2)==0));
    
    // cout<<sa<<" "<<sb<<" "<<sa.size()<<" "<<sb.size()<<" "<<ans<<endl;
    cout<<ans<<endl;
  } 
}