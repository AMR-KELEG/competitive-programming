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
  string s;
  getline(cin,s);
  getline(cin,s);
  char maxNode;
  while(t--) 
  {
    getline(cin,s);
    int n=s[0]-'A'+1;
    std::vector<std::vector<int> > adjlist(n);
    getline(cin,s);
    while(s.size()!=0)
    {
      int u=s[0]-'A';
      int v=s[1]-'A';
      if(u!=v)
      {
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
      }
      getline(cin,s);
    }

    std::vector<bool> vis(n,0);
    int com=0;
    for(int i=0;i<n;i++)
    {
      if(!vis[i])
      {
        //BFS
        com++;
        queue<int>q;
        q.push(i);
        while(!q.empty())
        {
          int u=q.front();
          q.pop();
          vis[u]=1;
          for(int in=0;in<adjlist[u].size();in++)
          {
            if(!vis[adjlist[u][in]])
            {
              q.push(adjlist[u][in]);
              vis[adjlist[u][in]]=1;
            }
          }
        }
      }
    }
    cout<<com<<endl;
    if(t)
      cout<<endl;
  }
}