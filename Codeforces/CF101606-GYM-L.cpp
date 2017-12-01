/* AC
LIS in nlog(n) using segment tree
*/

#include "bits/stdc++.h"
using namespace std;
const int N = 1000001;
int tree[4*N];

int query(int l,int r,int rl,int rr,int node=1)
{
	if (rl>r || rr<l || l>r)
		return 0;
	if (l>=rl && r<=rr)
	{
		return tree[node];
	}
	int mid = (l+r)>>1;
	return  max(query(l,mid,rl,rr,2*node),
			query(1+mid,r,rl,rr,2*node+1));
}

void update(int indx,int val,int l,int r,int node=1)
{
	if (l>indx || r<indx || l>r)
		return ;
	if (l==indx && r==l)
	{
		tree[node] = val;
		return ;
	}
	int mid = (l+r)>>1;
	update(indx,val,l,mid,2*node);
	update(indx,val,1+mid,r,2*node+1);
	tree[node] = max(tree[2*node],tree[2*node+1]);
}

int solve(const vector<pair<long long int,int> > & v)
{
	int indx = 0;
	map<int,int>mp; // h - indx
	for (int i=0;i<v.size();i++)
	{
		mp[v[i].second] = 1;
	}
	for (auto it:mp)
	{
		mp[it.first] = indx++;
	}
	std::vector<int> h(v.size());
	for (int i=0;i<v.size();i++)
	{
		h[i] = mp[v[i].second];
	}
	for (int node =0;node<4*h.size();node++)
		tree[node] = 0;
	int ans = 0;
	for (auto H:h)
	{	
		int cur_ans = 1+query(0,h.size()-1,0,H-1);
		ans = max(ans, cur_ans);
		update(H,cur_ans,0,h.size()-1);
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int tx,ty;
	cin>>tx>>ty;
	int n;
	cin>>n;
	map<pair<int,int> , std::vector<pair<long long int,int> > > mp;
	for (int i=0;i<n;i++)
	{
		int x,y,h;
		cin>>x>>y>>h;
		long long int dx = x-tx;
		long long int dy = y-ty;
		int G = abs(__gcd(dx,dy));
		pair<long long int,int> p2((dx*dx+dy*dy),h);
		dx /=G;
		dy /=G;
		pair<int,int> p(dx,dy);
		mp[p].push_back(p2);
	}	
	int ans = 0;
	for (auto node:mp)
	{
		std::vector<pair<long long int,int> > v = node.second;
		sort(v.begin(), v.end());
		// cout<<node.first.first<<" "<<node.first.second<<" "<< v.size()<<endl;
		if (v.size()==1)
		{
			ans++;
			continue;
		}
		// for (int i=0;i<v.size();i++)
		// {
		// 	cout<<v[i].first<<" "<<v[i].second<<endl;
		// }
		// cout<<endl;
		ans += solve(v);
	}
	cout<<ans;
}