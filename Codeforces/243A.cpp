#include "bits/stdc++.h"
using namespace std;
const int N = 100000;
int v[N];
int tree[4*N];
inline void build(int l, int r, int node=1)
{
	if (l==r)
	{
		tree[node] = v[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(l, mid, 2*node);
	build(1+mid, r, 1+2*node);
	tree[node] = tree[2*node] | tree[2*node+1];
}

inline int query(int l, int r, const int & rl, const int &rr,int node=1)
{
	if (l>rr || r<rl)
		return 0;
	if (l>=rl && r<=rr)
		return tree[node];
	int mid = (l+r)>>1;
	return query(l, mid, rl, rr, 2*node) | 
		query(1+mid, r, rl, rr, 2*node+1);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	scanf("%d", &n);	
	for (int i=0,_;i<n;i++)
	{
		scanf("%d", &_);
		v[i] = _;
	}
	build(0,n-1);
	set<int> range_values;
	set<int> cur_range;

	int cur_val = v[0];
	range_values.insert(cur_val);
	cur_range.insert(cur_val);
	int l=0;
	int r=n-1;
	while(true)
	{
		// search
		while(l<r)
		{
			int mid = (l+r+1)>>1;
			if (query(0,n-1,0,mid) == cur_val)
			{
				l = mid;
			}
			else
			{
				r = mid-1;
			}
		}
		// go to r+1
		if (r==n-1)
			break;
		cur_val = query(0,n-1,0,r+1);
		range_values.insert(cur_val);
		cur_range.insert(cur_val);
		l = r+1;
		r=n-1;
	}

	for (int st=1;st<n;st++)
	{
		set<int> s;
		s.insert(v[st]);
		for (auto val:cur_range)
		{
			s.insert(v[st]|val);
		}
		for (auto val:s)
		{
			range_values.insert(val);		
		}
		cur_range = s;
	}

	printf("%d\n", (int)range_values.size());
}