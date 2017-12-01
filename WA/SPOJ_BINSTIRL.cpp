// WA
#include "bits/stdc++.h"
using namespace std;
int s[10][10];	

int solve(int n,int k)
{
	if (k==0)
		return n==0;
	if (n==0)
		return 0;
	if (s[n][k] !=-1)
		return s[n][k];
	return s[n][k] = solve(n-1,k-1) + k* solve(n-1,k);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(s,-1,sizeof s);
	for (int n=1;n<10;n++)
	{
		for (int k=1;k<=n;k++)
		{
			cout<<"S("<<n<<", "<<k<<") = "<<solve(n,k)<<" %2 = "<<solve(n,k)%2<<endl;
		}
	}
}