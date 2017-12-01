/* AC
   Largest Rectangle in Histogram
*/
#include "bits/stdc++.h"
using namespace std;
const int MAX_N = 100000; 
int arr[MAX_N];
int tree[4*MAX_N];
int n;
void build(int l,int r,int node=1)
{
	if (l==r)
	{
		tree[node] = l;
		return ;
	}
	int mid = (l+r)>>1;
	build(l,mid,2*node);
	build(1+mid,r,1+2*node);
	if (arr[tree[2*node]]<=arr[tree[2*node+1]])
		tree[node] = tree[2*node];
	else
		tree[node] = tree[2*node+1];
}

int query(int l,int r,int rl,int rr,int node=1)
{
	if (l>rr || r<rl)
		return -1;
	if (l>=rl && r<=rr)
		return tree[node];
	int mid =(l+r)>>1;
	int l_indx = query(l,mid,rl,rr,2*node);
	int r_indx = query(1+mid,r,rl,rr,1+2*node);
	if (l_indx==-1)
		return r_indx;
	if (r_indx==-1)
		return l_indx;
	if (arr[l_indx]<=arr[r_indx])
		return l_indx;
	return r_indx;
}

long long int solve(int l,int r)
{
	if (l>r)
		return -2;
	if (l==r)
		return arr[l];
	int min_val_indx = query(0,n-1,l,r);
	long long int min_val = arr[min_val_indx];
	long long int ans = min_val *(r+1-l);
	return max(ans, max(solve(l,min_val_indx-1),solve(1+min_val_indx,r)));
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	scanf("%d", &n);
	while(n)
	{
		for (int i=0,h;i<n;i++)
		{
			scanf("%d", &h);
			arr[i] = h;
		}
		build(0,n-1);
		printf("%lld\n", solve(0,n-1));
		scanf("%d", &n);
	}	
}