//AC
#include <bits/stdc++.h>
#define INF (1000000009)
using namespace std;
std::vector<int> v;
std::vector<int> tree;
void build(int node,int l,int r)
{
	if(l==r)
	{
		tree[node]=v[l];
		return;
	}
	int mid=(l+r)>>1;
	build(2*node,l,mid);
	build(2*node+1,1+mid,r);
	tree[node]=min(tree[2*node],tree[2*node+1]);
}

int query(int node,int rl,int rr,int l,int r)
{
	if(l>rr || r<rl)
		return INF;
	if(l>=rl && r<=rr)
		return tree[node];
	int mid=(l+r)>>1;
	return min(query(2*node,rl,rr,l,mid),query(2*node+1,rl,rr,1+mid,r));
}
int main()
{
	std::ios_base::sync_with_stdio(0);
	freopen("in.txt","r",stdin);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		printf("Scenario #%d:\n",t);
		int n,q;
		cin>>n>>q;
		v=std::vector<int> (n);
		tree=std::vector<int> (4*n);
		for(int i=0;i<n;i++)cin>>v[i];
		build(1,0,n-1);
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			l--;r--;
			printf("%d\n", query(1,l,r,0,n-1));
		}
	}
}