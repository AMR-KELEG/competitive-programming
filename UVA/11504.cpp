#include "bits/stdc++.h"
using namespace std;
int n,m; 
std::vector<std::vector<int> > adjList;
std::vector<bool> vis;
int dfsIndex=0;
std::vector<int> ParOfDfs;
std::vector<int> NodeIn;

int find(int i)
{
  if(i==ParOfDfs[i])
    return i;
  return ParOfDfs[i]=find(ParOfDfs[i]);
}

void join(int a,int b)
{
  if(find(a)==find(b))return ;
  int pa=find(a);
  int pb=find(b);
  if(pa<pb)
  {
    ParOfDfs[pb]=pa;
  }
  else
  {
    ParOfDfs[pa]=pb; 
  }
}

void dfs(int node)
{
  NodeIn[node]=dfsIndex;
  vis[node]=1;
  for(int i=0;i<adjList[node].size();i++)
  {
    if(!vis[adjList[node][i]])
    {
      dfs(adjList[node][i]);
    }
    else
    {
      join(dfsIndex,NodeIn[adjList[node][i]]);
    }
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    adjList=std::vector<std::vector<int> > (n+1);
    vis=std::vector<bool> (n+1,0);
    NodeIn=std::vector<int> (n+1);
    int u,v;
    while(m--)
    {
      cin>>u>>v;
      adjList[u].push_back(v);
    }

    for(int i=1;i<=n;i++)
    {
      if(!vis[i])
      {
        ParOfDfs.push_back(dfsIndex);
        dfs(i);
        dfsIndex++;
      }
    }
    set<int>Dis;
    for(int i=0;i<ParOfDfs.size();i++)
    {
      find(ParOfDfs[i]);
    }

    for(int i=0;i<ParOfDfs.size();i++)
    {
      Dis.insert(ParOfDfs[i]);
    }
    cout<<Dis.size()<<endl;
    
  }

}