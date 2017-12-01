#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<int> > adjlist;
std::vector<std::vector<int> > parent;
std::vector<int> in_time;
std::vector<int> out_time;
std::vector<int> val;
std::vector<int> euler_tree;
std::vector<int> level;
map<int,int> val_to_indx;

#define Range pair<pair<int,int>, int>	
#define RanL first.first
#define RanR first.second
int t = 0;
int bucket_size;
bool range_cmp(const Range & ran1,const Range & ran2)
{
	int b1 = ran1.RanL/bucket_size;
	int b2 = ran2.RanL/bucket_size;
	if (b1<b2)
		return 1;
	if (b1==b2)
		return ran1.RanR>ran2.RanR;
	return 0;
}

void dfs(int node=1,int par=-1,int l=0)
{
	parent[node][0] = par;
	level[node] = l;
	in_time[node] = t;
	euler_tree.push_back(node);
	for (auto ch:adjlist[node])
	{
		if (ch == par)
			continue;
		t++;
		dfs(ch,node,l+1);
	}
	out_time[node] = ++t;
	euler_tree.push_back(node);
}

int LCA(int a,int b)
{
	if (a==b)
		return a;
	if (level[b]>level[a])
		swap(a,b);
	// lift a until they have the same level
	for (int lev = 18;lev>=0;lev--)
	{
		if (level[a]- (1<<lev) >=level[b])
		{
			a = parent[a][lev];
		}
	}
	if (a==b)
		return a;
	for (int lev = 18;lev>=0;lev--)
	{
		if (parent[a][lev]!=-1 && parent[a][lev]!=parent[b][lev])
		{
			a = parent[a][lev];
			b = parent[b][lev];
		}
	}
	return parent[a][0];
}

void prepare(int n)
{
	bucket_size = sqrt(n);
	level = std::vector<int> (n+1);
	parent = std::vector<std::vector<int> > (n+1,std::vector<int> (19));
	in_time = std::vector<int> (n+1);
	out_time = std::vector<int> (n+1);
	dfs();
	for (int l=1;l<19;l++)
	{
		for (int node = 1;node<=n;node++)
		{
			if (parent[node][l-1]==-1)
				continue;
			parent[node][l] = parent[parent[node][l-1]][l-1];
		}
	}
}

void farthest_insert(int indx, set<int>& s)
{
	int cur_val = val[euler_tree[indx]]; 
	if (s.find(cur_val)==s.end())
		s.insert(cur_val);
	else
		s.erase(cur_val);
}

void closest_insert(int indx, 
	priority_queue<pair<int,pair<int,int>> > & in_closest,
	std::vector<bool> & is_in,
	set<int> & s)
{
	int node = euler_tree[indx];
	int cur_val = val[node];
	is_in[node] = !is_in[node];
	if (is_in[node])
	{
		auto it1 = s.upper_bound(cur_val);
		if (it1!=s.end())
		{
			auto val1 = *(it1);
			if (val1 !=cur_val)
			{
				in_closest.push({-abs(val1- cur_val),{node,val_to_indx[val1]}});
			}
		}
		auto it2 = s.lower_bound(cur_val);
		if (it2!=s.begin())
		{
			it2--;
			int val2 = *it2;
			if (val2!=cur_val)
			{
				in_closest.push({-abs(val2- cur_val),{node,val_to_indx[val2]}});
			}
		}
	}

	farthest_insert(indx, s);
	// cout<<"Indx "<<indx<< " -> Node "<<node<<endl;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);	
	adjlist = std::vector<std::vector<int> > (n+1);
	val = std::vector<int> (n+1);
	for (int i=1;i<=n;i++)
	{
		cin>>val[i];
		val_to_indx[val[i]] = i;
	}
	for (int i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	// prepare
	prepare(n);

	int q;
	scanf("%d ",&q);
	std::vector<int> query_ans(q,0);
	std::vector<Range> closest_ranges;
	std::vector<Range> farthest_ranges;
	for (int i=0;i<q;i++)
	{
		char ty;
		int u,v;
		scanf("%c",&ty);
		scanf("%d %d ",&u, &v);
		if (level[u]>level[v])
			swap(u,v);
		int lca = LCA(u,v);
		if (ty=='C')
		{
			query_ans[i] = 2000000000;
			if (lca==u)
			{
				closest_ranges.push_back({{in_time[u],in_time[v]},i});
			}
			else
			{
				closest_ranges.push_back({{in_time[lca],in_time[u]},i});
				closest_ranges.push_back({{in_time[lca],in_time[v]},i});
			}
		}
		else
		{
			query_ans[i] = 0;
			if (lca==u)
			{
				farthest_ranges.push_back({{in_time[u],in_time[v]},i});
			}
			else
			{
				farthest_ranges.push_back({{in_time[lca],in_time[u]},i});
				farthest_ranges.push_back({{in_time[lca],in_time[v]},i});
			}
		}
	}
	sort(closest_ranges.begin(), closest_ranges.end(), range_cmp);
	sort(farthest_ranges.begin(), farthest_ranges.end(), range_cmp);
	set<int> in_values;
	int mo_l = 0,mo_r = -1;
	for (int i=0;i<farthest_ranges.size();i++)
	{
		int l = farthest_ranges[i].RanL;
		int r = farthest_ranges[i].RanR;
		int indx = farthest_ranges[i].second;
		while (mo_l<l)
		{
			// insert at mo_l
			farthest_insert(mo_l++,in_values);
		}
		while(mo_l>l)
		{
			farthest_insert(--mo_l,in_values);	
		}
		while (mo_r<r)
		{
			// farthest_insert at mo_r
			farthest_insert(++mo_r,in_values);
		}
		while(mo_r>r)
		{
			farthest_insert(mo_r--,in_values);	
		}

		query_ans[indx] = max(query_ans[indx],*(--in_values.end()) - *(in_values.begin()));
	}
	mo_l = 0,mo_r = -1;
	priority_queue<pair<int,pair<int,int>> >in_closest;
	std::vector<bool> is_in(n+1,0);
	in_values.clear();
	for (int i=0;i<closest_ranges.size();i++)
	{
		int l = closest_ranges[i].RanL;
		int r = closest_ranges[i].RanR;
		int indx = closest_ranges[i].second;
		while (mo_l<l)
		{
			// insert at mo_l
			closest_insert(mo_l++,in_closest,is_in,in_values);
		}
		while(mo_l>l)
		{
			closest_insert(--mo_l,in_closest,is_in,in_values);	
		}
		while (mo_r<r)
		{
			// closest_insert at mo_r
			closest_insert(++mo_r,in_closest,is_in,in_values);
		}
		while(mo_r>r)
		{
			closest_insert(mo_r--,in_closest,is_in,in_values);	
		}
		while(!in_closest.empty())
		{
			int u = in_closest.top().second.first;
			int v = in_closest.top().second.second;
			if (!is_in[u] || !is_in[v])
			{
				in_closest.pop();
			}
			else
			{
				break;
			}
		}
		if (!in_closest.empty())
			query_ans[indx] = min(query_ans[indx],
				-in_closest.top().first);
		// cout<<endl;
	}

	for (int i=0;i<q;i++)
	{
		printf("%d\n", query_ans[i]);
	}
}