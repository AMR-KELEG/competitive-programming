//AC
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define ll long long int
const int D = 2;
typedef std::vector<std::vector<ll> > Matrix;
#define REP(i,n) for(int i=1;i<=n;i++)
Matrix mul(Matrix a, Matrix b)
{
	Matrix c(D+1,std::vector<ll> (D+1,0));
	REP(i,D) REP(j,D) REP(k,D)
		c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % MOD;
	return c;
}

Matrix pow(Matrix m,int p)
{
	if (p==1)
		return m;
	if (p%2)
		return mul(m,pow(m,p-1));
	Matrix x = pow(m,p/2);
	return mul(x,x);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while (T--)
	{
		int n,m;
		cin>>n>>m;
		if (m<2)
		{
			int fib[]={0,1};
			int ans = 0;
			for(int i=n;i<=m;i++)
			{
				ans+=fib[i];
			}
			cout<<ans<<endl;
			continue;
		}
		if (n==0)
		{
			n++;
		}
		// sum1 = fib[m+2]-1
		// sum2 = fib[n+1]-1
		// sum1 - sum2 = fib[m+2] - fib[n+1]
		Matrix T (D+1, std::vector<ll> (D+1,1));
		T[2][2]=0;
		long long int ans = pow(T,m+1)[1][1];
		ans -= pow(T,n)[1][1];
		while(ans <0)
			ans+=MOD;
		cout<< ans%MOD<<endl;
		
		// find sigma from i to m
	}	
}