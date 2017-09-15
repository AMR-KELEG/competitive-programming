//AC
//ONE BASED
#include "bits/stdc++.h"
using namespace std;
std::vector<long long int> tree;//initialize it to 0
long long int B,P,L,N;
long long int modpow(long long int i,long long int p)
{
	if(p==0)
		return 1LL;
	if(p==1)
		return i;
	if(p%2==0)
	{
		long long int ans=modpow(i,p/2);
		return ((ans%P)*(ans%P))%P;
	}
	long long int ans=modpow(i,p/2);
	return ((((i%P)*(ans%P))%P)*(ans%P))%P;
}
long long int inversemod(long long int i)
{
	return modpow(i,P-2)%P;
}
void update_node(int i,int v,int l=0,int r=L-1,int node=1)
{
	if(r<i || l>i)
		return;
	if(l==r && l==i)
	{
		long long int mult=modpow(B,L-1-i);
		long long int ans=((mult%P)*(v%P))%P;
		tree[node]=ans%P;
		return;
	}
	int mid=(l+r)/2;
	update_node(i,v,l,mid,2*node);
	update_node(i,v,1+mid,r,(2*node)+1);
	tree[node]=(tree[2*node]+tree[(2*node)+1])%P;
}

long long int findsum(int rl,int rr,int l=0,int r=L-1,int node=1)
{
	if(rl>r || rr<l)
		return 0;
	if(l>=rl && r<=rr)
	{
		return tree[node]=tree[node]%P;
	}
	int mid=(l+r)/2;
	return ((findsum(rl,rr,l,mid,2*node)%P)+(findsum(rl,rr,1+mid,r,(2*node)+1)%P))%P;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	char c;
	long long int f,s;
	cin>>B>>P>>L>>N;
	while(!(B==0 &&P==0 &&N==0 &&L==0))
	{
		tree=std::vector<long long int>(4*L,0);
		for(int i=0;i<N;i++)
		{
			cin>>c>>f>>s;
			if(c=='E')
			{
				update_node(f-1,s);
			}
			else
			{
				long long int ans=findsum(f-1,s-1)%P;
				if(s!=L)
				{
					long long int mult=modpow(B,L-s)%P;
					mult=inversemod(mult);
					// printf("Mult %lld\n", mult);
					ans=((ans%P)*(mult%P))%P;
				}
				printf("%lld\n", ans%P);
			}
		}
		printf("-\n");
		cin>>B>>P>>L>>N;
	}
}