//AC
#include "bits/stdc++.h"
using namespace std;

int n,m,q;
std::vector<std::vector<int> > adjlist;
std::vector<std::vector<pair<int,std::vector<int> > > > lca_parents;
std::vector<int> depth;
std::vector<std::vector<int> > people_at_node;

void dfs(int node=0,int parent = -1,int d=0)
{
	depth[node]=d;
	lca_parents[node][0].first=parent;
	lca_parents[node][0].second = people_at_node[node];
	// if (parent!=-1 && people_at_node[parent].size()<=10)
	// {
	// 	lca_parents[node][0].second = people_at_node[parent];		
	// }
	// else if (parent!=-1)
	// {
	// 	// take the smallest ten numbers only
	// 	for(int i=0;i<10;i++)
	// 	{
	// 		lca_parents[node][0].second.push_back(people_at_node[parent][i]);	
	// 	}
	// }
	for (auto ch:adjlist[node])
	{
		if (ch==parent)
			continue;
		dfs(ch,node,d+1);
	} 
}

void merge_vectors (const std::vector<int> & v1,const std::vector<int> & v2,std::vector<int> & v)
{
	int i=0;
	int in1=0,in2=0;
	for(;i<10 && (in1<v1.size() || in2<v2.size());i++)
	{
		if (in1==v1.size())
		{
			// take from in1
			v.push_back(v2[in2++]);
		}
		else if(in2==v2.size())
		{
			// take from v2
			v.push_back(v1[in1++]);
		}
		else
		{
			if (v1[in1]<=v2[in2])
			{
				v.push_back(v1[in1++]);		
			}
			else
			{
				v.push_back(v2[in2++]);
			}
		}
	}
}

void prepare()
{	
	adjlist = std::vector<std::vector<int> > (n);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	people_at_node = std::vector<std::vector<int> > (n);
	for (int i=1;i<=m;i++)
	{
		int pos;
		cin>>pos;
		pos--;
		if (people_at_node[pos].size()<10)
			people_at_node[pos].push_back(i);
	}
	for(int node = 0;node<n;node++)
	{
		sort (people_at_node[node].begin(), people_at_node[node].end());
	}
	lca_parents = std::vector<std::vector<pair<int,std::vector<int> > > > (n,std::vector<pair<int,std::vector<int>> > (18));
	depth = std::vector<int> (n);
	dfs();
	// TODO
	// prepare the lca_parents here
	for (int level = 1;level<18;level++)
	{
		for(int node=0;node<n;node++)
		{
			if (lca_parents[node][level-1].first == -1)
			{
				lca_parents[node][level].first=-1;	
				// leave the No.s list empty
			}
			else
			{
				lca_parents[node][level].first = lca_parents[lca_parents[node][level-1].first][level-1].first;
				// Merge lca_parents[node][level-1].second with 
				// 		 lca_parents[ lca_parents[node][level-1].first ][level-1].second
				// and put it in lca_parents [node][level].second

				if (lca_parents[node][level].first ==-1)
					continue;
				std::vector<int> & v1 = lca_parents[node][level-1].second;
				std::vector<int> & v2 = lca_parents[ lca_parents[node][level-1].first ][level-1].second;
				merge_vectors(v1,v2,lca_parents[node][level].second);
				
				// looks good

				// cout<<"From: "<<node<<" To: "<<lca_parents[node][level].first<<": "<<endl;
				// for (auto val:lca_parents[node][level].second)
				// {
				// 	cout<<val<<" ";
				// }
				// cout<<endl<<endl;
			}
		}
	}
}

std::vector<int> ans;
std::vector<int> temp;
void find_ans(int a,int b)
{
	if (a==b)
	{
		ans = lca_parents[a][0].second;
		return;	
		// do something
	}
	if (depth[a]<depth[b])
	{
		swap(a,b);
	}
	ans.clear();
	// make a go up
	for (int level = 17;level>=0 && depth[a]>depth[b];level--)
	{
		int p = lca_parents[a][level].first;
		if (p==-1)
			continue;
		if (depth[a]-(1<<level) <depth[b])
		{
			continue;
		}
		// make a go up and adjust ans
		merge_vectors(ans,lca_parents[a][level].second,temp);
		ans = temp;
		temp.clear();
		a = p;
	}
	// make both go up
	if (a==b)
	{
		merge_vectors(ans,lca_parents[a][0].second,temp);
		ans = temp;
		temp.clear();	
		return ;
	}
	// cout<<"Not done\n";
	// cout<<a<<" "<<b<<endl;
	for (int level = 17;level>=0;level--)
	{
		int par1 = lca_parents[a][level].first;
		int par2 = lca_parents[b][level].first;
		if (par1==par2 || par1==-1 || par2==-1)
			continue;
		merge_vectors(ans,lca_parents[b][level].second,temp);
		ans = temp;
		temp.clear();
		merge_vectors(ans,lca_parents[a][level].second,temp);
		ans = temp;
		temp.clear();
		a = par1;
		b = par2;
		// cout<<a<<" "<<b<<endl;
	}
	merge_vectors(ans,lca_parents[b][0].second,temp);
	ans = temp;
	temp.clear();
	merge_vectors(ans,lca_parents[a][0].second,temp);
	ans = temp;
	temp.clear();
	merge_vectors(ans,lca_parents[ lca_parents[a][0].first ][0].second,temp);
	ans = temp;
	temp.clear();
}


int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>m>>q;
	prepare();
	while(q--)
	{
		int a,b,s;
		cin>>a>>b>>s;
		a--;
		b--;
		find_ans(a,b);
		printf("%d ", min(int(ans.size()),s));
		for (int i=0;i<min(int(ans.size()),s);i++)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
}