#include "bits/stdc++.h"
using namespace std;
int n;
std::vector<long long int> maxarea;
std::vector<long long int> minheight;
std::vector<long long int> he;
std::vector<long long int> lh;
std::vector<long long int> rh;
std::vector<long long int> ll;
std::vector<long long int> rl;
void build_tree(int node=1,int l=0,int r=n-1)
{
	if(l==r)
	{
		maxarea[node]=he[l];
		minheight[node]=he[l];
		lh[node]=he[l];
		ll[node]=1;
		rh[node]=he[l];
		rl[node]=1;
		return ;
	}
	int mid=(l+r)/2;
	build_tree(2*node,l,mid);
	build_tree(1+(2*node),mid+1,r);
	minheight[node]=min(minheight[node*2],minheight[(node*2)+1]);
	maxarea[node]=max(max(maxarea[2*node],maxarea[(2*node)+1]),minheight[node]*(r-l+1));
	ll[node]=ll[2*node];
	lh[node]=lh[2*node];
	rl[node]=rl[(2*node)+1];
	rh[node]=rh[(2*node)+1];
	if(lh[(2*node)+1]==rh[2*node])
	{
		maxarea[node]=max(maxarea[node], (rl[2*node]+ll[(2*node)+1])*(rh[2*node]) );
	}

}

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	while(n)
	{
		maxarea=std::vector<long long int> (4*n);
		minheight=std::vector<long long int> (4*n);
		ll=std::vector<long long int> (4*n);
		rl=std::vector<long long int> (4*n);
		lh=std::vector<long long int> (4*n);
		rh=std::vector<long long int> (4*n);
		he=std::vector<long long> (n);
		for(int i=0;i<n;i++)cin>>he[i];
		build_tree();
		printf("%lld\n", maxarea[1]);
		cin>>n;
	}
}