//AC
#include "bits/stdc++.h"
using namespace std;
int n;
std::vector<std::vector<int> > adjlist;
std::vector<int> children;
std::vector<float> expected;
int countchildren(int node)
{
	int ans=0;
	for(int i=0;i<adjlist[node].size();i++)
	{
		ans+=1+countchildren(adjlist[node][i]);
	}
	return children[node]=ans;
}
void findexpected(int node,float tp=-0.5,int countsib=n)
{
	/*
			p
		c   c   c
	*/
	float sum=countsib-children[node];
	sum*=0.5;
	sum+=tp+1;
	expected[node]=sum;
	
	// sum+=tp+1;
	
	for(int i=0;i<adjlist[node].size();i++)
	{
		findexpected(adjlist[node][i],sum-0.5,children[node]);
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;		
	adjlist=std::vector<std::vector<int> >(n+1);
	children=std::vector<int> (n+1);
	expected=std::vector<float> (n+1);
	int v;
	for(int i=0;i<n-1;i++)
	{
		cin>>v;
		adjlist[v].push_back(i+2);
	}
	countchildren(1);
	// for(int i=1;i<=n;i++)
	// 	cout<<children[i]<<" ";
	// cout<<"children "<<countchildren(4)<<endl;
	findexpected(1);
	for(int i=1;i<=n;i++)
		printf("%.1f ", expected[i]);
}