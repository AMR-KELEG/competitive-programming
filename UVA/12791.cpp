//AC
#include "bits/stdc++.h"
#define EPS 0.00000001
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int x,y;
	while(cin>>x>>y)
	{
		long double ans = y;
		ans/= (y-x);
		if(abs(ans-round(ans))<=EPS)
		{
			cout<<round(ans)<<"\n";
		}
		else
		{
			cout<<ceil(ans)<<"\n";	
		}
	}	
}