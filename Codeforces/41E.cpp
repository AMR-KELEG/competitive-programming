//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int n;
  cin>>n;
  std::vector<std::vector<int> > adjmat(n+1,vector<int>(n+1,0));
  std::vector<pair<int,int> > edges;
  bool change=true;
  while(change)
  {
    change=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=i+1;j<=n;j++)
      {
        if(adjmat[i][j]==0)
        {
          int v;
          for(v=1;v<=n;v++)
          {
            if(v==i || v==j)
              continue;
            if(adjmat[i][v]==1 && adjmat[v][j]==1)
            {
              v=-1;
              break;
            }
          }
          //cout<<i<<" "<<j<<" "<<v<<endl;
          if(v!=-1)
          {
            adjmat[i][j]=1;
            adjmat[j][i]=1;
            change=true;
            edges.push_back(pair<int,int>(i,j));
            break;
          }
          else
          {
            adjmat[i][j]=-1;
            adjmat[j][i]=-1;
          }
        }
      }
    }
  }
  /*
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cout<<setw(4)<<adjmat[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  cout<<edges.size()<<endl;
  for(int i=0;i<edges.size();i++)
    printf("%d %d\n", edges[i].first,edges[i].second);


}