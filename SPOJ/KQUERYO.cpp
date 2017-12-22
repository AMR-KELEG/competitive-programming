/* AC
   Offline Segment Tree -> Node == Vector<int>
*/
#include "bits/stdc++.h"
using namespace std;
std::vector<int> V;
std::vector<std::vector<int> > tree;

void build(int l, int r, int node=1)
{
	if (l==r)
	{
		tree[node] = std::vector<int> (1, V[l]);
		return ;
	}
	int mid = (l+r)>>1;
	build(l, mid, 2*node);
	build(1+mid, r, 2*node+1);
	tree[node] = std::vector<int> (r+1-l);
	merge(tree[2*node].begin(), tree[2*node].end(), 
		tree[2*node+1].begin(), tree[2*node+1].end(), tree[node].begin());
}

int query(const int & rl, const int & rr, int l, int r, const int & k, int node=1)
{
	if (r<rl || l>rr)
	{
		return 0;
	}
	if (l>=rl && r<=rr)
	{
		return tree[node].end()-lower_bound(tree[node].begin(), tree[node].end(),k+1);
	}
	int mid = (l+r)>>1;
	return query(rl,rr,l,mid,k,2*node)+query(rl,rr,1+mid,r,k,1+2*node);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	scanf("%d", &n);
	V = std::vector<int> (n);
	tree = std::vector<std::vector<int> > (4*n);
	for (int i=0,v;i<n;i++)
	{
		scanf("%d", &v);
		V[i] = v;
	}
	build(0, n-1);
	int q;
	scanf("%d", &q);
	int ans= 0;
	while(q--)
	{
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c);
		int i = max((ans ^a)-1, 0);
		int j = min(n-1, (ans^b)-1);
		int k = ans^c;
		if (i>j)
		{
			ans = 0;
		}
		else
		{
			ans = query(i,j,0,n-1,k);	
		}
		printf("%d\n", ans);
	}
}