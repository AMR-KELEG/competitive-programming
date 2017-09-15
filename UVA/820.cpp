//AC
#include "bits/stdc++.h"
using namespace std;

struct edge{
int to, flow, rev;
};

vector<vector<edge> > adj;
#define MAX_NODES 200
#define infinity 1e9
bool vis[MAX_NODES];
int source, sink, node_count , edge_count;
void add_edge(int from,int to, int flow)
{
  edge e1={to,flow,(int)adj[to].size()};
  edge e2={from,0,(int)adj[from].size()};
  adj[from].push_back(e1);
  adj[to].push_back(e2);
}
int find_path(int cur, int flow)
{
  if(cur == sink)
  return flow;
  if(vis[cur] || !flow)
  return 0;
  vis[cur] = true;
  for(int i=0 ; i < adj[cur].size(); i++)
  {
  edge &e = adj[cur][i];
  int fl = find_path(e.to,min(flow,e.flow));
  if(fl){
  edge &r = adj[e.to][e.rev];
  e.flow -= fl;
  r.flow += fl;
  return fl;
  }
  }
  return 0;
}
int max_flow()
{
  memset(vis,0,sizeof(vis));
  int res = 0, fl;
  while((fl=find_path(source,infinity)))
  {
  res += fl;
  memset(vis,0,sizeof(vis));
  }
  return res;
}



int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  cin>>node_count;
  int t=0;
  while(node_count!=0)
  {
    cin>>source>>sink>>edge_count;
    adj=std::vector<vector<edge> > (node_count+1);
    int a,b,cap;
    for(int i=0;i<edge_count;i++)
    {
      cin>>a>>b>>cap;
      add_edge(a,b,cap);
      add_edge(b,a,cap);
    }


    /*
      Network 1
      The bandwidth is 25.

    */
    cout<<"Network "<<++t<<endl<<"The bandwidth is "<<max_flow()<<".\n\n";
    cin>>node_count;
  } 
}