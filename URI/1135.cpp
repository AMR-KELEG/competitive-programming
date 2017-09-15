//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> ancestor;
std::vector<int> L;
std::vector<std::vector<int>> P;
int N;
void process3()
{
  for(int i=0;i<N;i++)
  {
    P[i][0]=ancestor[i];
  }
  for(int j=1;(1 << j) <N ;j++)
  {
    for(int i=0;i<N;i++)
      if(P[i][j-1]!=-1)
        P[i][j]=P[P[i][j-1]][j-1];
  }
}

int query(int p,int q)
{
  int tmp,logVal,i;
  if(L[p]<L[q])
    swap(p,q);
  for(logVal=1;(1<< logVal) <=L[p];logVal++);
  logVal--;
  for(i=logVal;i>=0;i--)
  {
    if( (L[p]-(1<<i)) >=L[q])
    {
      p=P[p][i];
    }
  }
  if(p==q)
    return p;
  for(i=logVal;i>=0;i--)
    if(P[p][i]!=-1 && P[p][i]!=P[q][i])
      p=P[p][i],q=P[q][i];
  return ancestor[p]; 
}

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  cin>>N;
  while(N)
  {
    ancestor=std::vector<int> (N,0);
    L=std::vector<int> (N,0);
    
    P=std::vector<std::vector<int> > (N,std::vector<int>(1+ceil(log2(N)),-1));
    std::vector<vector<pair<int,long long int>> > adjList(N);
    std::vector<long long int> dis(N);
    int a,l;
    for(int i=0;i<N-1;i++)
    {
      //i+1 is the node
      //a is ancestor
      //l is length
      cin>>a>>l;
      ancestor[i+1]=a;
      adjList[a].push_back({i+1,l});
    }
    process3();
    queue<pair<int,pair<long long int,int>>>q;//node d
    
    //Level is 0 or 1?
    q.push({0,{0,1}});
    while(!q.empty())
    {
      int node=q.front().first;
      long long int d=q.front().second.first;
      int l=q.front().second.second;
      q.pop();
      dis[node]=d;
      L[node]=l;
      for(int i=0;i<adjList[node].size();i++)
      {
        q.push({adjList[node][i].first,{d+adjList[node][i].second,l+1}});
      }
    }
    int Q;
    cin>>Q;
    int fr,se;
    while(Q--)
    {
      cin>>fr>>se;
      int lca=query(fr,se);
      long long int ans=dis[fr]+dis[se];
      ans-=dis[lca];
      ans-=dis[lca];
      cout<<ans;
      if(Q)
        cout<<" ";
    }
    cin>>N;
    cout<<endl;
  } 
}