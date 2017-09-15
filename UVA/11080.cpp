//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int t;
  cin>>t;
  int n,m,u,v,c;
  std::vector<std::vector<int> > adjlist;
  while(t--)
  {
    cin>>n>>m;
    adjlist=vector<std::vector<int> >(n);
    for(int i=0;i<m;i++)
    {
      cin>>u>>v;
      adjlist[u].push_back(v);
      adjlist[v].push_back(u);
    }
    std::vector<bool> vis(n,false);
    std::vector<int> col(n,-1);
    long long int g=0;
    for(int st=0;st<n;st++)
    {
      if(!vis[st])
      {
        queue<pair<int,int> >q;
        q.push(pair<int,int>(st,0));
        while(!q.empty())
        {
          pair<int,int> p=q.front();
          u=p.first;
          c=p.second;
          q.pop();
          vis[u]=1;
          if(col[u]==-1 ||col[u]==c)
          {
            col[u]=c;
          }
          else
          {
            g=-1;
            while(!q.empty())
              q.pop();
            //impossible
          }
          for(int i=0;i<adjlist[u].size();i++)
          {
            if(!vis[adjlist[u][i]])
              q.push(pair<int,int>(adjlist[u][i],!c));
            else if(col[adjlist[u][i]]!=(!c))
            {
              //im
              g=-1;
              while(!q.empty())
                q.pop();
            }
          }
        }
      }
      else
        continue;
      if(g==-1)
        break;

      int count0=0;
      queue<int>q;
      std::vector<bool> done(n,0);
      q.push(st);
      int len=0;
      while(!q.empty())
      {
        len++;
        u=q.front();
        q.pop();
        done[u]=1;
        for(int i=0;i<adjlist[u].size();i++)
        {
          if(!done[adjlist[u][i]])
          {
            done[adjlist[u][i]]=1;
            q.push(adjlist[u][i]); 
          }
        }
        if(col[u]==0)
          count0++;
      }

      if(len-count0<count0 && count0!=len)
        count0=len-count0;
      g+=count0;

    }
      cout<<g<<endl;
    

  }

}