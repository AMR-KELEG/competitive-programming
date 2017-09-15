#include "bits/stdc++.h"
using namespace std;
typedef pair<long long int,pair<long long int,bool> > qt;
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int n,m,k;
  cin>>n>>m>>k;
  std::vector<long long int> dis(n+5,LLONG_MAX);
  std::vector<std::vector<pair<long long int,long long int> > > adjlist(n+5);
  int u,v,w;
  for(int i=0;i<m;i++)
  {
    cin>>u>>v>>w;
    adjlist[u].push_back(pair<long long int,long long int>(v,w));
    adjlist[v].push_back(pair<long long int,long long int>(u,w)); 
  }
  std::vector<bool> vis(n+5,0);
  priority_queue<qt, std::vector<qt> ,greater<qt> >q; //dis,node
  q.push(pair<long long int,pair<long long int,bool> >(0,pair<long long int,bool> (1,0)));
  long long int d,node;
 
  long long int s,y;
  for(int i=0;i<k;i++)
  {
    cin>>s>>y;
    q.push(pair<long long int,pair<long long int,bool> >(y,pair<long long int,bool> (s,1)) );
  }
  int count=0;
  while(!q.empty())
  {
    d=q.top().first;
    node=q.top().second.first;
    if(vis[node])
    {
      q.pop();  
      continue;
    }
    if(q.top().second.second)
      count++;
    //cout<<node<<" "<<d<<endl;
    q.pop();
    vis[node]=1;
    dis[node]=d;
    //for(map<int,int>::iterator it=adjlist[node].begin();it!=adjlist[node].end();++it)
    for(int i=0;i<adjlist[node].size();i++)
    {
      if(!vis[adjlist[node][i].first])
      {
        //cout<<"DIS "<<adjlist[node][i].second<<endl;
        q.push(pair<long long int,pair<long long int,bool> >( d+adjlist[node][i].second, pair<long long int,bool> ( adjlist[node][i].first,0)));
        
      }
    }
  }
  cout<<k-count;
}   