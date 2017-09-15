//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> tree;//Count no of ones in range
std::vector<int> v;

void build_tree(int node,int l,int r)
{
	if(l==r)
	{
		tree[node]=v[node];
		return ;
	}
	int mid=(l+r)>>1;
	build_tree(2*node,l,mid);
	build_tree(2*node+1,1+mid,r);
	tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int node,int l,int r,int rl,int rr)
{
	if(l>rr || r<rl)
		return 0;
	if(l>=rl && r<=rr)
		return tree[node];
	int mid=(l+r)>>1;
	return query(2*node,l,mid,rl,rr)+query(2*node+1,1+mid,r,rl,rr);
}

void update(int node,int in,int val,int l,int r)
{
	if(l>in || r<in)
		return ;
	if(l==in && r==in)
	{
		tree[node]=val;
		return ;
	}
	int mid=(l+r)>>1;
	update(2*node,in,val,l,mid);
	update(2*node+1,in,val,1+mid,r);
	tree[node]=tree[2*node]+tree[2*node+1];
}

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	int q;
	cin>>q;
	std::vector<int> Qind(q);
	std::vector<char> Qtype(q);
	set<int>nos;
	
	for(int i=0;i<q;i++)
	{
		cin>>Qtype[i]>>Qind[i];
		if(Qtype[i]!='K')
			nos.insert(Qind[i]);
	}
	tree=std::vector<int> (4*nos.size(),0);
	v=std::vector<int> (nos.size(),0);
	unordered_map<int,int>mp;
	unordered_map<int,int>rmp;
	int i=0;
	for(auto no:nos)
	{
		rmp[i]=no;
		mp[no]=i++;
	}
	for(int i=0;i<q;i++)
	{
		if(Qtype[i]=='I')
		{
			//insert
			update(1,mp[Qind[i]],1,0,nos.size()-1);
		}
		else if(Qtype[i]=='D')
		{
			//Remove
			update(1,mp[Qind[i]],0,0,nos.size()-1);
		}
		else if(Qtype[i]=='K')
		{
			Qind[i]--;
			if(query(1,0,nos.size()-1,0,nos.size()-1)<=Qind[i])
			{
				printf("invalid\n");
				continue;
			}
			int l=0,r=nos.size()-1;
			while(l<r)
			{
				int mid=(l+r)>>1;
				int val=query(1,0,nos.size()-1,0,mid);
				//cout<<"Mid: "<<mid<<" ,Val: "<<val<<endl;
				if(val<Qind[i]+1)
				{
					l=mid+1;
				}
				else
				{
					r=mid;
				}
			}
			int mid=(l+r)>>1;
			printf("%d\n",rmp[mid]);
		}
		else
		{
			//Count
			if(mp[Qind[i]]==0)
				printf("0\n");
			else
				printf("%d\n", query(1,0,nos.size()-1,0,mp[Qind[i]]-1));
		}
	}
}
