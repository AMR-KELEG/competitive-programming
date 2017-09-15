//AC
#include "bits/stdc++.h"
using namespace std;
unsigned long long int expby2(unsigned long long int x,unsigned long long int n)
{
	//cout<<x<<endl;
	if(n==0)
		return 1;
	if(n==1)
		return x%1000000007;
	if(n%2)
		return ( (x%1000000007)*
			 ( expby2( ((x%1000000007)*(x%1000000007))%1000000007 ,
				(n-1)/2 )%1000000007) ) %1000000007;

	return expby2( ((x%1000000007)*(x%1000000007))%1000000007
	 ,n/2) %1000000007;

}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	unsigned long long int n,ans;
	cin>>n;
	if(n==0)
		cout<<1;
	else
	{
		ans=expby2(2,n)%1000000007;	
		ans=((expby2(2,n-1)%1000000007)*((1+ans)%1000000007))%1000000007;
		//cout<<ans<<endl;
		cout<<ans;
	}

}
