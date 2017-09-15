//AC
#include "bits/stdc++.h"
using namespace std;
int n;
std::vector<int> pot;
std::vector<int> tree;
void build_tree(int node=1,int l=0,int r=n-1)
{
	if(l==r)
	{
		tree[node]=pot[l];
		return ;
	}
	int mid=(l+r)/2;
	build_tree(2*node,l,mid);
	build_tree(1+(2*node),mid+1,r);
	tree[node]=tree[2*node]+tree[1+(2*node)];
}
void update(int in,int v,int node=1,int l=0,int r=n-1)
{
	if(in<l || in>r)
	{
		return ;
	}
	if(in==l && l==r)
	{
		tree[node]=v;
		return;
	}
	int mid=(l+r)/2;
	update(in,v,2*node,l,mid);
	update(in,v,(2*node)+1,mid+1,r);
	tree[node]=tree[2*node]+tree[1+(2*node)];
}
int query(int rl,int rr,int node=1,int l=0,int r=n-1)
{
	// cout<<l<<" "<<r<<" "<<tree[node]<<endl;
	if(l>rr || r<rl)
	{
		return 0;
	}
	if(l>=rl && r<=rr)
	{
		return tree[node];
	}
	int mid=(l+r)/2;
	return query(rl,rr,2*node,l,mid)+query(rl,rr,1+(2*node),mid+1,r);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	int i=1;
	while(n!=0)
	{
		printf("Case %d:\n", i++);
		// cout<<"N "<<n<<endl;
		pot=std::vector<int> (n);
		tree=std::vector<int> (4*n);
		for(int i=0;i<n;i++)
			cin>>pot[i];
		//,cout<<pot[i]<<" p"<<endl;

		build_tree();
		string op;
		cin>>op;
		int x,y;
		// cout<<op<<endl;
		while(op!="END")
		{
			cin>>x>>y;
			if(op=="M")
			{
				printf("%d\n",query(x-1,y-1));
				// cout<<query(0,0)<<endl<<<<" "<<tree[node]endl;
			}
			else
			{
				update(x-1,y);
			}
			cin>>op;
		}
		/*
		*/
		cin>>n;
		if(n>0)
		printf("\n");
	}		
}