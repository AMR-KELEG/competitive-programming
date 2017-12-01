//AC
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int n,m;
    cin>>n>>m;
    vector<int> degree(n+1,0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        degree[u]++;
        degree[v]++;
    }
    long long int ans = n*(n-1)*(n-2);
    ans /= 6;
    long long int wasted =0;
    for(int i=1;i<=n;i++)
    {
        long long int d = degree[i];
        wasted += (d)*(n-1-d);
    }
    cout<<ans-(wasted/2);
}