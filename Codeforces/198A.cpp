//AC after many many submissions
#include "bits/stdc++.h"
using namespace std;
long long int ampow(int k,int p)
{
	long long int ans=1;
	for(int i=0;i<p;i++)
	{
		ans*=k;
	}
	return ans; 
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int k,b,n,t,z,i;
	cin>>k>>b>>n>>t;
	if(k==1)
	{
		z=1+(n*b);
		if(t>=z)
			i=0;
		else
			i=ceil( ((double)z-t)/b );
	}	
	else
	{
		double c=(double)b/(k-1);
		if(log(t+c)-(n*log(k)+log(c+1))>=0)
			i=0;
		else if(abs(log(t+c)-(n*log(k)+log(c+1)))<=0.0000000001)
			i=0;
		else
		{
			double num=n*log(k)+log(c+1)-log(t+c);
			double den=log((double)k);
			i=ceil(num/den);
			if(i-(num/den)>=0.9999999999)
				i--;
		}
	}
	cout<<i<<endl;
}