// AC
#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<int> > adj;
std::vector<int> is_on;
std::vector<int> tree;
std::vector<bool> is_lazy;
unordered_map<int,int> mp;
std::vector<int> subtree;
void prepare(int node,int & indx)
{
	mp[node]=indx;
	for (auto ch:adj[node])
	{
		indx++;
		prepare(ch,indx);
	}
	subtree[mp[node]] = indx;
}

void dfs(int l,int r,int node=1)
{
	if (l==r)
	{
		tree[node] = is_on[l+1];
		return ;
	}
	int mid = (l+r)>>1;
	dfs(l,mid,2*node);
	dfs(1+mid,r,1+2*node);
	tree[node] = tree[2*node] + tree[2*node+1];
}

void prepare(int n)
{
	int indx = 1;
	prepare(1,indx);
	std::vector<std::vector<int> > mapped_adj(n+1);
	std::vector<int> new_is_on(n+1,0);
	for (int i=1;i<=n;i++)
	{
		int mapped_node = mp[i];
		new_is_on[mapped_node] = is_on[i];
	}
	is_on = new_is_on;
	dfs(0, n-1);
}

void wake_up(int l,int r,int node)
{
	if (!is_lazy[node])
		return ;
	is_lazy[node] = 0;
	tree[node] = (r+1-l)-(tree[node]);
	if (l==r)
		return;
	is_lazy[2*node] = !is_lazy[2*node];
	is_lazy[2*node+1] = !is_lazy[2*node+1];
}

int query(int l,int r, int rl,int rr,int node = 1)
{
	if (l>r)
		return 0;
	wake_up(l,r,node);
	if (l>rr || r<rl)
		return 0;
	if (l>=rl && r<=rr)
	{
		return tree[node];
	}
	int mid = (l+r)>>1;
	return query(l,mid,rl,rr,2*node) + 
			query(1+mid,r,rl,rr,2*node+1);
}

void update(int l,int r, int rl,int rr,int node = 1)
{
	if (l>r)
		return;
	wake_up(l,r,node);
	if (l>rr || r<rl)
		return ;
	if (l>=rl && r<=rr)
	{
		is_lazy[node] = 1;
		wake_up(l,r,node);
		return ;
	}
	int mid = (l+r)>>1;
	update(l,mid,rl,rr,2*node);
	update(1+mid,r,rl,rr,2*node+1);
	tree[node] = tree[2*node] + tree[2*node+1];
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	tree = std::vector<int> (4*n,0);
	is_lazy = std::vector<bool> (4*n,0);
	is_on = std::vector<int> (n+1,0);
	adj = std::vector<std::vector<int> > (n+1);
	subtree = std::vector<int> (n+1,0);
	for (int i=2, p;i<=n;i++)
	{
		cin>>p;
		adj[p].push_back(i);
	}
	for (int i=1,o;i<=n;i++)
	{
		cin>>o;
		is_on[i] = o;
	}
	prepare(n);

	int q;
	cin>>q;
	while(q--)
	{
		string s;
		int node;
		cin>>s>>node;
		int l = mp[node];
		int r = subtree[l];
		if (s=="get")
		{
			// count
			printf("%d\n", query(0,n-1,l-1,r-1));
		}
		else
		{
			// update
			update(0,n-1,l-1,r-1);
		}
	}

}