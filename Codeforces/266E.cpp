/* AC
   Segment Tree + Newton's binomial theorem
*/
#include "bits/stdc++.h"
using namespace std;
const int MOD = 1000000007;
int arr[100001];
long long int tree[6][400000]; // power from 0 to 5
long long int unweighted_tree[6][400000]; // power from 0 to 5
bool lazy[400000];
long long int lazy_val[400000];

int nCr[6][6];
void build(int l,int r,int node = 1)
{
	if (l==r)
	{
		long long int val = 1;
		unweighted_tree[0][node] = val;
		tree[0][node] = (unweighted_tree[0][node] * arr[l]) % MOD;
		for (int i=1;i<6;i++)
		{
			val = (val*l) % MOD;
			unweighted_tree[i][node] = val;
			tree[i][node] = (unweighted_tree[i][node] * arr[l]) % MOD;
		}
		return ;
	}
	int mid = (l+r)>>1;
	build(l,mid,2*node);
	build(1+mid,r,1+2*node);
	for (int i=0;i<6;i++)
	{
		unweighted_tree[i][node] = (unweighted_tree[i][2*node] + unweighted_tree[i][1+2*node]) % MOD;
		tree[i][node] = (tree[i][2*node] + tree[i][2*node+1]) % MOD;
	}
}

void relax(int l,int r,int node)
{
	if (!lazy[node])
	{
		return ;
	}
	lazy[node] = 0;
	for (int k=0;k<6;k++)
		tree[k][node] = (unweighted_tree[k][node] * lazy_val[node]) % MOD;
	if (l==r)
	{
		return ;
	}
	lazy[2*node] = 1;
	lazy[2*node+1] = 1;
	lazy_val[2*node] = lazy_val[node];
	lazy_val[2*node+1] = lazy_val[node];
}

int query(int l,int r,int rl,int rr,int K,int node = 1)
{
	if (l>r)
		return 0;
	relax(l,r,node);
	if (l>rr || r<rl)
		return 0;
	if (l>=rl && r<=rr)
	{
		return tree[K][node];
	}
	int mid = (l+r)>>1;
	return (query(l,mid,rl,rr,K,2*node) + 
			query(1+mid,r,rl,rr,K,2*node+1))%MOD;
}

int solve(int l,int r,int K,int n)
{
	long long int ans = 0;
	long long int cur_const = nCr[K][0];
	long long int cur_const_2 = 1;
	long long int cur_ans = query(1,n,l,r,K);
	// cout<<l<<" "<<r<<endl;
	// cout<<cur_ans<<endl;
	ans = cur_ans % MOD;
	for (int i=1;i<=K;i++)
	{
		cur_const = nCr[K][i];
		cur_const_2 *= 1-l;
		if(cur_const_2<0)
		{
			long long int c = ceil(1.0*abs(cur_const_2)/MOD);
			cur_const_2 += c*MOD;
		}
		cur_const_2 %= MOD;
		cur_ans = (((query(1,n,l,r,K-i)*cur_const)%MOD)*cur_const_2) % MOD;
		ans = (ans + cur_ans) % MOD;
	}
	return ans % MOD;
}

void update(int l,int r,int rl,int rr,int v,int node = 1)
{
	if (l>r)
		return ;
	relax(l,r,node);
	if (l>rr || r<rl)
		return ;
	if (l>=rl && r<=rr)
	{
		lazy[node] = 1;
		lazy_val[node] = v;
		relax(l,r,node);
		return ;
	}
	int mid = (l+r)>>1;
	update(l,mid,rl,rr,v,2*node);
	update(1+mid,r,rl,rr,v,1+2*node);
	for (int k=0;k<6;k++)
	{
		tree[k][node] = (tree[k][2*node+1] + tree[k][2*node]) % MOD;
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	for (int i=0;i<6;i++)
	{
		nCr[i][0] = 1;
		for (int j=1;j<=i;j++)
		{
			nCr[i][j] = nCr[i][j-1] * (i+1-j) / j;
		}
	}
	int n,q;
	scanf("%d %d", &n, &q);
	for (int i=1,v;i<=n;i++)
	{
		scanf("%d", &v);
		arr[i] = v;
	}
	build(1,n);
	while(q--)
	{
		char ty;
		scanf("%c ", &ty);
		while (ty!='?' && ty!='=')
			scanf("%c ", &ty);
		if (ty=='?')
		{
			int l,r,k;
			scanf("%d %d %d", &l, &r, &k);
			printf("%d\n", solve(l,r,k,n));
		}
		else
		{
			int l,r,v;
			scanf("%d %d %d", &l, &r, &v);
			update(1,n,l,r,v);
		}
	}

}