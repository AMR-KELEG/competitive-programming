// AC
// 
#include "bits/stdc++.h"
using namespace std;
int n;
long long int dp[11][11];
int vis[11][11];
string sol[11][11];
int curTest=0;
std::vector<int> noRows,noCols;

std::vector<string> toStr(11);

int solve(int l,int r)
{
  if(l==r)
  {
    vis[l][r]=curTest;
    sol[l][r]="A"+toStr[l+1];
    return dp[l][r]=0;
  }
  if(vis[l][r]==curTest)
  {
    return dp[l][r];
  }

  int minOpPivot=l;
  long long int minAns=solve(l,l)+solve(l+1,r)+(noRows[l]*noCols[l]*noCols[r]);
  for(int piv=l+1;piv<r;piv++)
  {
    long long int ans=solve(l,piv)+solve(piv+1,r)+(noRows[l]*noCols[piv]*noCols[r]);
    if(ans<minAns)
    {
      minAns=ans;
      minOpPivot=piv;
    }
  }
  sol[l][r]="("+sol[l][minOpPivot]+" x "+sol[minOpPivot+1][r]+")";
  return dp[l][r]=minAns;
}

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  for(int i=0;i<10;i++)
  {
    toStr[i]=string(1,char('0'+i));
  }
  toStr[10]="10";
  cin>>n;
  while(n!=0)
  {
    curTest++;
    noRows=std::vector<int> (n);
    noCols=std::vector<int> (n);
    for(int i=0;i<n;i++)
      cin>>noRows[i]>>noCols[i];
    solve(0,n-1);
    // cout<<"IN ";
    cout<<"Case "<<curTest<<": "<<sol[0][n-1]<<endl;
    cin>>n;
  }   
}
