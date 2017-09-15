//AC
#include "bits/stdc++.h"
#define node pair<int,pair<int,int> > // value left right
#define VAL first
#define Lch second.first
#define Rch second.second
using namespace std;

int n,N;
std::vector<bool> vis;
std::vector<int> low,high;
std::vector<node> tree;

void dfs(int indx=1,int par_val=-1,int val =0,int lev =0)
{
	if(tree[indx].Rch == -1)
	{
		int cur_node_val = tree[indx].VAL;
		if(!vis[cur_node_val])
		{
			vis[cur_node_val] = 1;
			high[cur_node_val] = val+1;
			low[cur_node_val] = pow(2,n);
		}
		return;
	}
	int cur_node_val = tree[indx].VAL;
	if(!vis[cur_node_val])
	{
		vis[cur_node_val] = 1;
		high[cur_node_val] = val+1;
		low[cur_node_val] = pow(2,n) - pow(2,n-lev) +1;
	}

	if(par_val != tree[indx].VAL)
		val ++;
	dfs(2*indx,tree[indx].VAL,val,lev+1);
	dfs(2*indx+1,tree[indx].VAL,val,lev+1);
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
		N = ceil(pow(2,n+1))-1;
		tree = std::vector<node> (ceil(pow(2,n+1)));
		low = std::vector<int> (pow(2,n)+1);
		high = std::vector<int> (pow(2,n)+1);
		vis = std::vector<bool> (pow(2,n)+1,0);
		stack<int> winners;
		for(int i=1;i<ceil(pow(2,n));i++)
		{
			int w;
			cin>>w;
			winners.push(w);
		}
		queue<int> q;
		for(int i=1;i<=N;i++)
		{
			q.push(i);
		}
		int val =pow(2,n);
		while(!q.empty())
		{
			int indx = q.front();
			q.pop();
			if (2*indx+1>N)
			{
				tree[indx] = {val--,{-1,-1}};
			}
			else
			{
				tree[indx] = {winners.top(),{2*indx,1+2*indx}};
				winners.pop();
			}
		}
		dfs();

		int m;
		cin>>m;
		while(m--)
		{
			int p;
			cin>>p;
			printf("Player %d can be ranked as high as %d or as low as %d.\n", p,high[p],low[p]);
		}
		cin>>n;
		if (n)
		{
			printf("\n");
		}
	}	
}