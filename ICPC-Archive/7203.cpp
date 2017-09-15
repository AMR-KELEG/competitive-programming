//AC
//5:52 -> 6:18
#include "bits/stdc++.h"
using namespace std;

string s;
string ans;
bool dp[64][3][3][3][3][3][3][3][3][3][3][2];
bool vis[64][3][3][3][3][3][3][3][3][3][3][2];
std::vector<short> Co(10);
bool solve(short bit,short c0,short c1,short c2,short c3,short c4,short c5
  ,short c6,short c7,short c8,short c9,bool isless)
{
  if(bit==s.size())
    return 1;
  if(vis[bit][c0][c1][c2][c3][c4][c5][c6][c7][c8][c9][isless])
  {
    return dp[bit][c0][c1][c2][c3][c4][c5][c6][c7][c8][c9][isless];
  }
  vis[bit][c0][c1][c2][c3][c4][c5][c6][c7][c8][c9][isless]=1;
  Co[0]=c0;Co[1]=c1;
  Co[2]=c2;Co[3]=c3;
  Co[4]=c4;Co[5]=c5;
  Co[6]=c6;Co[7]=c7;
  Co[8]=c8;Co[9]=c9;
  if(isless)
  {
    for(short i=9;i>=0;i--)
    {
      if(Co[i]<2)
      {
        Co[i]++;
        if(solve(bit+1,Co[0],Co[1],Co[2],Co[3],Co[4],
          Co[5],Co[6],Co[7],Co[8],Co[9],isless))
        {
          ans[bit]=i+'0';
          // cout<<bit<<" "<<i<<endl;
          Co[i]--;  
          return 1;
        }
        Co[i]--;
      }
    }
  }
  else
  {
    for(short i=s[bit];i>=0;i--)
    {
      if(Co[i]<2)
      {
        Co[i]++;
        if(solve(bit+1,Co[0],Co[1],Co[2],Co[3],Co[4],
          Co[5],Co[6],Co[7],Co[8],Co[9],i<s[bit]))
        {
          ans[bit]=i+'0';
          // cout<<"Not less "<<bit<<" "<<i<<endl;
          Co[i]--;
          return 1;
        }
        Co[i]--;
      }
    }
  }
  return 0;
}

void formString(long long int n)
{
  s="";
  while(n)
  {
    s=char((n%10))+s;
    n/=10;
  }
  // cout<<s<<" ";
  ans=string(s.size(),0);
}

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  long long int n;
  while(cin>>n)
  {
    //Form string
    formString(n);
    //Memset vis array
    memset(vis,0,sizeof vis);
    //Solve
    solve(0,0,0,0,0,0,0,0,0,0,0,0);
    int indexOfZero=-1;
    for(int i=0;i<ans.size();i++)
    {
      if(ans[i]=='0')
        indexOfZero=i;
      else
        break;
    }
    if(indexOfZero>=0)
      ans=ans.substr(indexOfZero+1);
    cout<<ans<<endl;
  } 
}