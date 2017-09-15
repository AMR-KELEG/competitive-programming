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
  getline(cin,s);//empty line
  
  while(t--)
  {
    map<string,int>dic;
    int id=0;  
    getline(cin,s);
    while(s!="*")
    {
      dic[s]=id++;
      getline(cin,s);
    }
    std::vector<std::vector<int> > adjlist(dic.size());
    for(auto s:dic)
    {
      string tmp=s.first;
      for(int i=0;i<tmp.size();i++)
      {
        for(char c='a';c<='z';c++)
        {
          tmp[i]=c;
          if(dic.find(tmp)!=dic.end())
          {
            adjlist[s.second].push_back(dic[tmp]);
          }
        }
        tmp[i]=s.first[i];
      }
    }

    while(getline(cin,s) && s.size()>0)
    {
      int in=s.find(" ");
      int source=dic[s.substr(0,in)];
      int destination=dic[s.substr(in+1)];
      int steps=0;
      int curnode=source;
      std::vector<bool> vis(dic.size(),0);
      vis[curnode]=1;
      queue<pair<int,int> >q;
      q.push({curnode,0});
      while(curnode!=destination)
      {
        curnode=q.front().first;
        steps=q.front().second;
        q.pop();
        if(curnode==destination)break;
        vis[curnode]=1;
        for(int i=0;i<adjlist[curnode].size();i++)
        {
          if(!vis[adjlist[curnode][i]])
          {
            vis[adjlist[curnode][i]]=1;
            q.push({adjlist[curnode][i],steps+1}); 
          }
        }

      }
      cout<<s.substr(0,in)<<" "<<s.substr(1+in)<<" "<<steps<<endl;
    }
    if(t)
      cout<<endl;

  } 
}