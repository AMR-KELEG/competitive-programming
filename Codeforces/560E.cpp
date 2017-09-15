//AC
#include "bits/stdc++.h"
using namespace std;
int h,w,n;
#define MOD 1000000007LL
// h w n <=10^5
//r h
//%10^9 +7
// one based
std::vector<long long> sol;
std::vector<pair<int,int> > blocks;
long long int fact[300000]={};
long long int modmul(long long i,int p)
{
	if(p==0)
		return 1LL;
	if(p==1)
		return i;
	long long ans=modmul(i,p/2)%MOD;
	if(p%2)
	{
		// odd 
		return (((ans*ans)%MOD)*i)%MOD;
	}
	return (ans*ans)%MOD;
}

long long int inverse(long long int i)
{
	// no ^ MOD-2
	return modmul(i,MOD-2)%MOD;
}
long long int NcR(int N,int R)
{
	long long int den=((fact[N-R]%MOD)*(fact[R]%MOD))%MOD;
	long long int ans=fact[N]%MOD;
	ans*=(inverse(den%MOD)%MOD);
	ans=ans%MOD;
	return ans;
}

/*
hi ci

			hin cin

*/
long long int solve(int in)
{
	if(sol[in]!=-1)
		return sol[in];
	int hin=blocks[in].first;
	int cin=blocks[in].second;
	// cout<<in<<" "<<hin<<" "<<cin<<endl;
	long long int ans=NcR(hin+cin-2,hin-1)%MOD;
	for(int i=0;i<in;i++)
	{
		int hi=blocks[i].first;
		int ci= blocks[i].second;
		// cout<<i<<" "<<hi<<" "<<ci<<endl;
		long long int rem=(solve(i)*NcR(hin-hi+cin-ci,cin-ci))%MOD;
		ans=ans-rem;
		if(ans<0)
			ans+=MOD;
		ans=ans%MOD;
	}
	// cout<<in<<" "<<ans<<endl;
	return sol[in]=ans%MOD;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long ans=1;
	fact[0]=1;
	for(int i=1;i<300000;i++)
	{
		ans*=i;
		fact[i]=(ans=ans%MOD);
	}

	cin>>h>>w>>n;
	sol=std::vector<long long> (n+2,-1);
	blocks=std::vector<pair<int,int> > (n);
	blocks.push_back(pair<int,int> (h,w));
	int r,c;
	for(int i=0;i<n;i++)
	{
		cin>>blocks[i].first>>blocks[i].second;
	}
	sort(blocks.begin(), blocks.end());
	cout<<solve(n)%MOD;
}