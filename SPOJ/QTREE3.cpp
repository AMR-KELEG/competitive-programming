#include "bits/stdc++.h"
using namespace std;
#define MAX 100001
#define INF 1000000009
/*
Done:
1)DFS
2)HLD
3)Build_Tree
4)Update_Tree
5)Query
--------------------------------------------------
In the first line there are two integers N and Q.
In the next N-1 lines describe the edges in the tree: 
a line with two integers a b denotes an edge between a and b.
The next Q lines contain instructions "0 i" or "1 v" (1 ≤ i, v ≤ N).
For 1/3 of the test cases, N=10^5, Q=10^5.

Output
For each "1 v" operation, write one integer representing its result.
*/

int treeSize[MAX];
int parent[MAX];
int level[MAX];
std::vector<std::vector<int> >adjList (MAX);
int dfs(int node,int p,int l=0)
{
  treeSize[node]=1;
  level[node]=l;
  for(int i=0;i<adjList[node].size();i++)
  {
    if(adjList[node][i]==p)
      continue;
    parent[adjList[node][i]]=node;
    treeSize[node]+=dfs(adjList[node][i],node,l+1);
  }
  return treeSize[node];
}

std::vector<std::vector<int> > segmentTree;
void buildTree(int tSize)
{
  segmentTree.push_back(std::vector<int> (4*(tSize),INF));
}

int indxOfChain[MAX]={};
int indxInChain[MAX]={};
vector<int> chainHead;
vector<int> chainSize(1,0);
int curChain=0; //May not be required

void HLD(int node,int p,int chainIndx)
{
  if(chainSize[chainIndx]==0)
  {
    chainHead.push_back(node);
  }
  indxInChain[node]=chainSize[chainIndx];
  indxOfChain[node]=chainIndx;
  chainSize[chainIndx]++;
  if(adjList[node].size()==1)
  {
    //No more nodes - just parent
    //Build Tree
    buildTree(chainSize[chainIndx]);
    return ;
  }
  int indxOfHeavyNode=-1;
  for(int i=0;i<adjList[node].size();i++)
  {
    if(adjList[node][i]==p)
      continue;
    else if(indxOfHeavyNode==-1)
      indxOfHeavyNode=i;
    else if(treeSize[adjList[node][indxOfHeavyNode]]<treeSize[adjList[node][i]])
    {
      indxOfHeavyNode=i;
    }
  }
  //From heavy node -- continue HLD with same chain number
  HLD(adjList[node][indxOfHeavyNode],node,chainIndx);
  for(int i=0;i<adjList[node].size();i++)
  {
    if(adjList[node][i]==p || i==indxOfHeavyNode)
      continue;
    //Start new Tree 
    curChain++;
    chainSize.push_back(0);
    HLD(adjList[node][i],node,curChain);    
  }
}


void update(int node,int node_in,int l,int r,int treeIndx)
{
  int in=indxInChain[node_in];
  if(in==l && l==r)
  {
    if(segmentTree[treeIndx][node]==INF)
    {
      segmentTree[treeIndx][node]=node_in;
      // cout<<"Color "<<node_in<<endl;
    }
    else
    {
      segmentTree[treeIndx][node]=INF;
    }
    return ;
  }
  if(in<l || in>r)
    return ;
  int mid=(l+r)>>1;
  update(2*node,node_in,l,mid,treeIndx);
  update(2*node+1,node_in,1+mid,r,treeIndx);
  int ans1=segmentTree[treeIndx][2*node];
  int ans2=segmentTree[treeIndx][2*node+1];
  // cout<<l<<" "<<r<<" "<<"Answers: "<<ans1<<" "<<ans2<<endl;
  int l1,l2;
  if(ans1==INF)
    l1=INF;
  else
    l1=level[ans1];
  if(ans2==INF)
    l2=INF;
  else
    l2=level[ans2];

  if(l1<l2)
    segmentTree[treeIndx][node]=ans1;
  else
    segmentTree[treeIndx][node]=ans2;
  // cout<<treeIndx<<" "<<segmentTree[treeIndx][node]<<endl;
}

int query(int node,int rl,int rr,int l,int r,int treeIndx)
{
  // cout<<"Range: "<<rl<<" "<<rr<<" "<<l<<" "<<r<<" Ans: "<<segmentTree[treeIndx][node]<<endl;
  if(l>rr || r<rl)
    return INF;
  if(l>=rl && r<=rr)
    return segmentTree[treeIndx][node];
  // cout<<l<<" "<<r<<" "<<treeIndx<<" ANS: "<<segmentTree[treeIndx][node]<<endl; 
  int mid=(l+r)>>1;
  int ans1=query(2*node,rl,rr,l,mid,treeIndx);
  int ans2=query(2*node+1,rl,rr,1+mid,r,treeIndx);
  int l1,l2;
  if(ans1==INF)
    l1=INF;
  else
    l1=level[ans1];
  if(ans2==INF)
    l2=INF;
  else
    l2=level[ans2];
  
  if(l1<l2)
    return ans1;
  else
    return ans2;
}

int solve(int TOP,int BOT)
{
  int ans=INF;
  ans=min(ans,query(1,0,0,0,chainSize[TOP]-1,indxOfChain[TOP]));
  while(TOP!=BOT)
  {
    int cur_chain=indxOfChain[BOT];
    // cout<<"Bot: "<<BOT<<" Chain: "<<cur_chain<<" indxInChain: "<<indxInChain[BOT]<<endl;
    //check color of BOT
    int ans2=query(1,0,indxInChain[BOT],0,chainSize[cur_chain]-1,cur_chain);
    int l1,l2;
    if(ans==INF)
      l1=INF;
    else
      l1=level[ans];
    if(ans2==INF)
      l2=INF;
    else
      l2=level[ans2];
    if(l2<l1)
      ans=ans2;
    //if Bot is top of chain -> Go to parent
    if(BOT==chainHead[cur_chain])
    {
      BOT=parent[BOT];
    }
    //else -> Go to top of current chain
    else
    {
      // ans=min(ans,query(1,0,indxInChain[BOT],0,chainSize[BOT]-1,cur_chain));
      BOT=chainHead[cur_chain];      
    }
  }   
  return ans;
}

int main()
{
  // std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int n,q;
  // cin>>n>>q;
  scanf("%d %d",&n,&q);
  for(int e=0,f,s;e<n-1;e++)
  {
    scanf("%d %d",&f,&s);
    // cin>>f>>s;
    f--;s--;
    adjList[f].push_back(s);
    adjList[s].push_back(f);
  }
  dfs(0,-1);
  HLD(0,-1,0);
  int u,v;
  while(q--)
  {
    // cin>>u>>v;
    scanf("%d %d",&u,&v);
    if(u==0)
    {
      //Update
      v--;
      int cur_chain=indxOfChain[v];
      update(1,v,0,chainSize[cur_chain]-1,cur_chain);
    }
    else
    {
      u--;v--;
      //Query
      int ans=solve(u,v);
      if(ans==INF)
        printf("-1\n");
      else
        printf("%d\n",ans+1);
    }
  }
}