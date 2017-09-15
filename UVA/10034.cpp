//AC
#include "bits/stdc++.h"
using namespace std;
#define x first
#define y second
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
    int n;
    cin>>n;
    std::vector<pair<long double,long double> > points(n);
    for(int i=0;i<n;i++)
    {
      cin>>points[i].x>>points[i].y;
    }
    priority_queue<pair<long double,int>,std::vector<pair<long double,int> >,greater<pair<long double,int> > >q;
    std::vector<bool> vis(n,0);
    vis[0]=1;
    for(int i=1;i<n;i++)
    {
      q.push({hypot(points[0].x-points[i].x,points[0].y-points[i].y),i});
    }
    long double totalLen=0;
    while(!q.empty())
    {
      int u=q.top().second;
      long double dis=q.top().first;
      q.pop();
      if(vis[u])
        continue;
      vis[u]=1;
      totalLen+=dis;
      for(int i=0;i<n;i++)
      {
        if(u==i || vis[i])
          continue;
        q.push({hypot(points[u].x-points[i].x,points[u].y-points[i].y),i});   
      }
    }
    cout<<fixed<<setprecision(2)<<totalLen<<endl;
    if(t)
      cout<<endl;
  } 
}