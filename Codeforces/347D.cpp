//AC
#include "bits/stdc++.h"
using namespace std;
string s1,s2,s3;
int dp[101][101][101];
string nextc[101][101][101];// as index in first string

int solve(int i1=0,int i2=0,int i3=0)
{
  if(i1==s1.size() || i2==s2.size() || i3==s3.size())
  {
    return 0;
  }

  if(dp[i1][i2][i3]!=-1)
    return dp[i1][i2][i3];

  if(s1[i1]==s2[i2])
  {
    if(i3<s3.size()-1 && s3[i3]==s1[i1])
    {
      //still can get last char
      int ans1=1+solve(i1+1,i2+1,i3+1);
      int ans2=solve(i1+1,i2,i3);
      int ans3=solve(i1,i2+1,i3);
      int mx=max(ans1,max(ans2,ans3));
      if(ans2==mx)
      {
        nextc[i1][i2][i3]=nextc[i1+1][i2][i3];
      }
      else if(ans3==mx)
      {
        nextc[i1][i2][i3]=nextc[i1][i2+1][i3];
      }
      else if(ans1==mx)
      {
        nextc[i1][i2][i3]=s1[i1]+nextc[i1+1][i2+1][i3+1];
      }
      return dp[i1][i2][i3]=mx;
    } 

    else if(i3<s3.size() && s3[i3]!=s1[i1])
    {
      int length=0;
      bool valid=0;
      for(int start=1;start<=i3 && !valid;start++)
      {
        valid=1;
        int i=0;
        for(int j=start;j<i3;j++)
        {
          if(s3[j]!=s3[i++])
          {
            valid=0;
          }
        }

        if(valid)
        {
          if(s3[i]==s1[i1])
          {
            length=1+i3-start;
          }
          else
          {
            valid=0;
          }
        }
      }
      // cout<<i3<<" "<<length<<" "<<s3.substr(0,i3)<<" "<<s1[i1]<<endl;
      int ans1=1+solve(i1+1,i2+1,length);
      int ans2=solve(i1+1,i2,i3);
      int ans3=solve(i1,i2+1,i3);
      int mx=max(ans1,max(ans2,ans3));
      if(ans2==mx)
      {
        nextc[i1][i2][i3]=nextc[i1+1][i2][i3];
      }
      else if(ans3==mx)
      {
        nextc[i1][i2][i3]=nextc[i1][i2+1][i3];
      }
      else
      {
        nextc[i1][i2][i3]=s1[i1]+nextc[i1+1][i2+1][length];
      }
      return dp[i1][i2][i3]=mx;

    }
    else
    {
      // can't take it
      int ans=solve(i1+1,i2+1,i3);
      nextc[i1][i2][i3]=nextc[i1+1][i2+1][i3];
      return dp[i1][i2][i3]=ans;
    }
  }

  int ans1=solve(i1+1,i2,i3);
  int ans2=solve(i1,i2+1,i3);
  if(ans1>ans2)
    nextc[i1][i2][i3]=nextc[i1+1][i2][i3];
  else
    nextc[i1][i2][i3]=nextc[i1][i2+1][i3];
  return dp[i1][i2][i3]=max(ans1,ans2);
}

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  cin>>s1>>s2>>s3;
  for(int i=0;i<101;i++)
  {
    for(int j=0;j<101;j++)
    {
      for(int k=0;k<101;k++)
        nextc[i][j][k]="";
    }
  }
  memset(dp,-1,sizeof dp);
  solve();
  if(nextc[0][0][0]=="")
    nextc[0][0][0]="0";
  cout<<nextc[0][0][0];
}
