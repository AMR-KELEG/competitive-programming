//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<long long int> color; 
std::vector<int> lazyColor;
std::vector<long long int> sum;
std::vector<long long int> lazyAdd;
void build(int node,int l,int r)
{
	if(l==r)
	{
		color[node]=l+1;
		return ;
	}
	int mid=(l+r)>>1;
	build(2*node,l,mid);
	build(2*node+1,1+mid,r);
	color[node]=-1;
}
void lazyProp(int node,int l,int r)
{
	if(l==r)
	{
		if(lazyColor[node])
		{
			color[node]=lazyColor[node];
			lazyColor[node]=0;
		}
		if(lazyAdd[node])
		{
			sum[node]+=lazyAdd[node];
			lazyAdd[node]=0;
		}
		return ;
	}
	if(lazyColor[node])
	{
		color[node]=lazyColor[node];
		lazyColor[2*node]=lazyColor[node];
		lazyColor[2*node+1]=lazyColor[node];
		lazyColor[node]=0;
	}
	if(lazyAdd[node])
	{
		sum[node]+=lazyAdd[node];
		//Wrong assumption here
		int mid=(l+r)>>1;
		lazyAdd[node]/=(r+1-l);
		lazyAdd[2*node]+=lazyAdd[node]*(mid+1-l);
		lazyAdd[2*node+1]+=lazyAdd[node]*(r-mid);
		lazyAdd[node]=0;
	}
}

long long int query(int node,int l,int r,int rl,int rr)
{
	lazyProp(node,l,r);
	if(l>rr || r<rl)
	{
		return 0;
	}
	if(l>=rl && r<=rr)
	{
		// cout<<l<<" "<<r<<" "<<color[node]<<" "<<sum[node]<<endl;
		return sum[node];
	}
	int mid=(l+r)>>1;
	return query((2*node),l,mid,rl,rr)+query((2*node)+1,1+mid,r,rl,rr);
}

void update(int node,int l,int r,int rl,int rr,int c)
{
	lazyProp(node,l,r);
	if(l>rr || r<rl)
	{
		return ;
	}
	if(l>=rl && r<=rr)
	{
		if(color[node]!=-1)
		{
			long long int dC=abs(c-color[node]);
			long long int add=dC*(r+1-l);
			sum[node]+=add;
			color[node]=c;
			if(l==r)
			{
				// cout<<"IN: "<<l<<" "<<sum[node]<<endl;
				return;
			}
			int mid=(l+r)>>1;
			lazyAdd[2*node]+=(mid+1-l)*dC;
			lazyAdd[2*node+1]+=(r-mid)*dC;
			lazyColor[2*node]=c;
			lazyColor[2*node+1]=c;
			return;
		}
	}
	int mid=(l+r)>>1;
	update(2*node,l,mid,rl,rr,c);
	update(2*node+1,1+mid,r,rl,rr,c);
	lazyProp(2*node,l,mid);
	lazyProp(2*node+1,1+mid,r);
	if(color[2*node]==color[2*node+1])
		color[node]=color[2*node];
	else
		color[node]=-1;
	sum[node]=sum[2*node]+sum[2*node+1];
}

int main()
{
	// std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	color=std::vector<long long int> (4*n);
	lazyColor=std::vector<int> (4*n,0);
	sum=std::vector<long long int> (4*n,0);
	lazyAdd=std::vector<long long int> (4*n,0);	
	build(1,0,n-1);
	while(m--)
	{
		int t;
		cin>>t;
		if(t==1)
		{
			//Update 
			int l,r,x;
			cin>>l>>r>>x;
			l--;r--;
			// void update(int node,int l,int r,int rl,int rr,int c)
			update(1,0,n-1,l,r,x);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			// cout<<"Q: "<<l<<" "<<r<<endl;
			printf("%lld\n", query(1,0,n-1,l,r));
		}
	}

}