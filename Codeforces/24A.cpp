//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
 //n
  int n;
  cin>>n;
  // make adjlist and adjmat
  std::vector<vector<int> > adjmat(n+2,std::vector<int> (n+2,-1));
  std::vector<std::vector<int> > adjlist(n+2);
  int a,b,c;
  for(int i=0;i<n;i++)
  {
    cin>>a>>b>>c;
    adjmat[a][b]=0;
    adjmat[b][a]=c;
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
  } 
  std::vector<bool> vis(n+2,0);
  int cost1=0;
  queue<int>q;
  q.push(1);
  while(!q.empty())
  {
    a=q.front();
    q.pop();
    vis[a]=1;
    for(int i=0;i<adjlist[a].size();i++)
    {
      if(!vis[adjlist[a][i]])
      {
        q.push(adjlist[a][i]);
        cost1+=adjmat[a][adjlist[a][i]];
        break;
      }
    }
  }
  cost1+=adjmat[a][1];
  vis=std::vector<bool>(n+2,0);
  int cost2=0;
  cost2+=adjmat[1][adjlist[1][1]];
  vis[1]=1;
  q.push(adjlist[1][1]);
  while(!q.empty())
  {
    a=q.front();
    q.pop();
    vis[a]=1;
    for(int i=0;i<adjlist[a].size();i++)
    {
      if(!vis[adjlist[a][i]])
      {
        q.push(adjlist[a][i]);
        cost2+=adjmat[a][adjlist[a][i]];
        break;
      }
    }
  }
  cost2+=adjmat[a][1];
  // cout<<cost1<<" "<<cost2<<endl;
  cout<<min(cost2,cost1);
}