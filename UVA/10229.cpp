//AC
#include "bits/stdc++.h"
using namespace std;

#define REP(i,n) for (int i = 1; i <= n; i++)
typedef long long ll;
typedef vector<vector<ll> > matrix;
ll MOD = 1000000007;
const int K = 2;
 
// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}
// computes A ^ p
matrix pow(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

int main()
{
  // std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int n,m;
  while(cin>>n>>m)
  {
    if(n==0)
    {
      printf("0\n");
    }
    else if(n==1)
    {
      printf("1\n");
    }
    else
    {
      matrix A(K+1, vector<ll>(K+1,1));
      A[2][2]=0;
      MOD=ceil(pow(2,m));
      matrix res=pow(A,n-1);
      int ans=res[1][1];
      printf("%d\n", ans);
      // cout<<endl;
    }
  } 
}