//AC
#include "bits/stdc++.h"
using namespace std;
string s;
std::vector<int> open,closed;
int n;
void build_tree(int node=1,int l=0,int r=n-1)
{
	if(l==r)
	{
		if(s[l]=='(')
		{
			open[node]=1;
		}
		else
		{
			closed[node]=1;
		}
		return;
	}
	int mid=(l+r)/2;
	build_tree(2*node,l,mid);
	build_tree((2*node)+1,mid+1,r);
	open[node]=open[(2*node)+1];
	closed[node]=closed[(2*node)];
	if(open[(2*node)]>closed[(2*node)+1])
		open[node]+=open[(2*node)]-closed[(2*node)+1];
	else
		closed[node]+=closed[(2*node)+1]-open[(2*node)];	
}
pair<int,int> query(int rl,int rr,int node=1,int l=0,int r=n-1) // open closed
{
	if(r<rl || l>rr)
	{
		return pair<int,int>(0,0);
	}
	if(l>=rl && r<=rr)
	{
		return pair<int,int>(open[node],closed[node]);
	}
	int mid=(l+r)/2;
	pair<int,int> ln=query(rl,rr,2*node,l,mid);
	pair<int,int> rn=query(rl,rr,(2*node)+1,mid+1,r);
	pair<int,int> ans;
	ans.first=rn.first;
	ans.second=ln.second;
	if(ln.first>rn.second)
		ans.first+=ln.first-rn.second;
	else
		ans.second+=rn.second-ln.first;
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>s;
	n=s.size();
	open=std::vector<int> (4*n,0);
	closed=std::vector<int> (4*n,0);
	int m;
	cin>>m;
	build_tree();
	int l,r;
	while(m--)
	{
		cin>>l>>r;
		l--;
		r--;
		pair<int,int> a=query(l,r);
		printf("%d\n", r+1-l-(a.first+a.second));
	}
}