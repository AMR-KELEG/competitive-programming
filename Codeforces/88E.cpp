// AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> gr, tree;
void update(int l, int r, int idx, int val, int node=1)
{
	if (l>idx || r<idx)
		return ;
	if (l==r)
	{
		tree[node] = val;
		return ;
	}
	int mid = (l+r)>>1;
	update(l,mid,idx,val,2*node);
	update(1+mid,r,idx,val,1+2*node);
	tree[node] = tree[2*node] ^ tree[2*node+1];
}

int query(int l,int r,int rl,int rr,int node=1)
{
	if (l>rr || r<rl)
		return 0;
	if (l>=rl && r<=rr)
		return tree[node];
	int mid = (l+r)>>1;
	return query(l,mid,rl,rr,2*node) ^ query(1+mid,r,rl,rr,2*node+1);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	scanf("%d", &n);
	gr = std::vector<int> (n+1,0);
	tree = std::vector<int> (4*(n+1), 0);
	for (int i=3;i<=n;i++)
	{
		// try to divide it
		set<int>s;
		for (long long int k=2;k<=i;k++)
		{
			long long int ak = 2*i - k*k + k;
			if (ak % (2*k) == 0)
			{
				// try to solve
				ak/=2*k;
				s.insert(query(0,n,ak,ak+k-1));
			}
			else
			{
				ak/=2*k;
			}
			if (ak<1)
				break; 
		}
		for (int j=0;j<=n;j++)
		{
			if (s.find(j) == s.end())
			{
				update(0,n,i,j);
				gr[i] = j;
				break;
			}
		}
	}
	if (gr[n])
	{
		for (long long int k=2;k<=n;k++)
		{
			long long int ak = 2*n - k*k + k;
			if (ak % (2*k) == 0)
			{
				// try to solve
				ak/=2*k;
				int nim_val = query(0,n,ak,ak+k-1);
				if (!nim_val)
				{
					cout<<k;
					return 0;
				}
			}
			
		}
	}
	else
	{
		cout<<-1;
	}
}