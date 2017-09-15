//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<pair<long long int,int>> curPath(1,{0,0});
std::vector<int> a;
std::vector<int> ans;
std::vector<int> inc;
std::vector<int> par;
std::vector<std::vector<pair<int,int>>> adjlist;
int n;

void build_ans()
{
	// queue<pair<int,int>>q;//node inc
	queue<int>q;
	std::vector<int> sizes(n+1);
	for(int i=1;i<=n;i++)
	{
		sizes[i]=adjlist[i].size();
		if(adjlist[i].size()==0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		sizes[par[node]]--;
		ans[node]+=inc[node];
		ans[par[node]]+=ans[node];
		if(sizes[par[node]]==0)
		{
			q.push(par[node]);
		}
	}
}

void dfs(int node=1,long long int dis=0)
{
	//lower_bound
	pair<long long int,int> v={dis-a[node],-1};
	vector<pair<long long int,int>>::iterator it
		=lower_bound(curPath.begin(), curPath.end(),v);
	if(it!=curPath.end() && node!=1)
	{
		int in=it-curPath.begin();
		in++;

		if(in<curPath.size())
		{
			inc[par[curPath[in].second]]--;
			inc[par[node]]++;
			// cout<<"PARENT "<<curPath[in].second<<" "<<node<<endl;
		}
	}
	// cout<<node<<" "<<dis<<endl;
	curPath.push_back({dis,node});
	long long int curDis;
	for(int i=0;i<adjlist[node].size();i++)
	{
		curDis=curPath[curPath.size()-1].first=dis+adjlist[node][i].second;
		dfs(adjlist[node][i].first,curDis);
	}
	curPath.pop_back();
}
int main()
{
	// std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	scanf("%d",&n);
	a=std::vector<int> (n+1);
	ans=std::vector<int> (n+1,0);
	inc=std::vector<int> (n+1,0);
	par=std::vector<int> (n+1,0);
	adjlist=vector<std::vector<pair<int,int>>> (n+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=2,w;i<=n;i++)
	{
		scanf("%d%d",&par[i],&w);
		adjlist[par[i]].push_back({i,w});
	}
	
	dfs();
	build_ans();
	for(int i=1;i<=n;i++)
		printf("%d ", ans[i]);
}