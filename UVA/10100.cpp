//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<string> v1,v2;
int dp[1001][1001];
int vis[1001][1001];
int t=1;
int solve(int i=0,int j=0)
{
  if(i==v1.size() || j==v2.size())
    return 0;
  if(vis[i][j]==t)
    return dp[i][j];
  vis[i][j]=t;
  if(v1[i]==v2[j])
  {
    return dp[i][j]=1+solve(i+1,j+1);
  }
  return dp[i][j]=max(solve(i,j+1),solve(i+1,j));
}

void formVec(string & s1,std::vector<string> & v1)
{
  int st=0;
  int len=0;
  for(int i=0;i<s1.size();i++)
  {
    if((s1[i]<='z' && s1[i]>='a') || (s1[i]<='Z' && s1[i]>='A') || (s1[i]<='9' && s1[i]>='0'))
    {
      len++;
    }
    else if(len)
    {
      v1.push_back(s1.substr(st,len));
      st=i+1;
      len=0;
    }
    else
    {
      st=i+1;
    }
  }
  if(len)
  {
    v1.push_back(s1.substr(st,len));
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  string s1,s2;
  while(getline(cin,s1))
  {
    getline(cin,s2);
    if(s1.size()==0 || s2.size()==0)
    {
      cout<<setw(2)<<t;
      cout<<". Blank!\n";
    }
    else
    {
      //generate vector<string> 
      v1.clear();
      v2.clear();
      formVec(s1,v1);
      formVec(s2,v2);
      cout<<setw(2)<<t;
      cout<<". Length of longest match: "<<solve()<<"\n"; 
    }

    t++;
  } 
}