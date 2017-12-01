//AC
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adjlist;
int D[100001],T[100001],S[100001];
int L[100001][17];
int t=0;
vector<vector<int>> nodes_at_depth;
int dfs(int node,int p=0,int depth=0)
{
    L[node][0]=p;
    D[node]=depth;
    T[node]=t++;
    nodes_at_depth[depth].push_back(T[node]);
    for(auto no : adjlist[node])
        S[node]+=dfs(no,node,depth+1);
    return S[node]+1;
}

int go_up(int node,int levels)
{
    if(levels==0)
        return node;
    for(int step=17;step>=0;step--)
    {
        if((1<<step)<=levels)
        {
            node=L[node][step];
            levels-=(1<<step);
            break;
        }
    }
    return go_up(node,levels);
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    adjlist = vector<vector<int>> (n+1);
    nodes_at_depth = vector<vector<int>> (n+1);
    vector<int>roots;
    for(int node=1;node<=n;node++)
    {
        int p;
        cin>>p;
        if(p==0)
        {
            roots.push_back(node);
            continue;
        }
        adjlist[p].push_back(node);
    }
    for(auto r : roots)
        dfs(r);
    for(int level=1;level<17;level++)
    {
        for(int node=1;node<=n;node++)
            L[node][level]=L[L[node][level-1]][level-1];
    }
    int m;
    cin>>m;
    while(m--)
    {
        int v,p;
        cin>>v>>p;
        if(p>D[v])
            printf("0 ");
        else
        {
            //Go up to anc
            int anc=go_up(v,p);
            //printf(" ANC %d ",anc);
            //Binary search in depth D[v]
            //for nodes in range
            // T[anc] -> T[anc]+S[anc]
            int v1=T[anc];
            int v2=T[anc]+S[anc];
            int ans =
            upper_bound(nodes_at_depth[D[v]].begin(),
                        nodes_at_depth[D[v]].end(),v2)
            -lower_bound(nodes_at_depth[D[v]].begin(),
                         nodes_at_depth[D[v]].end(),v1);
            printf("%d ",ans-1);
        }
    }
}
