//AC
#include "bits/stdc++.h"
#define MOD (1000000007)
using namespace std;
int fact[200001]={};
int invfact[200001]={};
int modExp(int val,int p)
{
	if(p==0)return 1;
	if(p==1)return val;
	long long int ans=modExp(val,p/2);
	ans=(ans*ans)%MOD;
	if(p%2)
		ans=(ans*val)%MOD;
	return ans;
}
int inv(int n)
{
	return modExp(n,MOD-2);
}
int nCr(int n,int r)
{
	//n!/(n-r)!(r)!
	long long int ans=fact[n];
	ans=(ans*invfact[r])%MOD;
	ans=(ans*invfact[n-r])%MOD;
	return ans;
}
int findZerosVal(int nZ)
{
	if(nZ==0)
		return 0;
	return (nZ%2==0);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	fact[0]=1;
	invfact[0]=1;
	for(long long int i=1;i<200001;i++)
	{
		fact[i]=(i*fact[i-1])%MOD;
		invfact[i]=inv(fact[i]);
	}
	int z,o,g;
	cin>>z>>o>>g;
	if(o==0)
	{
		int ans=findZerosVal(z);
		cout<<(ans==g);
	}
	else if(o==1)
	{
		if(z==0)
			cout<<(1==g);
		else
		{
			//z is no of zeros to the left
			int ans=0;
			int totalWays=nCr(z+o,z);
			ans+=findZerosVal(z)==0;
			z--;
			while(z>=0)
			{
				int curVal=findZerosVal(z+1);
				ans+=(curVal==0);
				z--;
			}
			if(g==0)
				cout<<ans;
			else
			{
				ans=totalWays-ans;
				if(ans<0)
					ans+=MOD;
				cout<<ans;
			}
		}

	}
	else
	{
		int totalWays=nCr(z+o,z);
		long long int ans=(findZerosVal(z+1)==0);
		int remZeros=0;
		while(z>0)
		{
			z--;
			remZeros++;
			int ways=nCr(remZeros+o-1,remZeros);
			if(findZerosVal(z+1)==0)
			{
				ans=(ans+ways)%MOD;
			}
		}
		if(g==0)
			cout<<ans;
		else
		{
			ans=(totalWays-ans);
			if(ans<0)
				ans+=MOD;
			cout<<ans;
		}
	}
}
