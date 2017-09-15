//AC
#include "bits/stdc++.h"
using namespace std;
#define MAX 10010
void solve(long long int n)
{
	for(long long int x=n/2;x<=MAX;x++)
	{
		long long int y=x+1;
		if(2*x-n!=0 && (n*x)/((2*x)-n)>0)
		{
			y=max((n*x)/((2*x)-n),y);
		}
		for(;y<=MAX;y++)
		{
			long long int z=x*y;
			if(((2*z)-n*(x+y))==0)
				continue;
			if((z*n)%((2*z)-n*(x+y))==0 && (n*z)/((2*z)-(n*(x+y)))>max(x,y))
			{
				if(z>1000000000)
					continue;
				z=(n*z)/((2*z)-n*(x+y));
				cout<<x<<" "<<y<<" "<<z;
				return ;
			}
		}
	}
	cout<<-1;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	solve(n);
}