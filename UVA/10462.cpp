//AC
#include "bits/stdc++.h"
using namespace std;
vector<bool>edgeTaken;
vector<pair<int,pair<int,int> > >edges;
int forbiddenEdge=-1;
int n,m;
int minVal,secVal=1000000000;
vector<int>par;
int find(int node)
{
  if(node==par[node])
    return node;
  return par[node]=find(par[node]);
}

void join(int a,int b)
{
  int pa=find(a);
  int pb=find(b);
  if(pa<=pb)
    par[pb]=pa;
  else
    par[pa]=pb;
}

int findMST()
{
  par=vector<int>(n);
  for(int i=0;i<n;i++)par[i]=i;
  int takenEdges=0;
  int totalW=0;
  for(int i=0;i<m && takenEdges<n-1;i++)
  {
    int curW=edges[i].first;
    int a=edges[i].second.first;
    int b=edges[i].second.second;
    if(find(a)==find(b) || i==forbiddenEdge)
      continue;
    totalW+=curW;
    takenEdges++;
    edgeTaken[i]=1;
    join(a,b);
  } 
  if(takenEdges<n-1)
    return -1;
  return totalW; 
}

int findsecVal()
{
  int takenEdges=n-2;
  int w=0;
  for(int i=0;i<n;i++)par[i]=i;
  for(int i=0;i<m;i++)
  {
    if(i==forbiddenEdge)
      continue;
    if(edgeTaken[i])
    {
      w+=edges[i].first;
      join(edges[i].second.first,edges[i].second.second);
    }
  }

  for(int i=0;i<m;i++)
  {
    if(edgeTaken[i] || forbiddenEdge==i)
    {
      continue;
    }
    int a=edges[i].second.first,b=edges[i].second.second;
    if(find(a)!=find(b))
    {
      if(w+edges[i].first>=minVal)
      {
        takenEdges++;
        secVal=min(secVal,w+edges[i].first);
        break;
      }
    }
  }
  if(takenEdges<n-1)
    return 1000000000;
  return secVal;
}

int main()
{
  freopen("in.txt","r",stdin);
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;i++)
  {
    scanf("%d",&n);
    scanf("%d",&m);
    edges=vector<pair<int,pair<int,int> > >(m);
    edgeTaken=std::vector<bool> (m,0);
    int a,b,c;
    for(int i=0;i<m;i++)
    {
      scanf("%d %d %d",&a,&b,&c);
      a--;
      b--;
      edges[i]={c,{a,b}};
    }
    sort(edges.begin(),edges.end());
    minVal=findMST();
    if(minVal==-1)
      printf("Case #%d : No way\n", i);
    else
    {
      secVal=1000000000;
      for(int i=0;i<m;i++)
      {
        if(edgeTaken[i])
        {
          forbiddenEdge=i;
          findsecVal();
          forbiddenEdge=-1;
        }
      }
      if(secVal==1000000000)
      {
        printf("Case #%d : No second way\n", i);
      }
      else
      {
        printf("Case #%d : %d\n", i,secVal);
      }

    }

  }

} 
