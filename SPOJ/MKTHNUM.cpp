//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<int> > tree;
std::vector<int> a;
int n,q;
void build_tree(int node,int l,int r)
{
	tree[node]=std::vector<int> (r+1-l);
	if(l==r)
	{
		tree[node][0]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build_tree(2*node,l,mid);
	build_tree(2*node+1,1+mid,r);
	merge(tree[node*2].begin(), tree[node*2].end(),
				tree[node*2+1].begin(), tree[node*2+1].end()
				,tree[node].begin());
}

//No of elements in range less than val
int query(int node,int l,int r,int rl,int rr,int val)
{
	if(l>rr || r<rl)
		return 0;
	if(l>=rl && r<=rr)
	{
		//Do lower_bound here
		return lower_bound(tree[node].begin(), tree[node].end(),val)-tree[node].begin();
	}
	int mid=(l+r)>>1;
	return query(2*node,l,mid,rl,rr,val)+query(2*node+1,1+mid,r,rl,rr,val);
}

int solve(int rl,int rr,int indx)
{
	//Do binary search
	//Search for val that has no of elements=indx
	int l=-1000000000,r=1000000000;
	int mid=(l+r+1)>>1;
	while(l<r)
	{
		// cout<<l<<" "<<r<<endl;
		mid=(l+r+1)>>1;
		int noOfElements=query(1,0,n-1,rl,rr,mid);
		if(noOfElements>indx)
			r=mid-1;
		else l=mid;
	}
	return (l+r+1)>>1;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>q;
	a=std::vector<int> (n);
	tree=std::vector<std::vector<int> > (4*n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	build_tree(1,0,n-1);
	int l,r,k;
	while(q--)
	{
		cin>>l>>r>>k;
		l--;r--;k--;
		//Query
		printf("%d\n", solve(l,r,k));
	}
}