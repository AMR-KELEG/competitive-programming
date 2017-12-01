//AC
#include <bits/stdc++.h>
using namespace std;
bool vis[51] = {};
vector<vector<int> >adjlist;
int dfs(int node)
{
    int ch=0;
    vis[node]=1;
    for(int i=0;i<adjlist[node].size();i++)
    {
        if(!vis[adjlist[node][i]])
        {
            ch+=dfs(adjlist[node][i]);
        }
    }
    return 1+ch;
}

int main()
{
    int n,m;
    cin>>n>>m;
    adjlist = vector<vector<int> >(n+1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    long long int ans=1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            ans*=round(pow(2,dfs(i)-1));
        }
    }
    cout<<ans;
}
