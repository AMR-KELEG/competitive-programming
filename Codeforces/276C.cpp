//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> v;
std::vector<int> counter;
std::vector<int> tree;
std::vector<int> lazy;
int n,m;
void update_tree(int rl,int rr,int l=0,int r=n-1,int node=1)
{
	if(l>rr || r<rl)
		return ;
	if(l>=rl && r<=rr)
	{
		if(l==r)
		{
			tree[node]+=lazy[node]+1;
			lazy[node]=0;
			counter[l]=tree[node];
		}
		else
		{
			tree[node]+=lazy[node]+1;
			lazy[2*node]+=lazy[node]+1;
			lazy[(2*node)+1]+=lazy[node]+1;
			lazy[node]=0;	
		}
		return;
	}
	if(lazy[node]!=0)
	{
		tree[node]+=lazy[node];
		lazy[2*node]+=lazy[node];
		lazy[(2*node)+1]+=lazy[node];
		lazy[node]=0;
	}
	int mid=(l+r)/2;
	update_tree(rl,rr,l,mid,2*node);
	update_tree(rl,rr,1+mid,r,(2*node)+1);
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	cin>>n>>m;
	tree=std::vector<int> (4*n,0);
	lazy=std::vector<int> (4*n,0);
	counter=std::vector<int> (n,0);
	v=std::vector<int> (n);
	for(int i=0;i<n;i++)cin>>v[i];
	sort(v.begin(), v.end());
	int l,r;
	for(int i=0;i<m;i++)
	{
		cin>>l>>r;
		update_tree(l-1,r-1);
	}
	for(int i=0;i<n;i++)
		update_tree(i,i);
	sort(counter.begin(),counter.end());
	long long int ans=0;
	for(int i=0;i<n;i++)
	{
		// cout<<counter[i]<<endl;
		ans+=(counter[i]-1)*((long long int)v[i]);
	}
	cout<<ans;





}