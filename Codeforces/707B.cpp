//AC
#include "bits/stdc++.h"
int MAX=1+(1e9);
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int n,m,k;
	cin>>n>>m>>k;
  std::vector<std::vector<pair<int,int> > > adjlist(n+1);
  std::vector<bool> isBaker(n+1,0);
  int u,v,l;
  int mindis=MAX;
  for(int i=0;i<m;i++)
  {
    cin>>u>>v>>l;
    adjlist[u].push_back({v,l});
    adjlist[v].push_back({u,l});
  }
  for(int i=0;i<k;i++)
  {
    cin>>u;
    isBaker[u]=1;
  }

  for(int i=1;i<=n;i++)
  {
    if(isBaker[i])
      continue;
    for(int j=0;j<adjlist[i].size();j++)
    {
      if(isBaker[adjlist[i][j].first])
      {
        mindis=min(mindis,adjlist[i][j].second);
      }
    }
  }

  if(mindis==MAX)
    cout<<-1;
  else
    cout<<mindis;

}