//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> tree;
std::vector<int> lazy;
int n;
void update_range(int rl,int rr,int v,int l=0,int r=n-1,int node=1)
{
	if(r<rl || l>rr)
		return ;
	if(l>=rl && r<=rr)
	{
		tree[node]+=lazy[node]+v;
		if(l!=r)
		{
			lazy[2*node]+=lazy[node]+v;
			lazy[1+(2*node)]+=lazy[node]+v;	
		}
		lazy[node]=0;
		return ;
	}
	if(lazy[node]!=0)
	{
		tree[node]+=lazy[node];
		if(l!=r)
		{
			lazy[2*node]+=lazy[node];
			lazy[1+(2*node)]+=lazy[node];
		}
		lazy[node]=0;
	}
	int mid=(l+r)/2;
	update_range(rl,rr,v,l,mid,2*node);
	update_range(rl,rr,v,1+mid,r,1+(2*node));
	tree[node]=tree[2*node]+tree[(2*node)+1];
}
int query(int rl,int rr,int l=0,int r=n-1,int node=1)
{
	if(r<rl || l>rr)
		return 0;
	if(lazy[node]!=0)
	{
		tree[node]+=lazy[node];
		if(l!=r)
		{
			lazy[2*node]+=lazy[node];
			lazy[1+(2*node)]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(l>=rl && r<=rr)
	{
		return tree[node];
	}
	int mid=(l+r)/2;
	return query(rl,rr,l,mid,2*node)+query(rl,rr,1+mid,r,1+(2*node));
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	tree=std::vector<int> (4*n,0);
	lazy=std::vector<int> (4*n,0);
	std::vector<int> a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];

	std::vector<int> fcs(n+1,0),suff(n+1,0);
	map<int,int>countmp;
	suff[n]=1;
	fcs[1]++;
	countmp[a[n]]++;
	update_range(0,suff[n]-1,1);
	for(int i=n-1;i>1;i--)
	{
		suff[i]=++countmp[a[i]];
		// cout<<suff[i]<<endl;
		update_range(0,suff[i]-1,1);
	}
	for(int i=0;i<n;i++)
	{
		cout<<"From "<<0<<" to "<<i+1<<" "<<query(0,i)<<endl;
	}
	map<int,int>cmp;
	long long int ans=0;
	int curf=0;
	++cmp[a[1]];
	for(int i=2;i<n;i++)
	{
		curf=++cmp[a[i]];
		cout<<curf<<endl;
		if(curf>1)
			ans+=query(0,curf-2);
		update_range(0,suff[i]-1,-1);
	}
	cout<<ans;
}