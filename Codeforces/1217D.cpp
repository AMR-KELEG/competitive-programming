// AC
/*
Difficulty:
    Moderate difficulty - Easy implementation
Idea:
The question relies mainly on understanding the idea of back-edges.
A backedge is an edge that connects a node to another one that has actually started the dfs.
So, it's like node A starts dfsing, goes to B, B goes to C then C wants to go to A again.
This can be detected using the start(when did you enter the node on DFSing)and
exit (when did you leave the node on DFSing) times of visiting the node.
*/
#include <bits/stdc++.h>

using namespace std;

int start_time[5000];
int end_time[5000];
int t = 0;
bool vis[5000];
void dfs(int node, const vector<vector<int> > & adjlist){
    if(vis[node])
        return;
    vis[node]=true;
    start_time[node] = t++;
    for(auto next_node: adjlist[node])
        dfs(next_node, adjlist);
    end_time[node] = t++;
}

int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<vector<int> > adjlist(n);
    memset(vis, 0, sizeof vis);
    int u, v;
    vector< pair<int, int> > edges(m);
    for(int i=0; i< m; i++){
        cin >> u >> v;
        u--;
        v--;
        edges[i] = {u, v};
        adjlist[u].push_back(v);
    }
    for(int i=0; i< n; i++) dfs(i, adjlist);
    vector<int> colors(m, 1);
    bool needs_two_colors = false;
    for(int i=0; i< m; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        // Is this a backedge?       
        if (start_time[u] > start_time[v] && end_time[u] < end_time[v]){
            colors[i] = 2;
            needs_two_colors = true;
        }
    }
    if (needs_two_colors)
        cout<<2<<endl;
    else
        cout<<1<<endl;
    
    for(auto c: colors)
        cout<<c<<" ";
    return 0;
}
