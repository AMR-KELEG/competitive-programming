//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<pair<int,int> > > adjlist;
std::vector<int> freq;
std::vector<int> cum_freq;
std::vector<long long int> cost;

long long int find_cost(int node=0,int p =-1, long long int d =0)
{
	long long int ans =freq[node]*d;
	for(int i=0;i<adjlist[node].size();i++)
	{
		int ch = adjlist[node][i].first;
		int dis = adjlist[node][i].second;
		if(ch == p)
			continue;
		ans += find_cost(ch,node,d+dis);
	}
	return ans;
}

int find_cum_freq(int node=0, int par=-1)
{
	int ans =freq[node];
	for(auto ch:adjlist[node])
	{
		int c = ch.first;
		if(c==par)
			continue;
		ans += find_cum_freq(c,node);
	}
	return cum_freq[node] = ans;
}

void generate_cost(long long int total_cost, long long int last_edge_cost, int node =0, int par =-1)
{
	int par_freq = (par==-1)? 0 :cum_freq[0] - cum_freq[node]; 
	cost [node] = total_cost + (par_freq - cum_freq[node]) *last_edge_cost;
	for(auto ch_node:adjlist[node])
	{
		int c = ch_node.first;
		int d = ch_node.second;
		if(c==par)
			continue;
		generate_cost(cost[node], d, c, node);
	}
}

void prepare()
{
	find_cum_freq();
	cost [0] = find_cost();
	generate_cost(cost[0], 0);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	
	while(T--)
	{
		int n;
		cin>>n;
		// cout<<n<<endl;
		adjlist = std::vector<std::vector<pair<int,int> > > (n);
		freq = std::vector<int> (n,0);
		cum_freq = std::vector<int> (n,0);
		cost = std::vector<long long int> (n,0);
		for(int i=1;i<n;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			a--;
			b--;
			adjlist[a].push_back({b,c});
			adjlist[b].push_back({a,c});
		}
		int m;
		cin>>m;
		while(m--)
		{
			int node,f;
			cin>>node>>f;
			freq[node-1] = 2*f;
		}	
		// find cost from root
		prepare();
		long long int min_cost = cost[0];
		for(int i=1;i<n;i++)
			min_cost = min(min_cost, cost[i]);
		printf("%lld\n", min_cost);
		bool f =1;
		for (int i=0;i<n;i++)
		{
			if(min_cost == cost[i])
			{
				if(f)
				{
					printf("%d", i+1);
					f=0;
				}
				else 
				{
					printf(" %d", i+1);
				}
			}
		}
		printf("\n");
	}		
}