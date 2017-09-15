#include "bits/stdc++.h"
using namespace std;
#define ll long long
std::vector<ll> notree,countree,v,lazyno,lazycount;
int n,m,k;
void build_tree(std::vector<ll> & tree,int l=0,int r=n-1,int node=1)
{
	if(l==r)
	{
		tree[node]=v[l];
		return ;
	}
	int mid=(l+r)/2;
	build_tree(tree,l,mid,2*node);
	build_tree(tree,1+mid,r,(2*node)+1);
}
void inc_count(int rl,int rr,ll v,int l=0,int r=n-1,int node=1)
{
	if(lazycount[node])
	{
		if(l==r)
		{
			countree[node]+=lazycount[node];
			lazycount[node]=0;
		}
		else
		{
			countree[node]+=lazycount[node];
			lazycount[2*node]+=lazycount[node];
			lazycount[1+(2*node)]+=lazycount[node];
			lazycount[node]=0;
		}
	}
	if(r<rl || l>rr)
	{
		return ;
	}
	if(l>=rl && r<=rr)
	{
		lazycount[node]+=v;
		return;
	}
	int mid=(l+r)/2;
	inc_count(rl,rr,v,l,mid,2*node);
	inc_count(rl,rr,v,1+mid,(2*node)+1);
}
void inc_val(int rl,int rr,ll v,int l=0,int r=n-1,int node=1)
{
	if(lazyno[node])
	{
		if(l==r)
		{
			notree[node]+=lazyno[node];
			lazyno[node]=0;
		}
		else
		{
			notree[node]+=lazyno[node];
			lazyno[2*node]+=lazyno[node];
			lazyno[1+(2*node)]+=lazyno[node];
			lazyno[node]=0;
		}
	}
	if(r<rl || l>rr)
	{
		return ;
	}
	if(l>=rl && r<=rr)
	{
		lazyno[node]+=v;
		return;
	}
	int mid=(l+r)/2;
	inc_val(rl,rr,v,l,mid,2*node);
	inc_val(rl,rr,v,1+mid,(2*node)+1);
}

ll query_no(int i,int l=0,int r=n-1,int node=1)
{
	if(lazyno[node])
	{
		if(l==r)
		{
			notree[node]+=lazyno[node];
			lazyno[node]=0;
		}
		else
		{
			notree[node]+=lazyno[node];
			lazyno[2*node]+=lazyno[node];
			lazyno[1+(2*node)]+=lazyno[node];
			lazyno[node]=0;
		}
	}
	if(l>i || r<i)
	{
		return 0;
	}
	if(l==r && i==l)
	{
		return notree[node];
	}
	int mid=(l+r)/2;
	return max(query_no(i,l,mid,2*node),query_no(i,1+mid,(2*node)+1);
}


int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	cin>>n>>m>>k;
	ll l,r,d;
	v=std::vector<ll> (n);
	std::vector<ll> inc(m);
	for(int i=0;i<n;i++)
		cin>>v[i];
	for(int i=0;i<m;i++)
	{
		cin>>l>>r>>d;
		l--;
		r--;
		incr()
	}
	// m increments
}