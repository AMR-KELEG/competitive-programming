//AC
#include "bits/stdc++.h"
#define REP(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef std::vector<std::vector<long long> > matrix;
int MOD;
int d;

matrix mul(const matrix & A,const matrix & B)
{
  matrix C(d+1,std::vector<long long> (d+1,0));
  REP(i,d)REP(j,d)REP(k,d)
    C[i][j]=(C[i][j]+(A[i][k])%MOD*(B[k][j])%MOD)%MOD;
  return C;
}

matrix pow(const matrix & A,int p)
{
  if(p==1)
    return A;
  if(p%2)
    return mul(A,pow(A,p-1));
  matrix X=pow(A,p/2);
  return mul(X,X);
}

int main()
{
  // std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int n;
  scanf("%d %d %d ",&d,&n,&MOD);
  while(!(n==0 && MOD==0 && d==0))
  {
    matrix T(d+1,std::vector<long long> (d+1,0));
    for(int i=1;i<=d;i++)
    {
      int no;
      scanf("%d",&no);
      T[1][i]=no%MOD;
    }
    std::vector<int> f(d+1);
    for(int i=0;i<d;i++)
    {
      scanf("%d",&f[d-i]);
      f[d-i]%=MOD; 
    }
    if(n<=d)
    {
      printf("%d\n", f[n]);
    }
    else
    {
      for(int r=2;r<=d;r++)
      {
        T[r][r-1]=1;
      }
      matrix res=pow(T,n-d);
      long long int ans=0;
      for(int i=1;i<=d;i++)
      {
        ans+=(((res[1][i]%MOD)*(f[i]%MOD))%MOD);
        ans%=MOD;
      }      
      ans%=MOD;
      printf("%d\n", (int)ans);
    }
    scanf("%d %d %d ",&d,&n,&MOD);
  }
}