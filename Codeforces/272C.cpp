//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> a;
std::vector<long long int> maxTree;
std::vector<long long int> lazy;
void build(int l,int r,int node=1)
{
	if(l==r)
	{
		maxTree[node]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	int L=2*node,R=2*node+1;
	build(l,mid,L);
	build(mid+1,r,R);
	maxTree[node]=max(maxTree[L],maxTree[R]);
}

void lazyProp(int node,int l,int r)
{
	if(!lazy[node])return;
	if(l==r)
	{
		maxTree[node]=lazy[node];
		lazy[node]=0;
		return;
	}
	maxTree[node]=lazy[node];
	lazy[2*node]=lazy[node];
	lazy[2*node+1]=lazy[node];
	lazy[node]=0;
}

long long int query(int l,int r,int rl,int rr,int node=1)
{
	lazyProp(node,l,r);
	if(l>rr || r<rl)return 0;
	if(l>=rl && r<=rr)
		return maxTree[node];
	int mid=(l+r)>>1;
	int L=2*node,R=2*node+1;
	return max(query(l,mid,rl,rr,L),query(1+mid,r,rl,rr,R));
}

void update(int l,int r,int rl,int rr,long long int nVal,int node=1)
{
	lazyProp(node,l,r);
	if(l>rr || r<rl)return ;
	if(l>=rl && r<=rr)
	{
		// lazy[node]=nVal;
		maxTree[node]=nVal;
		if(l<r)
		{
			lazy[2*node]=nVal;
			lazy[2*node+1]=nVal;
		}
		return ;
	}
	int mid=(l+r)>>1;
	int L=2*node,R=2*node+1;
	update(l,mid,rl,rr,nVal,L);
	update(1+mid,r,rl,rr,nVal,R);
	maxTree[node]=max(maxTree[L],maxTree[R]);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	a=std::vector<int> (n);
	maxTree=std::vector<long long int> (4*n);
	lazy=std::vector<long long int> (4*n);
	for(int i=0;i<n;i++)cin>>a[i];
	build(0,n-1);
	int m;
	cin>>m;
	while(m--)
	{
		int w,h;
		cin>>w>>h;
		long long int ans=query(0,n-1,0,w-1);
		printf("%lld\n", ans);
		update(0,n-1,0,w-1,ans+h);
	}
}