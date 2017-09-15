//AC
#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
const int MXSIZE = 101;
 
 
int parent [MXSIZE];
int child  [MXSIZE];
int low    [MXSIZE];
int tym    [MXSIZE];
bool seen  [MXSIZE];
bool is_cut[MXSIZE];
int c=0;
 
vector <vector <int> > adj (MXSIZE); //adjancy graph
 
void dfs(int s)
{
 
 /* static variable gets declared only 
    once till the program runs */
 
  seen[s]=true;   // mark s as visited
 
  low[s]=tym[s]=c++; // first assigns and then increment c.
 
 // checking all children of s
  for(int i=0;i<adj[s].size();i++)
  {
    int curr = adj[s][i];

    if(curr==parent[s])
      continue;         // do nothing if curr is its parent

    if(!seen[curr])
    {

      child[s]++; // one more independent child of s
      parent[curr]=s; 
      dfs(curr);


      /* the low time of the oldest ancestor
        reachable from both */
      low[s] = min(low[s] , low[curr]); 


     /* if curr has greater or equal 
        low time than visited time of s then if we cut s then
        curr will get disconnected from the graph*/
      if(low[curr] >= tym[s])
        is_cut[s]=true;

    }
    else
    {
      /* here instead of low[curr] I used
         tym[curr] , I have explained it below*/
      low[s]= min(low[s],tym[curr]);
    }
 
 
  }
 
}
 
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);  
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif

  string s;
  int n;
  getline(cin,s);  // no. of vertices and edges
  while(s[0]!='0')
  {
    n=atoi(s.c_str());
    // cout<<n<<endl;
    getline(cin,s);
    for(int i=0;i<MXSIZE;i++)
      adj[i].clear();
    memset(seen,0,sizeof seen);
    memset(parent,0,sizeof parent);
    memset(child,0,sizeof child);
    memset(is_cut,0,sizeof is_cut);

    c=0;
    while(s[0]!='0')
    {
      stringstream ss(s);
      int node;
      ss>>node;
      int othernode;
      while(ss>>othernode)
      {
        // cout<<node<<" "<<othernode<<endl;
        adj[node].push_back(othernode);
        adj[othernode].push_back(node);
      }
      getline(cin,s);
    }

    parent[1]=-1;
    for(int i=1;i<=n;i++)
    {
      if(!seen[i])
      {
        dfs(i);
        is_cut[i]= child[i]>1 ? true : false; 
      }  
    }

    
    int ans=0;
    for(int i=1;i<=n;i++)
    {
      if(is_cut[i])
      {
        ans++;
      }
    }
    cout<<ans<<endl;
    getline(cin,s);
  }


   





  return 0;
}