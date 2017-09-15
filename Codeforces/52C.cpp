//AC
#include "bits/stdc++.h"
using namespace std;
int n;
std::vector<long long int > a,lazy,tree;
int countspaces(string & s)
{
	int ans=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==' ')
			ans++;
	}
	return ans;
}

void build_tree(int node=1,int l=0,int r=n-1)
{
	if(l==r)
	{
		tree[node]=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build_tree(2*node,l,mid);
	build_tree((2*node)+1,1+mid,r);
	tree[node]=min(tree[(2*node)],tree[(2*node)+1]);	
}

void lazy_update(int rl,int rr,int val,int node=1,int l=0,int r=n-1)
{
	if(lazy[node])
	{
		if(l==r)
		{
			tree[node]+=lazy[node];
			lazy[node]=0;
		}
		else
		{
		tree[node]+=lazy[node];
		lazy[2*node]+=lazy[node];
		lazy[(2*node)+1]+=lazy[node];
		lazy[node]=0;
		}
	}
	if(l>rr || r<rl)
	{
		return ;
	}
	if(l>=rl && r<=rr)
	{
		if(l==r)
		{
			tree[node]+=val+lazy[node];
			lazy[node]=0;
			return;
		}
		tree[node]+=val+lazy[node];
		lazy[(2*node)]+=val+lazy[node];
		lazy[(2*node)+1]+=val+lazy[node];
		lazy[node]=0;
		return;	
	}
	int mid=(l+r)/2;
	lazy_update(rl,rr,val,2*node,l,mid);
	lazy_update(rl,rr,val,1+(2*node),mid+1,r);
	tree[node]=min(tree[2*node],tree[1+(2*node)]);
}

long long int query(int rl,int rr,int node=1,int l=0,int r=n-1)
{
	if(lazy[node])
	{
		if(l==r)
		{
			tree[node]+=lazy[node];
			lazy[node]=0;
		}
		else
		{
		tree[node]+=lazy[node];
		lazy[2*node]+=lazy[node];
		lazy[(2*node)+1]+=lazy[node];
		lazy[node]=0;
		}
	}
	if(l>rr || r<rl)
	{
		return LLONG_MAX;
	}
	if(l>=rl && r<=rr)
	{
		if(lazy[node]!=0)
		{
			if(l==r)
			{
				tree[node]+=lazy[node];
				lazy[node]=0;
				return tree[node];
			}
			tree[node]+=lazy[node];
			lazy[(2*node)]+=lazy[node];
			lazy[(2*node)+1]+=lazy[node];
			lazy[node]=0;
			return tree[node];
		}
		return tree[node];
	}
	int mid=(l+r)/2;
	return min(query(rl,rr,2*node,l,mid),query(rl,rr,(2*node)+1,mid+1,r));
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int m;
	cin>>n;
	a=std::vector<long long int> (n);
	lazy=std::vector<long long int> (4*n,0);
	tree=std::vector<long long int> (4*n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	build_tree();
	cin>>m;
	string s;
	int l,r,val;
	getline(cin,s);
	while(m--)
	{
		getline(cin,s);
		stringstream ss(s);
		if(countspaces(s)>=2)
		{
			ss>>l>>r>>val;
			if(r<l)
			{
				lazy_update(l,n-1,val);

				lazy_update(0,r,val);
			}
			else
			{
				lazy_update(l,r,val);
			}
		}
		else
		{
			ss>>l>>r;
			long long int va;
			if(r<l)
			{
				va=query(l,n-1);
				va=min(va,query(0,r));
			}
			else
			{
				va=query(l,r);
			}
			printf("%lld\n", va);
		}
	}
}