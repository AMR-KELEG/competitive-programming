//AC
#include "bits/stdc++.h"
using namespace std;
long long int lcm(long long int a,long long int b)
{
	long long int ans = a;
	ans*=b;
	return ans/__gcd(a,b);
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int n,m;
	while(cin>>n>>m)
	{
		std::vector<long long int> v(m);
		for(int i=0;i<m;i++)cin>>v[i];
		long long int ans = 0;
		for(long long int i=1;i< (1<<m);i++)
		{
			long long int cur = 1;
			long long int no = 0;
			for(int id=0 ;id<m;id++)
			{
				if( (i>>id) & 1)
				{
					no++;
					cur = lcm(cur,v[m-1-id]);
				}
			}
			if(no%2 ==0)
			{
				ans -= n/cur;
			}
			else
			{
				ans += n/cur;	
			}
		}
		printf("%d\n", n-ans);
	}
}