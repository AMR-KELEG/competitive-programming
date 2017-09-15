//AC
#include "bits/stdc++.h"
using namespace std;
long long int counter[21]={};
long long int mypow(long long int i,long long int p)
{
	if(p==0)
		return 1LL;
	return i*mypow(i,p-1);
}
int finddigits(long long int i)
{
	int d=0;
	while(i>0)
	{
		i/=10;
		d++;
	}
	return d;
}

long long int finderror(long long int i)
{
	int n=finddigits(i);
	if(i<10)
	{
		return 9LL-i;
	}
	long long int msd=i,lsd=i%10;
	long long int ans=0;
	while(msd>=10)
	{
		msd/=10;
	}
	// cout<<i<<" "<<" M "<<msd<<" L "<<lsd<<endl;
	
	long long int midval=i;
	midval-=(((long long int)msd)*ceil(mypow(10,n-1)));
	// cout<<i<<" "<<midval<<endl;
	midval/=10;
	// cout<<i<<" "<<midval<<endl;
	if(msd>lsd)
	{
		ans=((10-msd)*(ceil(mypow(10,n-2))));
		ans-=midval;



		/*
		ans=(10-msd)*ceil(mypow(10,n-2));
		// cout<<i<<" B "<<msd<<" "<<lsd<<endl;
		if(midval>0)
		{
			ans-=midval;
			// ans++;
		}
		// cout<<"A "<<ans<<endl;
		*/
	}
	else if (msd==lsd)
	{
		ans=((10-msd)*(ceil(mypow(10,n-2))));
		ans-=(midval+1);
	}
	else
	{
		ans=((10-msd)*(ceil(mypow(10,n-2))));
		ans-=(midval+1);
	}
	// cout<<ans<<endl;
	return ans;
}
long long int findsum(long long int i)
{
	if(i==0)
		return 0;
	long long ans=counter[finddigits(i)];
	ans-=finderror(i);
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	long long int l,r;
	cin>>l>>r;
	counter[0]=0;
	counter[1]=9;
	long long int cor=9;
	for(int i=2;i<=19;i++)
	{
		cor=((9LL)*ceil(mypow(10,i-2)));
		counter[i]=counter[i-1]+cor;
		// cor+=((9LL)*ceil(mypow(10,i-2)));
		// cout<<counter[i]<<endl;
	}
	// cout<<findsum(l-1LL)<<endl;
	// cout<<findsum(r)<<endl;
	long long int ans=findsum(r)-findsum(l-1LL);
	cout<<ans<<endl;
	// cout<<"Cor "<<cor;
}