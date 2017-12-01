// WA
#include "bits/stdc++.h"
using namespace std;
std::vector<int> tree;
std::vector<std::vector<int> > grid;
void build(int r1,int r2,int c1,int c2,int node = 1)
{
	// cout<<node<<": "<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<endl;
	if (r1>r2 || c1>c2)
	{
		tree[node] = 0;
		return ;
	}
	if (r1==r2 && c1 == c2)
	{
		tree[node] = grid[r1][c1];
		return ;
	}
	int midr = (r1+r2)>>1;
	int midc = (c1+c2)>>1;
	
	build(r1,midr,c1,midc,4*node-2);
	build(1+midr,r2,c1,midc,4*node-1);
	build(r1,midr,midc+1,c2,4*node);
	build(1+midr,r2,midc+1,c2,4*node+1);
	tree[node] =-1;
	if (tree[4*node] !=-1)
	{
		set<int> s;
		int val = -1;
		for (int i=-2;i<2;i++)
		{
			if (tree[4*node +i])
			{
				val = tree[4*node +i];
				s.insert(tree[4*node+i]);
			}
		}
		if (s.size() ==1)
			tree[node] = val;
	}
}

long long int range_sum(int st,int en)
{
	long long int D = en+1-st;
	return ((D)*(D+1))/2;
}

long long int query(int r1,int r2,int c1,int c2,int node = 1)
{
	if (r1>r2 || c1>c2)
		return 0;
	if (tree[node] !=-1)
	{
		return range_sum(r1,r2) * range_sum(c1,c2);
	}
	int midr = (r1+r2)>>1;
	int midc = (c1+c2)>>1;
	// if (r1 == r2)
	// {
	// 	return query(r1,r2,c1,midc,4*node)+
	// 	query(r1,r2,1+midc,c2,4*node+1);
			
	// }
	// if (c1==c2)
	// {
	// 	return query(r1,midr,c1,c2,4*node-2)+
	// 	query(1+midr,r2,c1,c2,4*node-1);	
	// }
	return query(r1,midr,c1,midc,4*node-2) +
	query(1+midr,r2,c1,midc,4*node-1) +
	query(r1,midr,midc+1,c2,4*node) +
	query(1+midr,r2,midc+1,c2,4*node+1);

	// query(r1,midr,c1,c2,4*node-2) +
	// 		query(1+midr,r2,c1,c2,4*node-1) +
	// 		query(r1,r2,c1,midc,4*node) +
	// 		query(r1,r2,1+midc,c2,4*node+1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while (T--)
	{
		int R,C;
		cin>>R>>C;
		int n = max(R,C);
		tree = std::vector<int> (8*n*n,-1);
		grid = std::vector<std::vector<int> > (R,std::vector<int> (C));
		for (int r=0;r<R;r++)
			for (int c=0;c<C;c++)
				cin>>grid[r][c];
		build(0,R-1,0,C-1);
		cout<<query(0,R-1,0,C-1)<<"\n";
	}	
}