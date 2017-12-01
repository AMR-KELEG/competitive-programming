// AC
#include "bits/stdc++.h"
using namespace std;

// des - indx
std::vector<std::vector<pair<int,int> > > adjlist;	
std::vector<int> edge_l;
std::vector<long long int> left_subtree;

int dfs(int node=1,int p=-1)
{
	int ans = 1;
	for (int i=0;i<adjlist[node].size();i++)
	{
		int ch = adjlist[node][i].first;
		int edge_indx = adjlist[node][i].second;
		if (ch==p)
			continue;
		int cur_ans = dfs(ch,node);
		left_subtree[edge_indx] = cur_ans;
		ans += cur_ans;
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	adjlist = std::vector<std::vector<pair<int,int> > > (n+1);
	edge_l = std::vector<int> (n,0);
	left_subtree = std::vector<long long int> (n,0);
	for (int i=1,a,b;i<=n-1;i++)
	{
		cin>>a>>b>>edge_l[i];
		adjlist[a].push_back({b,i});
		adjlist[b].push_back({a,i});
	}
	dfs();
	long long int cur_cost = 0;
	for (int i=1;i<n;i++)
	{
		cur_cost += edge_l[i] * left_subtree[i] * (n- left_subtree[i]);
	}
	long double mul = 6;
	mul/=n;
	mul/=n-1;
	int q;
	cin>>q;
	while(q--)
	{
		int idx,cur_l;
		cin>>idx>>cur_l;
		cur_cost -= (edge_l[idx]-cur_l) * left_subtree[idx] * (n- left_subtree[idx]);
		edge_l[idx] = cur_l;
		printf("%0.9LF\n", cur_cost*mul);
	}
}