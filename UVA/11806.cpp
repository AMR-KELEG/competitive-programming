//AC
#include <bits/stdc++.h>
#define MOD 1000007
using namespace std;

int C[401][401];//n & r
void prepare()
{
	for(int no=1;no<=400;no++)
	{
		C[no][0]=1;
		for(int i=1;i<no;i++)
		{	
			C[no][i]=C[no-1][i]+C[no-1][i-1];
			C[no][i] %=MOD;
		}
		C[no][no]=1;
	}
}

long long int nCr(int n,int r)
{
	if(n==r)
		return 1;
	if(r>n)
	{
		return 0;
	}
	return C[n][r];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	prepare();
	int T;
	cin>>T;
	int n,m,k;
	for(int t=1; t<=T;t++)
	{
		cin>>n>>m>>k;
		long long int ans = nCr(n*m, k);
		int dr[] = {-1,-1,0,0};
		int dc[] = {0,0,-1,-1};
		// no of per 0 or 1
		// 2^4
		for(int p=1; p< (1<<4);p++)
		{
			int r = n;
			int c = m;
			int no =0;
			for(int shift =0 ;shift<4;shift++)
			{
				if(p>>shift & 1)
				{
					// take 4-i
					no ++;
					r+=dr[3-shift];
					c+=dc[3-shift];
				}
			}
			// cout<<r<<" "<<c<<" : "<<r*c<<"C"<<k<<endl;
			if(no%2)
			{
				ans-=nCr(r*c,k);
			}
			else
			{
				ans+=nCr(r*c,k);
			}
		}
		while(ans<0)
			ans +=MOD;
		ans %= MOD;
		printf("Case %d: %d\n", t,ans);
	}
	return 0;
}