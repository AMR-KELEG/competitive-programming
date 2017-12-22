/* AC
 No of triplets i<j<k and ai>aj>ak
 Merge Sort Segment Tree
*/

#include "bits/stdc++.h"
using namespace std;

std::vector<int> v;
std::vector<std::vector<int> > tree;

void build(int l, int r, int node=1)
{
	if(l==r)
	{
		tree[node] = std::vector<int> (1,v[l]);
		return;
	}
	int mid = (l+r)>>1;
	build(l,mid,2*node);
	build(1+mid,r,1+2*node);
	tree[node] = std::vector<int> (r+1-l);
	merge(tree[2*node].begin(), tree[2*node].end(), 
		tree[1+2*node].begin(), tree[1+2*node].end(),
		tree[node].begin());
}

long long int query(int l, int r, const int rl, const int rr, 
					const int val, const bool less,int node = 1)
{
	if (l>rr || r<rl)
		return 0;
	if (l>=rl && r<=rr)
	{
		if (less)
		{
			return lower_bound(tree[node].begin(), tree[node].end(), val) 
			- tree[node].begin();
		}
		else
		{
			return (r+1-l) - (lower_bound(tree[node].begin(), tree[node].end(), 1+val) 
						- tree[node].begin());	
		}
	}
	int mid = (l+r)>>1;
	return query(l,mid,rl,rr,val,less,2*node) + 
			query(1+mid,r,rl,rr,val,less,2*node+1);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	scanf("%d", &n);
	tree = std::vector<std::vector<int> > (4*n);
	v = std::vector<int> (n);
	for (int i=0,_;i<n;i++)
	{
		scanf("%d", &_);
		v[i] = _;
	}
	build(0, n-1);
	long long int ans = 0;
	for (int i=1;i<n-1;i++)
	{
		//
		long long int val = query(0,n-1,0,i-1,v[i],0) * query(0,n-1,i+1,n-1,v[i],1);
		ans += val;
	}
	printf("%I64d\n", ans);
}