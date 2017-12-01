// TLE
#include "bits/stdc++.h"
using namespace std;
#define Range pair<int,pair<int,int>>
#define L first
#define R second.first
#define I second.second
int SQRT;
const int N = 1+2*100000;
bool cmp(const Range & ran1, const Range & ran2)
{
	int b1 = ran1.R/SQRT;
	int b2 = ran2.R/SQRT;
	if (b1!=b2)
		return b1<b2;
	return ran1.L<ran2.L;
}

int tree[4*N];

inline void update(int indx, bool inc, int l=0, int r=N-1, int node=1)
{
	if (l>indx || r<indx)
		return ;
	if (l==r)
	{
		if (inc)
			tree[node] ++;
		else
			tree[node] --;
		return ;
	}
	int mid = (l+r)>>1;
	update(indx, inc, l, mid, 2*node);
	update(indx, inc, 1+mid, r, 2*node+1);	
	tree[node] = max(tree[2*node], tree[2*node+1]);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	scanf("%d", &n);
	while(n)
	{
		memset(tree, 0, sizeof tree);
		SQRT = sqrt(n);
		int q;
		cin>>q;
		std::vector<int> v(n);
		for (int i=0,a;i<n;i++)
		{
			scanf("%d", &a);
			v[i] = a;
		}
		std::vector<Range> Q(q);
		std::vector<int> ans(q);
		for (int i=0,l,r;i<q;i++)
		{
			scanf("%d %d", &l, &r);
			Q[i].L = l-1;
			Q[i].R = r-1;
			Q[i].I = i;
		}
		sort(Q.begin(), Q.end(), cmp);
		int mo_l = 0;
		int mo_r = -1;
		for (auto qu:Q)
		{
			int l = qu.L;
			int r = qu.R;
			int i = qu.I;
			while(mo_l<l)
			{
				// erase mo_l
				update(v[mo_l]+100000,0);
				mo_l++;
			}
			while(mo_l>l)
			{
				// add mo_l
				mo_l--;
				update(v[mo_l]+100000,1);
			}
			while(mo_r<r)
			{
				mo_r++;	
				update(v[mo_r]+100000,1);
			}
			while(mo_r>r)
			{
				// erase mo_r
				update(v[mo_r]+100000,0);
				mo_r--;
			}
			ans[i] = tree[1];
		}
		for (int i=0;i<q;i++)
			printf("%d\n", ans[i]);
		scanf("%d", &n);
	}	
}