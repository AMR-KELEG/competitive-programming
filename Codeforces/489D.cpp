#include "bits/stdc++.h"
using namespace std;
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int n,m;
  cin>>n>>m;
  std::vector<std::vector<int> > adjlist(n+2);
  int a,b;
  for(int i=0;i<m;i++)
  {
    cin>>a>>b;
    adjlist[a].push_back(b);
  }
  // cout<<n<<" "<<m<<endl;
  std::vector<int> count;
  long long int ans=0;
  queue<pair<int,int> >q;// node - level
  int u,l;
  for(int i=1;i<=n;i++)
  {
    count=std::vector<int> (n+2,0);
    q.push(pair<int,int>(i,0));
    while(!q.empty())
    {
      u=q.front().first;
      l=q.front().second;
      // cout<<u<<" "<<l<<endl;
      q.pop();
      if(l==0)
      {
        for(int no=0;no<adjlist[u].size();no++)
          q.push(pair<int,int>(adjlist[u][no],l+1));
      }
      else if(l==1)
      {
        for(int no=0;no<adjlist[u].size();no++)
          count[adjlist[u][no]]++;
          // q.push(pair<int,int>(,l+1)); 
      }
      else if(l==2)
      {
        count[u]++;
      }
    }
    for(int j=1;j<=n;j++)
    {
      if(i==j)
        continue;
      // cout<<j<<" "<<count[j]<<endl;
      ans+=(count[j]*max(0,count[j]-1))*0.5;
    }
  }
  cout<<ans;
}