//AC
#include "bits/stdc++.h"
#define segmentProp pair<pair<long long int,long long int>,pair<long long int,long long int>>
#define segM first.first
#define segS first.second
#define segML second.first
#define segMR second.second
#define emptySeg {{-800000000,0},{-800000000,-800000000}}
using namespace std;
int n;
std::vector<long long int> v;
std::vector<long long int> maxS,maxLS,maxRS,tot;

void build(int l,int r,int node=1)
{
	if(l==r)
	{
		tot[node]=maxS[node]=maxLS[node]=maxRS[node]=v[l];
		return ;
	}
	int mid=(l+r)>>1;
	int L=2*node,R=2*node+1;
	build(l,mid,L);
	build(1+mid,r,R);
	tot[node]=tot[L]+tot[R];
	maxLS[node]=max(maxLS[L],tot[L]+maxLS[R]);
	maxRS[node]=max(maxRS[R],maxRS[L]+tot[R]);
	maxS[node]=max(max(max(maxLS[node],maxRS[L]+maxLS[R]),max(maxS[L],maxS[R])),max(maxRS[node],tot[node]));
}

void update(int in,int val,int l,int r,int node=1)
{
	if(l>in || r<in)
		return ;
	if(l==r)
	{
		tot[node]=maxS[node]=maxLS[node]=maxRS[node]=val;
		v[in]=val;
		return ;
	}
	int L=2*node,R=2*node+1;
	int mid=(l+r)>>1;
	update(in,val,l,mid,L);
	update(in,val,1+mid,r,R);
	tot[node]=tot[L]+tot[R];
	maxLS[node]=max(maxLS[L],tot[L]+maxLS[R]);
	maxRS[node]=max(maxRS[R],maxRS[L]+tot[R]);
	maxS[node]=max(max(max(maxLS[node],maxRS[L]+maxLS[R]),max(maxS[L],maxS[R])),max(maxRS[node],tot[node]));
}

segmentProp query(int l,int r,int rl,int rr,int node=1)
{
	if(l>rr || r<rl)
	{
		return emptySeg;
	}
	if(l>=rl && r<=rr)
	{
		return {{maxS[node],tot[node]},{maxLS[node],maxRS[node]}};
	}
	int mid=(l+r)>>1;
	int L=2*node;
	int R=2*node+1;
	segmentProp lseg(query(l,mid,rl,rr,L));
	segmentProp rseg(query(mid+1,r,rl,rr,R));
	if(lseg==segmentProp(emptySeg))
		return rseg;
	if(rseg==segmentProp(emptySeg))
		return lseg;
	long long int stot=lseg.segS+rseg.segS;
	long long int smaxLS=max(lseg.segML,lseg.segS+rseg.segML);
	long long int smaxRS=max(rseg.segMR,rseg.segS+lseg.segMR);
	long long int smaxS=max(max(max(stot,lseg.segMR+rseg.segML)
					,max(lseg.segM,rseg.segM)),max(smaxLS,smaxRS));
	return {{smaxS,stot},{smaxLS,smaxRS}};
}

int brute(int rl,int rr)
{
	int ans=v[rl];
	for(int l=rl;l<=rr;l++)
	{
		int curSum=0;
		for(int r=l;r<=rr;r++)
		{
			curSum+=v[r];
			ans=max(ans,curSum);
		}
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	v=std::vector<long long int> (n);
	maxS=std::vector<long long int> (4*n);
	maxLS=std::vector<long long int> (4*n);
	maxRS=std::vector<long long int> (4*n);
	tot=std::vector<long long int> (4*n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	build(0,n-1);
	int q;
	cin>>q;
	while(q--)
	{
		int t,l,r;
		cin>>t>>l>>r;
		if(t)
		{
			l--;r--;
			printf("%d\n",query(0,n-1,l,r).segM);
		}
		else
		{
			l--;
			update(l,r,0,n-1);
		}
	}
}