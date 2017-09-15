#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<int> > adjlist;
std::vector<pair<int,int> > edges;
std::vector<int> treeSize;
std::vector<int> chainHead; // Find the head of the chain
std::vector<int> chainSize;
std::vector<int> chainNo; // Find the the chain of the node
std::vector<int> chainIndex; // Find the index of the node in the chain
std::vector<std::vector<bool> > chainHasWhiteEdge;
void dfs(int node=0,int p=-1)
{
	treeSize[node]=1;
	for(int i=0;i<adjlist[node].size();i++)
	{
		int child=adjlist[node][i];
		if(child==p)
			continue;
		dfs(child,node);
		treeSize[node]+=treeSize[child];
	}
}
void build(int node=0,int chain_no=0,int par=-1)
{
	// cout<<node<<endl;
	if(chain_no==(int)chainHead.size())
	{
		chainHead.push_back(node);
		chainSize.push_back(1);
		chainNo[node]=chain_no;
		chainIndex[node]=0;
	}
	else
	{
		chainNo[node]=chain_no;
		chainIndex[node]=chainSize[chain_no];	
		chainSize[chain_no]++;
	}
	int max_child=-1;
	for(int i=0;i<adjlist[node].size();i++)
	{
		int child=adjlist[node][i];
		if(child==par)
			continue;
		// cout<<node<<" "<<child<<" "<<par<<endl;
		if(max_child==-1 || treeSize[child]>treeSize[max_child])
			max_child=child;
	}
	// cout<<"Node "<<node<<" Max child "<<max_child<<endl;
	if(max_child!=-1)
	{
		build(max_child,chain_no,node);
		for(int i=0;i<adjlist[node].size();i++)
		{
			int child=adjlist[node][i];
			if(child==par || child==max_child)
				continue;
			build(child,(int)chainHead.size(),node);
		}
	}
}

void prepare()
{
	dfs();
	build();
	int no_of_chains=chainSize.size();
	chainHasWhiteEdge=std::vector<std::vector<bool> > (no_of_chains);
	for(int i=0;i<no_of_chains;i++)
	{
		int chain_size=chainSize[i];
		chainHasWhiteEdge[i]=std::vector<bool> (4*chain_size,0);
	}
}

// what are rl and rr
// what are l and r
bool white_edge_in_chain(int chain_no,int rl,int rr,int l,int r,int node=1)
{
	if(r< rl || l>rr)return 0;
	if(l>=rl && r<=rr)
	{
		return chainHasWhiteEdge[chain_no][node];
	}
	int mid=(l+r)>>1;
	return white_edge_in_chain(chain_no,rl,rr,l,mid,2*node) ||
		   white_edge_in_chain(chain_no,rl,rr,1+mid,r,2*node+1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	adjlist=std::vector<std::vector<int> > (n);
	treeSize=std::vector<int> (n);
	chainNo=std::vector<int> (n);
	chainIndex=std::vector<int> (n);
	for(int e=0,u,v;e<n-1;e++)
	{
		cin>>u>>v;
		edges.push_back({u,v});
		u--;v--;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	prepare();
	for(int i=0;i<n;i++)
	{
		printf("Node: %d of tree size %d in chain %d and its indx is %d\n",
			i,treeSize[i],chainNo[i],chainIndex[i] );
	}
	int q;
	cin>>q;
	while(q--)
	{
		;
	}
}