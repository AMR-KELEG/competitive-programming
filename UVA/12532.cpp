//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> v;
std::vector<int> tree;
int n,k;
void build_tree(int node=1,int l=0,int r=n-1)
{
	if(l==r)
	{
		tree[node]=((v[l]>0)?1:(v[l]==0)?0:-1);
		return ;
	}
	int mid=(l+r)/2;
	build_tree(2*node,l,mid);
	build_tree(1+(2*node),mid+1,r);
	tree[node]=tree[(2*node)]*tree[(2*node)+1];
	// cout<<"l "<<l<<" r "<<r<<" val "<<tree[node]<<endl;
}
void update_tree(int node=1,int l=0,int r=n-1,int i=0,int v=0)
{
	if(i<l ||i>r)
		return ;
	if(i==l && i==r)
	{
		tree[node]=v;
		return ;
	}
	int mid=(l+r)/2;
	update_tree(node*2,l,mid,i,v);
	update_tree((node*2)+1,mid+1,r,i,v);
	tree[node]=tree[(2*node)]*tree[(2*node)+1];
	// cout<<endl<<endl<<"l "<<l<<" r "<<r<<" val "<<tree[node]<<endl;
}

int query(int rl,int rr,int node=1,int l=0,int r=n-1)
{
	if(rr<l || rl>r)
	{
		return 1;
	}
	if(l>=rl && r<=rr)
	{
		return tree[node];
	}
	int mid=(l+r)/2;
	// cout<<l<<" "<<r<<endl;
	return query(rl,rr,(2*node),l,mid)*query(rl,rr,(2*node)+1,mid+1,r);
}

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	char c;
	int a,b;
	while(cin>>n>>k)
	{
		v=std::vector<int> (n);
		tree=std::vector<int> (n*4);
		for(int i=0;i<n;i++)
			cin>>v[i];
		build_tree();
		// cout<<query(0,0)<<endl;
		// cout<<query(1,1)<<endl;
		// cout<<query(2,2)<<endl;
		// cout<<query(3,3)<<endl;
		// k=0;
		while(k--)
		{
			cin>>c>>a>>b;
			if(c=='C')
			{
				// void update_tree(int node=1,int l=0,int r=n-1,int i=0,int v=0)
				update_tree(1,0,n-1,a-1,((b>0)?1:(b==0)?0:-1));
			}
			else
			{
				// int query(int rl,int rr,int node=1,int l=0,int r=n-1)
				int ans=query(a-1,b-1);
				if(ans==1)
					printf("+");
				else if(ans==0)
					printf("0");
				else
					printf("-");
			}
		}
		printf("\n");
	}	
}