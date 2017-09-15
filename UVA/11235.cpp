//AC
#include "bits/stdc++.h"
using namespace std;
// struct seg;
struct seg
{
	pair<int,int>lef,rig,mv;
	seg():lef(pair<int,int>(0,0)),rig(pair<int,int>(0,0)),mv(pair<int,int>(0,0))
	{

	}
};
int n;
std::vector<int> v;
std::vector<seg >tree; 
void build_tree(int node=1,int l=0,int r=n-1)
{
	if(l==r)
	{
		tree[node].lef=tree[node].rig=tree[node].mv=pair<int,int>(v[l],1);
		return;
	}
	int mid=(l+r)/2;
	build_tree(2*node,l,mid);
	build_tree((2*node)+1,mid+1,r);
	seg ls=tree[2*node];
	seg rs=tree[(2*node)+1];
	seg ans;
	// for left take left of ls or left ls+lr
	if(ls.lef.first==rs.lef.first)
	{
		ans.lef=pair<int,int>(ls.lef.first,ls.lef.second+rs.lef.second);
	}
	else
		ans.lef=ls.lef;
	if(ls.rig.first==rs.rig.first)
	{
		ans.rig=pair<int,int>(ls.rig.first,ls.rig.second+rs.rig.second);
	}
	else
		ans.rig=rs.rig;
	if(ls.rig.first==rs.lef.first)
	{
		ans.mv=pair<int,int>(ls.rig.first,ls.rig.second+rs.lef.second);
	}
	if(ans.mv.second<ls.mv.second)
	{
		ans.mv=ls.mv;	
	}
	if(ans.mv.second<rs.mv.second)
	{
		ans.mv=rs.mv;	
	}
	tree[node]=ans;
}
seg query(int rl,int rr,int node=1,int l=0,int r=n-1)
{
	if(r<rl || l>rr)
	{
		return seg();
	}
	if(l>=rl && r<=rr)
	{
		return tree[node];
	}
	int mid=(l+r)/2;
	seg ls=query(rl,rr,2*node,l,mid);
	seg rs=query(rl,rr,(2*node)+1,1+mid,r);
	seg ans;

	if(ls.lef.first==rs.lef.first)
	{
		ans.lef=pair<int,int>(ls.lef.first,ls.lef.second+rs.lef.second);
	}
	else
		ans.lef=ls.lef;
	if(ls.rig.first==rs.rig.first)
	{
		ans.rig=pair<int,int>(ls.rig.first,ls.rig.second+rs.rig.second);
	}
	else
		ans.rig=rs.rig;
	if(ls.rig.first==rs.lef.first)
	{
		ans.mv=pair<int,int>(ls.rig.first,ls.rig.second+rs.lef.second);
	}
	if(ans.mv.second<ls.mv.second)
	{
		ans.mv=ls.mv;	
	}
	if(ans.mv.second<rs.mv.second)
	{
		ans.mv=rs.mv;	
	}

	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int q;
	int i,j;
	while(cin>>n)
	{
		if(n==0)
			break;
		cin>>q;
		v=std::vector<int> (n);
		tree=std::vector<seg> (4*n);
		// rig=std::vector<pair<int,int> > (4*n);
		// mv=std::vector<pair<int,int> > (4*n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		build_tree();
		while(q--)
		{
			cin>>i>>j;
			printf("%d\n",query(i-1,j-1).mv.second);
		}
	}
}