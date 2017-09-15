//WA
#include "bits/stdc++.h"
using namespace std;
int n;
std::vector<int> v;
std::vector<set<int> > dis;
set<int> build_tree(int node,int i,int j)
{
	if(j<i)
		return set<int>();
	if(j==i)
	{
		dis[node].insert(v[i]);
		// cout<<node<<" "<<dis[node].size()<<" "<<*(dis[node].begin())<<endl;
		return dis[node];
	}
	set<int> ans;
	ans=build_tree((2*node)+1,1+(i+j)/2,j);
	dis[node]=build_tree(2*node,i,(i+j)/2);
	dis[node].insert(ans.begin(),ans.end());
	// cout<<node<<" "<<dis[node].size()<<" "<<*(dis[node].begin())<<endl;
	return dis[node];
}
set<int> query(int node,int a,int b,int i,int j)
{
	// cout<<a<<" "<<b<<" "<<i<<" "<<j<<endl;
	if(a>j || b<i)
		return set<int>();
	if(a<=i && b>=j)
	{
		return dis[node];
	}
	set<int>ans=query(2*node,a,b,i,(i+j)/2);
	set<int>ans2=query((2*node)+1,a,b,1+(i+j)/2,j);
	ans.insert(ans2.begin(),ans2.end());
	return ans;

}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	v=std::vector<int> (n);
	dis=std::vector<set<int> > ((n+2)*ceil(log2(n+2)));
	for(int i=0;i<n;i++)
		cin>>v[i];
	int q;
	cin>>q;
	build_tree(1,0,n-1);
	// cout<<dis[1].size()<<endl;
	int i,j;
	while(q--)
	{
		cin>>i>>j;
		printf("%d\n",query(1,i-1,j-1,0,n-1).size());

	}

}
