//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> surviviors,winner;
int n,m;
void build_tree(int node=1,int l=0,int r=n-1)
{
	if(l==r)
	{
		surviviors[node]=1;
		return ;
	}
	int mid=(l+r)/2;	
	build_tree(2*node,l,mid);
	build_tree(1+(2*node),mid+1,r);
	surviviors[node]=r+1-l;
	// cout<<l<<" "<<r<<" "<<surviviors[node]<<endl;
}
void update(int a,int b,int x,int node=1,int l=0,int r=n-1)
{
	if(r<a || l>b)
	{
		return;
	}
	if(surviviors[node]==0)
		return ;

	if(surviviors[node]==r+1-l && l>=a && r<=b)
	{
		surviviors[node]=0;
		for(int i=l;i<=r;i++)
		{
			if(i==x)
			{
				surviviors[node]++;
				continue;
			}
			// printf("l r %d %d %d %d\n",l,r,i, x);
			if(winner[i]==0)
				winner[i]=x+1;
		}
		return ;
	}
	/*
	*/
	int mid=(l+r)/2;	
	update(a,b,x,2*node,l,mid);
	update(a,b,x,1+(2*node),mid+1,r);
	surviviors[node]=surviviors[node*2]+surviviors[1+(2*node)];
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>m;	
	winner=std::vector<int> (n+1,0);
	surviviors=std::vector<int> (4*n);
	build_tree();
	int l,r,x;
	while(m--)
	{
		cin>>l>>r>>x;
		update(l-1,r-1,x-1);
		/*
		printf("\n");
		*/
	}
		for(int i=0;i<n;i++)
			printf("%d ", winner[i]);
}